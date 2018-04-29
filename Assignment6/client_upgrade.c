#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include<sys/types.h>
#include "g711.c"
#include <arpa/inet.h>
#include <pthread.h> //pthread definition file
#include <pulse/simple.h>
#include <pulse/error.h>
int sockfd = 0,n = 0;
char sendBuff[10240];
void *Thread1Proc() //print address of the three local variables j, k and l
{
  static const pa_sample_spec ss = {
    .format = PA_SAMPLE_S16LE,
    .rate = 44100,
    .channels = 2
  };
  pa_simple *s = NULL;
  int ret = 1;
  int error;
  /* Create the recording stream */
  if (!(s = pa_simple_new(NULL, "VoIP", PA_STREAM_RECORD, NULL, "record", &ss, NULL, NULL, &error))) {
    fprintf(stderr, __FILE__": pa_simple_new() failed: %s\n", pa_strerror(error));
    goto finish;
  }
  while(1)
  {

  // fgets(sendBuff, sizeof sendBuff, stdin);
  // // printf("wrote\n");
  //     // strcpy(sendBuff, "Message from server");
      ssize_t r;
      uint8_t buf[10240];
      uint8_t buf2[10240];
      /* Record some data ... */
      if (pa_simple_read(s, buf, sizeof(buf), &error) < 0) {
          fprintf(stderr, __FILE__": pa_simple_read() failed: %s\n", pa_strerror(error));
          goto finish;
      }
      /* And write it to STDOUT */
      // if (loop_write(STDOUT_FILENO, buf, sizeof(buf)) != sizeof(buf)) {
      //     fprintf(stderr, __FILE__": write() failed: %s\n", strerror(errno));
      //     goto finish;
      // }
      // write(STDOUT_FILENO, buf, sizeof(buf));
      // for(int i=0;i<10240;i++)
  		// {
  		// 	buf2[i]=linear2alaw(buf[i]);
  		// 	//printf("Decoding");
      //
  		// }
      write(sockfd, buf2, sizeof(buf2));
  }
  finish:
		if (s)
		pa_simple_free(s);
}
char recvBuff[10240];
void *Thread2Proc() //print address of the three local variables j, k and l
{
  // pa_simple *s = pa_simple_new(NULL, "./server", PA_STREAM_PLAYBACK, NULL, "playback", &ss, NULL, NULL, &error);
  pa_simple *s = NULL;
  int ret = 1;
        for (;;) {
          static const pa_sample_spec ss = {
            .format = PA_SAMPLE_S16LE,
            .rate = 44100,
            .channels = 1
          };
          int error;
          if (!(s = pa_simple_new(NULL, "VoIP", PA_STREAM_PLAYBACK, NULL, "playback", &ss, NULL, NULL, &error))) {
            fprintf(stderr, __FILE__": pa_simple_new() failed: %s\n", pa_strerror(error));
            // goto finish;
          }
            uint8_t buf[10240];
            ssize_t r;
            /* Read some data ... */
            if ((r = read(sockfd, buf, sizeof(buf))) <= 0) {
                if (r == 0) /* EOF */
                    break;
                fprintf(stderr, __FILE__": read() failed: %s\n", strerror(errno));
                // goto finish;
            }
            /* ... and play it */
            if (pa_simple_write(s, buf, (size_t) r, &error) < 0) {
                fprintf(stderr, __FILE__": pa_simple_write() failed: %s\n", pa_strerror(error));
                // goto finish;
            }
        /* Make sure that every single sample was played */
        if (pa_simple_drain(s, &error) < 0) {
            fprintf(stderr, __FILE__": pa_simple_drain() failed: %s\n", pa_strerror(error));
            // goto finish;
        }
        if (s != NULL) {
		pa_simple_free(s);
		s = NULL;
	}
}
        // ret = 0;
        // finish:
        //     if (s)
        //         pa_simple_free(s);
        // return ret;

}
int main(int argc, char*argv[])
{
  struct sockaddr_in serv_addr;

  memset(sendBuff, '0' ,sizeof(sendBuff));
  memset(recvBuff, '0' ,sizeof(recvBuff));
  if((sockfd = socket(AF_INET, SOCK_STREAM, 0))< 0)
    {
      printf("\n Error : Could not create socket \n");
      return 1;
    }
    printf("This is client. Start typing to chat with server\n");
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(5000);
  serv_addr.sin_addr.s_addr = inet_addr(argv[1]);

  if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr))<0)
    {
      printf("\n Error : Connect Failed \n");
      return 1;
    }
    pthread_t th1, th2;
  // for(;;)
{
  // pthread_create(&th1, NULL, Thread1Proc, NULL); //Create thread1 & attach function Thread1Proc
  pthread_create(&th2, NULL, Thread2Proc, NULL); //Create thread1 & attach function Thread1Proc
  // pthread_join(th1,NULL); //start thread
  pthread_join(th2,NULL); //start thread
  // printf("read\n");
// int n = 0;
// while((n = read(sockfd, recvBuff, sizeof(recvBuff)-1)) > 0)
//   {
//     recvBuff[n] = 0;
//     if(fputs(recvBuff, stdout) == EOF)
//   {
//     printf("\n Error : Fputs error");
//   }
//     // printf("\n");
//   }
//
// if( n < 0)
//   {
//     printf("\n Read Error \n");
//   }
}
return 0;
}
