#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define SIG_LENGTH 320

extern double _320_pts_ecg_IMX[SIG_LENGTH];
extern double _320_pts_ecg_REX[SIG_LENGTH];

double outputMag[SIG_LENGTH];
double outputPhase[SIG_LENGTH];


void rect_to_polar_conversion(double *srcRexArr,
                              double *srcImxArr,
                              double *outMagArr,
                              double *outPhaseArr,
                              int len
                              );

int main()
{
   FILE *inputRexFile, *inputImxFile, *outputMagFile, *outputPhaseFile;

     rect_to_polar_conversion((double *)&_320_pts_ecg_REX[0],
                              (double *)&_320_pts_ecg_IMX[0],
                              (double *)&outputMag[0],
                              (double *)&outputPhase[0],
                              (int) SIG_LENGTH
                              );

    inputRexFile = fopen("input_rex.dat","w");
    inputImxFile = fopen("input_imx.dat","w");
    outputMagFile = fopen("output_magnitude.dat","w");
    outputPhaseFile  = fopen("output_phase.dat","w");

    for(int i =0;i<SIG_LENGTH;i++)
    {
        fprintf(inputRexFile,"\n%f",_320_pts_ecg_REX[i]);
        fprintf(inputImxFile,"\n%f",_320_pts_ecg_IMX[i]);
        fprintf(outputMagFile,"\n%f",outputMag[i]);
        fprintf(outputPhaseFile,"\n%f",outputPhase[i]);
    }

    fclose(inputRexFile);
    fclose(inputImxFile);
    fclose(outputMagFile);
    fclose(outputPhaseFile);

    return 0;
}



void rect_to_polar_conversion(double *srcRexArr,
                              double *srcImxArr,
                              double *outMagArr,
                              double *outPhaseArr,
                              int len
                              )
    {
     double PI = 3.14159265358979f;
     int k;
     for(k=0;k<len;k++)
     {
         outMagArr[k] = sqrt(powf(srcRexArr[k],2)+ powf(srcImxArr[k],2));
          if(srcRexArr[k]==0)
          {
            srcRexArr[k]= pow(10,-20);
            outPhaseArr[k] = atan(srcImxArr[k]/srcRexArr[k]);

            }

            if((srcRexArr[k]<0)&&(srcImxArr[k]<0))
            {
                outPhaseArr[k] = outPhaseArr[k]-PI;
            }
           if((srcRexArr[k]<0)&&(srcImxArr[k]>=0))
           {
               outPhaseArr[k] = outPhaseArr[k]+PI;
           }
     }

    }
