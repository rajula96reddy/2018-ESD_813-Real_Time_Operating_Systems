#include <stdlib.h>
#include <stdio.h>
#include <pthread.h> //pthread definition file
#include <sys/types.h> //To use types like pid_t
#include <time.h>

int a, b, c; //created three global variables
void *Thread1Proc() //print address of the three local variables j, k and l
{
  int i, j, k;
  a = 4;
  b = 5;
  c = 6;
  printf("Thread 1: Address of i is %p, j is %p & k is %p\n", &i, &j, &k);
  printf("Thread 1: Address of a is %p, b is %p & c is %p\n", &a, &b, &c);
  // for(int i=1; i<5; i++)
  {
    printf("Thread 1 - Value of i is %d, j is %d & k is %d\n", i, j, k);
    printf("Thread 1 - Value of a is %d, b is %d & c is %d\n", a, b, c);
  }
}
void *Thread2Proc() //print address of the three local variables j, k and l
{
  int i, j, k;
  a = 7;
  b = 8;
  c = 9;
  printf("Thread 2: Address of i is %p, j is %p & k is %p\n", &i, &j, &k);
  printf("Thread 2: Address of a is %p, b is %p & c is %p\n", &a, &b, &c);
  // for(int i=1; i<5; i++)
  {
    printf("Thread 2 - Value of i is %d, j is %d & k is %d\n", i, j, k);
    printf("Thread 2 - Value of a is %d, b is %d & c is %d\n", a, b, c);
  }
}
void *Thread3Proc() //print address of the three local variables j, k and l
{
  int i, j, k;
  a = 10;
  b = 11;
  c = 12;
  printf("Thread 3: Address of i is %p, j is %p & k is %p\n", &i, &j, &k);
  printf("Thread 3: Address of a is %p, b is %p & c is %p\n", &a, &b, &c);
  // for(int i=1; i<5; i++)
  {
    printf("Thread 3 - Value of i is %d, j is %d & k is %d\n", i, j, k);
    printf("Thread 3 - Value of a is %d, b is %d & c is %d\n", a, b, c);
  }
}
int main()
{
  a = 1;
  b = 2;
  c = 3;
  pthread_t th1, th2, th3;
  pthread_create(&th1, NULL, Thread1Proc, NULL); //Create thread1 & attach function Thread1Proc
  pthread_create(&th2, NULL, Thread2Proc, NULL); //Create thread2 & attach function Thread2Proc
  pthread_create(&th3, NULL, Thread3Proc, NULL); //Create thread3 & attach function Thread3Proc
  pthread_join(th1,NULL); //start thread
  pthread_join(th2,NULL); //start thread
  pthread_join(th3,NULL); //start thread
  return 0;
}
