//The client send simple mathematical equations to server.
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

struct my_msgbuf {
  long mtype;
  char mtext[200];
  int result;
};
struct my_msgbuf1 {
  long mtype;
  int mtext[1];
};
int main(void)
{
  struct my_msgbuf buf;
  struct my_msgbuf1 buf1;
  int msqid1, msqid2;
  key_t key, key0;
  if ((key = ftok("client.c", 'a')) == -1)
  {
    perror("ftok");
    exit(1);
  }
  if ((msqid1 = msgget(key, 0644 | IPC_CREAT)) == -1)
  {
    perror("msgget");
    exit(1);
  }
  if ((key0 = ftok("server.c", 'a')) == -1)
  {
    perror("ftok");
    exit(1);
  }
  if ((msqid2 = msgget(key0, 0644 | IPC_CREAT)) == -1)
  {
    perror("msgget");
    exit(1);
  }
  printf("Enter lines of text, ^D to quit:\n");
  while(fgets(buf.mtext, sizeof buf.mtext, stdin) != NULL)
  {
    buf.mtype = rand()%10; /* we don't really care in this case */
    int len = strlen(buf.mtext);
    /* ditch newline at end, if it exists */
    if (buf.mtext[len-1] == '\n') buf.mtext[len-1] = '\0';
      printf("%s\n",buf.mtext );
    if (msgsnd(msqid1, &buf, len+1, 0) == -1) /* +1 for '\0' */
      perror("msgsnd");
    // usleep(10000);
    if (msgrcv(msqid2, &buf1, 2, 0, MSG_NOERROR) == -1)
      {
        perror("msgrcv");
        exit(1);
      }
      printf("%d\n",buf1.mtext[0]);
  }
  if (msgctl(msqid1, IPC_RMID, NULL) == -1)
  {
    perror("msgctl");
    exit(1);
  }
  return 0;
}
