#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <pthread.h> //pthread definition file
int sockfd = 0,n = 0;
char sendBuff[1024];
void *Thread1Proc() //print address of the three local variables j, k and l
{
  while(1)
  {
  fgets(sendBuff, sizeof sendBuff, stdin);
  // printf("wrote\n");
      // strcpy(sendBuff, "Message from server");
    write(sockfd, sendBuff, strlen(sendBuff));
  }
}
char recvBuff[1024];
void *Thread2Proc() //print address of the three local variables j, k and l
{
  while(1)
  {
    // printf("read\n");
  int n = 0;
  while((n = read(sockfd, recvBuff, sizeof(recvBuff)-1)) > 0)
    {
      recvBuff[n] = 0;
      printf("Message from server:");
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
int main(void)
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
  serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

  if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr))<0)
    {
      printf("\n Error : Connect Failed \n");
      return 1;
    }
    pthread_t th1, th2;
  // for(;;)
{
  pthread_create(&th1, NULL, Thread1Proc, NULL); //Create thread1 & attach function Thread1Proc
  pthread_create(&th2, NULL, Thread2Proc, NULL); //Create thread1 & attach function Thread1Proc
  pthread_join(th1,NULL); //start thread
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
