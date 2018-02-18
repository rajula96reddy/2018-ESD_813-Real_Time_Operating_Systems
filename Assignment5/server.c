//The server computes the equation and send the results back to the clien4t.
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
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
  int number1, number2, result;
  char operation;
  int computation_id=0;
  key_t key, key0;
  FILE *output;
  if ((key = ftok("client.c", 'a')) == -1)
  {
    perror("ftok");
    exit(1);
  }
  if ((key0 = ftok("server.c", 'a')) == -1)
  {
    perror("ftok");
    exit(1);
  }
  if ((msqid1 = msgget(key, 0644 | IPC_CREAT)) == -1)
  {
    perror("msgget");
    exit(1);
  }
  if ((msqid2 = msgget(key0, 0644 | IPC_CREAT)) == -1)
  {
    perror("msgget");
    exit(1);
  }
  for(;;)
  {
    output = fopen("output.bat", "a");//Store the computation requested and result in a file for future purposes
    if (output == NULL)
    {
      printf("Error !");
      exit(1);
    }
    if (msgrcv(msqid1, &buf, sizeof buf.mtext, 0, 0) == -1)
    {
      perror("msgrcv");
      exit(1);
    }
    printf("Client id is: \"%ld\"\n", buf.mtype);
    number1 = buf.mtext[0]-'0';
    printf("%d\n",buf.mtext[0]-'0');
    operation = buf.mtext[1];
    printf("%c\n",buf.mtext[1]);
    number2 = buf.mtext[2]-'0';
    printf("%d\n",buf.mtext[2]-'0');
    if(operation == '+')
    {
      result = number1 + number2;
    }
    else if(operation == '-')
    {
      result = number1 - number2;
    }
    else if(operation == '*')
    {
      result = number1 * number2;
    }
    else if(operation == '/')
    {
      result = number1 / number2;
    }
    buf1.mtext[0] =  result;
    if (msgsnd(msqid2, &buf1, 2, 0) == -1) /* +1 for '\0' */
      perror("msgsnd");
    printf("%d\n", result);
    fprintf(output, "Computation %d, Requested by %ld: %d %c %d, Result is %d\n", computation_id, buf.mtype, number1, operation, number2, result);
    computation_id ++;
    fclose(output);
  }
  if (msgctl(msqid2, IPC_RMID, NULL) == -1)
  {
    perror("msgctl");
    exit(1);
  }
  return 0;
}
