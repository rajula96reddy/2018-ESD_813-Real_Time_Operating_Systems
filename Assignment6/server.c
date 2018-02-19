#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <pthread.h> //pthread definition file
int connfd = 0, n=0;
char recvBuff[1024];
void *Thread1Proc() //print address of the three local variables j, k and l
{
  while(1)
  {
  // int n = 0;
  // printf("read\n");
  while((n = read(connfd, recvBuff, sizeof(recvBuff)-1)) > 0)
    {
      recvBuff[n] = 0;
      printf("Message from client:");
      if(fputs(recvBuff, stdout) == EOF)
    {
      printf("\n Error : Fputs error");
    }
      // printf("\n");
    }

  if( n < 0)
    {
      printf("\n Read Error \n");
    }
  }
}
char sendBuff[1024];
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

int main(void)
{
  int listenfd = 0;

  struct sockaddr_in serv_addr;

  // char sendBuff[1024];
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
