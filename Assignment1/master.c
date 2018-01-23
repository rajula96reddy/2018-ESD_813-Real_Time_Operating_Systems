#include<stdlib.h>
#include<stdio.h>
#include<string.h>
void average(int *array, int window) //Function to average a number based on it's neighbours for the given size of the window
{
    for (int j=(window/2);j<(5686-(window/2));j++) //Ignore the numbers in the first & last as they don't have neighbours on both sides
    {
      int newValue = 0;
      for (int i=j-(window/2);i<=j+(window/2);i++) //Neigbours for a given number
      {
        newValue = newValue + array[i];
      }
      array[j] = newValue/window; //Change the data itself
    }
}
int peaks(int *Data, int window) //Function to find the peaks for a given data and choosen size of window
{
    int count = 0; //Peaks count
    int flag1 = 0; //Flag to
    int flag2 = 0;
    for (int j=(window/2);j<(5686-(window/2));j++) //Ignore the first & last numbers as they don't have neighbours on both the sides
    {
      //Flags to identify peaks
      flag1 = 0;
      flag2 = 0;
      int newValue = 0;
      for (int i=j-(window/2);i<=j+(window/2);i++) //Run iteration to give values to both the flags
      {
          if(i<j && Data[j]>=520 && Data[i]!=Data[j]) //520 is the threshold for the peak which is given on observation
          {
            if(Data[i]<Data[j])
            {
              flag1 = flag1 + 1;
              continue;
            }
            else
              break;
          }
          else if(i>j && Data[j]>=520)
          {
            if(Data[i] <= Data[j])
            {
              flag2 = flag2 + 1;
              continue;
            }
            else
              break;
          }
      }
      if (flag1 == (window)/2 && flag2 == (window)/2) //Evaluate the flags & incremet counter if it's a peak
      {
        count = count + 1;
      }
    }
    return count;
}
int main(int argc, char *argv[])
{
    FILE *readFile, *writeFile;
    readFile = fopen("Samples.csv","r"); //Input file
    writeFile = fopen("Output.csv", "w"); //Output file
    if(readFile == NULL || writeFile == NULL)
      return -1;
    int ch;
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
    average(Data, atoi(argv[1])); //Smoothen data
    for (int i=0; i<5686; i++)
    {
      fprintf(writeFile, "%d\n", Data[i]);    }
    int Data_New[5686];
    count = 0;
    fclose(writeFile);
    readFile = fopen("Output.csv","r"); //Read smoothen data for finding peaks
    while (fgets(buff,sizeof(buff),readFile) != NULL)
    {
        int a = atoi(buff);
        Data_New[count] = a;
        count = count+1;
    }
    printf("The number of peaks are %d\n", peaks(Data_New, 5));
    fclose(readFile);
    return 1;
}
