#include <stdlib.h>
#include <stdio.h>
#include <unistd.h> //fork() definition file
#include <sys/types.h> //To use types like pid_t

int g_first, g_second, g_third; //created Three global variables
void PrintVariable() //print address of the three local variables j, k and l
{
  int j, k, l;
  printf("Address of j is %p, k is %p & l is %p\n", &j, &k, &l);
  printf("Address of g_first is %p, g_second is %p & g_third is %p\n", &g_first, &g_second, &g_third);
}
int main()
{
  // pid_t main_pid = getpid();
  // printf("%d\n", main_pid);
  // int i, j, k;
  FILE *f1; //file pointer
  f1 = fopen("Kill.sh", "w");
  fprintf(f1, "#!/bin/bash\n"); //start line of bash script
  fclose(f1);
  pid_t child1_pid = fork();
  // printf("%d\n", result);
  if(child1_pid == 0)
  {
    printf("This is child 1\n");
    PrintVariable();
    // printf("Address of i is %p, j is %p & k is %p\n", &i, &j, &k);
  }
  else
  {
    f1 = fopen("Kill.sh", "a");
    fprintf(f1, "pkill -9 %d\n", child1_pid); //kill command for first child
    fclose(f1);
    pid_t child2_pid = fork();
    if(child2_pid == 0)
    {
      printf("This is child 2\n");
      PrintVariable();
      // printf("Address of i is %p, j is %p & k is %p\n", &i, &j, &k);
    }
    else
    {
      f1 = fopen("Kill.sh", "a");
      fprintf(f1, "pkill -9 %d\n", child2_pid);//kill command for second child
      fclose(f1);
      pid_t child3_pid = fork();
      if(child3_pid == 0)
      {
        printf("This is child 3\n");
        PrintVariable();
        // printf("Address of i is %p, j is %p & k is %p\n", &i, &j, &k);
      }
      else
      {
        f1 = fopen("Kill.sh", "a");
        fprintf(f1, "pkill -9 %d\n", child3_pid);//kill command for third child
        fclose(f1);
        while(1)
        {}
      }
    }
    // printf("This is parent\n");
    // printf("Address of i is %p, j is %p & k is %p\n", &i, &j, &k);
  }
  fclose(f1);
  return 0;
}
