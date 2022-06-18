#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define SIG_LENGTH 320
#define IMP_RSP_LENGTH 29

extern double inputSignal[SIG_LENGTH];
extern double impulseRes[IMP_RSP_LENGTH];

double outputSignal[SIG_LENGTH+IMP_RSP_LENGTH];

void convolution( double *srcArr,
                  double *outArr,
                  double *irArr,
                  int srcLen,
                  int irLen
                 );


int main()
{
    FILE *inputFile, *irFile, *outputFile;

     convolution( (double*) &inputSignal[0],
                  (double*) &outputSignal[0],
                  (double*) &impulseRes[0],
                  (int) SIG_LENGTH,
                  (int) IMP_RSP_LENGTH
                 );

    inputFile = fopen("input_signal.dat","w");
    irFile   = fopen ("impulse_response.dat","w");
    outputFile = fopen("output_signal.dat","w");

    for(int i=0;i<SIG_LENGTH;i++)
    {
         fprintf(inputFile,"\n%f",inputSignal[i]);
    }

    fclose(inputFile);

    for(int i=0;i<IMP_RSP_LENGTH;i++)
    {
         fprintf(irFile,"\n%f",Impulse_response[i]);

    }

    fclose(irFile);

     for(int i=0;i<SIG_LENGTH+IMP_RSP_LENGTH;i++)
     {

         fprintf(outputFile,"\n%f",outputSignal[i]);
     }

     fclose(outputFile);

    return 0;
}


void convolution( double *srcArr,
                  double *outArr,
                  double *irArr,
                  int srcLen,
                  int irLen
                 )
{
    int i,j;
    for(i=0;i<srcLen+irLen;i++)
    {
        outArr[i] =0;
    }

      for(i=0;i<srcLen;i++)
      {
          for(j=0;j<irLen;j++)
          {
              outArr[i+j] = outArr[i+j]+ srcArr[i]*irArr[j];

          }
      }

}
