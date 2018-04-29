#include <sys/socket.h>
#include <netinet/in.h>
#include "g711.c"
#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include<sys/types.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <pthread.h> //pthread definition file
#include <pulse/simple.h>
#include <pulse/error.h>
static ssize_t loop_write(int fd, const void*data, size_t size) {
    ssize_t ret = 0;
    while (size > 0) {
        ssize_t r;
        if ((r = write(fd, data, size)) < 0)
            return r;
        if (r == 0)
            break;
        ret += r;
        data = (const uint8_t*) data + r;
        size -= (size_t) r;
    }
    return ret;
}
int connfd = 0;
ssize_t n=0;
uint8_t recvBuff[10240];
uint8_t buf2[10240];
void *Thread1Proc() //print address of the three local variables j, k and l
{
  // pa_simple *s = pa_simple_new(NULL, "./server", PA_STREAM_PLAYBACK, NULL, "playback", &ss, NULL, NULL, &error);
  pa_simple *s = NULL;
  int ret = 1;
  /* Create the recording stream */
  recvBuff[n] = 0;
  ssize_t r;
  uint8_t buf[10240];
  static const pa_sample_spec ss = {
    .format = PA_SAMPLE_S16LE,
    .rate = 44100,
    .channels = 1
  };
  // if (!(s = pa_simple_new(NULL, "VoIP1", PA_STREAM_PLAYBACK, NULL, "record", &ss, NULL, NULL, &error))) {
  //   fprintf(stderr, __FILE__": pa_simple_new() failed: %s\n", pa_strerror(error));
  //   // goto finish;
  // }
  while(1)
  {
    int error;

    printf("Message from client:");
  // int n = 0;
  if (!(s = pa_simple_new(NULL, "VoIP1", PA_STREAM_PLAYBACK, NULL, "record", &ss, NULL, NULL, &error))) {
    fprintf(stderr, __FILE__": pa_simple_new() failed: %s\n", pa_strerror(error));
    // goto finish;
  }
  // printf("read\n");
  // while((n = read(connfd, recvBuff, sizeof(recvBuff)-1)) > 0)
      /* Record some data ... */
                      if (pa_simple_read(s, buf, sizeof(buf), &error) < 0) {
                          fprintf(stderr, __FILE__": pa_simple_read() failed: %s\n", pa_strerror(error));
                          // goto finish;
                      }
                      /* And write it to STDOUT */
                      // if (loop_write(connfd, buf, sizeof(buf)) != sizeof(buf)) {
                          // fprintf(stderr, __FILE__": write() failed: %s\n", strerror(errno));
                          // goto finish;
                      // }
    //   if(fputs(recvBuff, stdout) == EOF)
    // {
    //   printf("\n Error : Fputs error");
    // }
      // printf("\n");
      // write(connfd, buf, sizeof(buf));

  //   ret =0;
  // if( n < 0)
  //   {
  //     printf("\n Read Error \n");
  //   }
    if (s != NULL) {
		pa_simple_free(s);
		s = NULL;
	}
  }
  // finish:
  //     if (s)
  //         pa_simple_free(s);
  //     // return ret;
}
char sendBuff[10240];
void *Thread2Proc() //print address of the three local variables j, k and l
{
  while(1)
  {
  fgets(sendBuff, sizeof sendBuff, stdin);
  // printf("wrote\n");
      // strcpy(sendBuff, "Message from server");
    write(connfd, sendBuff, strlen(sendBuff));
  }
}

int main(int argc, char *argv[])
{
  int listenfd = 0;

  struct sockaddr_in serv_addr;

  // char sendBuff[10240];
  int numrv;

  listenfd = socket(AF_INET, SOCK_STREAM, 0);
  printf("This is server. Start typing to chat with client\n");

  memset(&serv_addr, '0', sizeof(serv_addr));
  memset(recvBuff, '0', sizeof(recvBuff));
  memset(sendBuff, '0', sizeof(sendBuff));

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  serv_addr.sin_port = htons(5000);

  bind(listenfd, (struct sockaddr*)&serv_addr,sizeof(serv_addr));

  if(listen(listenfd, 10) == -1){
      printf("Failed to listen\n");
      return -1;
  }
  pthread_t th1, th2;
  connfd = accept(listenfd, (struct sockaddr*)NULL ,NULL); // accept awaiting request
  // while(1)
    {
      pthread_create(&th1, NULL, Thread1Proc, NULL); //Create thread1 & attach function Thread1Proc
      pthread_create(&th2, NULL, Thread2Proc, NULL); //Create thread1 & attach function Thread1Proc
      pthread_join(th1,NULL); //start thread
      pthread_join(th2,NULL); //start thread
      // fgets(sendBuff, sizeof sendBuff, stdin);
      // printf("wrote\n");
          // strcpy(sendBuff, "Message from server");
        // write(connfd, sendBuff, strlen(sendBuff));
      // sleep(1);
    }
    close(connfd);

  return 0;
}
