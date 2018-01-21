#include<stdlib.h>
#include<stdio.h>
#include<string.h>
void average(int *array, int window)
{
    for (int j=(window/2);j<(5686-(window/2));j++)
    {
      // printf("%d\n", j);
      int newValue = 0;
      for (int i=j-(window/2);i<=j+(window/2);i++)
      {
        // printf("i is %d\n", i);
        newValue = newValue + array[i];
      }
      // printf("%d\n", newValue);
      array[j] = newValue/window;
    }
}
int peaks(int *Data, int window)
{
    int count = 0;
    int flag1 = 0;
    int flag2 = 0;
    for (int j=(window/2);j<(5686-(window/2));j++)
    {
      // printf("%d\n", j);
      flag1 = 0;
      flag2 = 0;
      int newValue = 0;
      for (int i=j-(window/2);i<=j+(window/2);i++)
      {
          // printf("i is %d & j is %d\rn",i,j);
          if(i<j && Data[j]>=520 && Data[i]!=Data[j])
          {
            if(Data[i]<Data[j])
            {
              flag1 = flag1 + 1;
              continue;
              // printf("data[i] is %d & data[j] is %d\n",Data[i],Data[j]);
            }
            else
              break;
              // print Data[j]
          }
          else if(i>j && Data[j]>=520)
          {
            if(Data[i] <= Data[j])
            {
              flag2 = flag2 + 1;
              continue;
              // printf("data[i] is %d & data[j] is %d\n",Data[i],Data[j]);
            }
            else
              break;
          }
      }
      if (flag1 == (window)/2 && flag2 == (window)/2)
      {
        // printf("%d %d\n",flag1,flag2 );
        count = count + 1;
        // printf("%d\n", j);
      }
      // printf("%d\n", newValue);
      // array[j] = newValue/window;
    }
    return count;
}
int main(int argc, char *argv[])
{
    FILE *readFile, *writeFile;
    readFile = fopen("Samples.csv","r");
    writeFile = fopen("Output.csv", "w");
    if(readFile == NULL || writeFile == NULL)
      return -1;
    //printf(readFile, "%d\n");
    int ch;
    char value;
    ch = fgetc(readFile);
    int Data[5686];
    char buff[10];
    int count = 0;
    while ( fgets(buff,sizeof(buff),readFile) != NULL ) {
        int a = atoi(buff);
        Data[count] = a;
        count = count+1;
    }
    fclose(readFile);
    // for (size_t i = 0; i < 7; i++) {
    //   printf("%d\n", Data[i]);
    // }
    // printf("%d\n",count);
    // printf("%d\n",Data[3]);
    average(Data, atoi(argv[1]));
    // printf("%d\n", Data[3]);
    for (int i=0; i<5686; i++)
    {
      // snprintf(buff, 10, "%d", Data[i]);
      // printf("%s\n", buff);
      fprintf(writeFile, "%d\n", Data[i]);
      // fwrite(&Data[i], sizeof(Data[i]), 1, writeFile);
      // printf("%d\n", Data[i]);
    }
    int Data_New[5686];
    // char buff[10];
    count = 0;
    fclose(writeFile);
    readFile = fopen("Output.csv","r");
    while (fgets(buff,sizeof(buff),readFile) != NULL)
    {
        int a = atoi(buff);
        // printf("%d\n",a );
        Data_New[count] = a;
        count = count+1;
    }
    printf("The number of peaks are %d\n", peaks(Data_New, 5));
    fclose(readFile);
    return 1;
}
