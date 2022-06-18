#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define len 320

extern double inputSignal[len];
double outputSignal[len];

void runningSum(double *srcArr, double *outArr, int len);


int main()
{
    FILE *inputFile,*outputFile;

     runningSum((double *) &inputSignal[0], (double *) &outputSignal[0], (int)len);


    inputFile = fopen("input_signal.dat","w");
    outputFile = fopen("output_signal.dat","w");

    for(int i=0;i<len;i++)
    {
         fprintf(inputFile,"\n%f",inputSignal[i]);
    }

    fclose(inputFile);

    for(int i=0;i<len;i++)
    {

         fprintf(outputFile,"\n%f",outputSignal[i]);
    }

     fclose(outputFile);

    return 0;
}



void runningSum(double *srcArr, double *outArr, int len)
{
      for(int i =0;i<len;i++)
      {
          outArr[i] = outArr[i-1]+srcArr[i];
      }

}



