#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIG_LENGTH 320

extern double inputSignal[320];
double outputREX[SIG_LENGTH/2];
double outputIMX[SIG_LENGTH/2];
double outputMAG[SIG_LENGTH/2];
double outputIDFT[SIG_LENGTH];

void dft(double srcArr,double outRexArr, double outImxArr, int len);
void dftMagOutput(double outMagArr);
void idft(double outArr, double *srcRexArr, double *srcImxArr, int len);

int main()
{
     FILE *inputFile, *outputRexFile, *outputImxFile, *idftOutputFile;

    dft((double *) &inputSignal[0], (double *) &outputREX[0], (double *) &outputIMX[0], (int)len);
    idft((double *) &outputIDFT[0], (double *) &outputREX[0], (double *) &outputIMX[0], (int) len);

    inputFile = fopen("input_signal.dat","w");
    outputRexFile=fopen ("output_rex.dat","w");
    outputImxFile=fopen("output_imx.dat","w");
    idftOutputFile=fopen("output_idft.dat","w");

    for(int i=0;i<SIG_LENGTH;i++){
    fprintf(inputFile,"\n%f",inputSignal[i]);
    fprintf(idftOutputFile,"\n%f",outputIDFT[i]);

    }

    for(int i=0;i<(SIG_LENGTH/2);i++)
    {
        fprintf(outputRexFile,"\n%f",outputREX[i]);
        fprintf(outputImxFile,"\n%f",outputIMX[i]);

    }

    fclose(inputFile);
    fclose(outputRexFile);
    fclose(outputImxFile);
    fclose(idftOutputFile);

    return 0;
}

void dft(double srcArr,double outRexArr, double outImxArr, int len)
{
  int i,j,k;
  double PI = 3.14159265359;

  for(j=0;j<len/2;j++)
  {
      sig_dest_rex_arr[j] =0;
      sig_dest_imx_arr[j] =0;

  }

    for(k=0;k<(len/2);k++)
    {
        for(i=0;i<len;i++)
        {
            sig_dest_rex_arr[k] = sig_dest_rex_arr[k] + sig_src_arr[i]*cos(2*PI*k*i/len);
            sig_dest_imx_arr[k] = sig_dest_imx_arr[k] - sig_src_arr[i]*sin(2*PI*k*i/len);
        }
    }


}
 void dftMagOutput(double outMagArr)
 {

     int k;
     for(k=0;k<SIG_LENGTH/2;k++)
     {
         sig_dest_mag_arr[k] = sqrt(pow(outputREX[k],2)+pow(outputIMX[k],2));
     }
 }

 void idft(double outArr, double *srcRexArr,double *srcImxArr,int len)
 {
      double PI =3.14159265359;
      int i,k;
      for(k=0;k<len/2;k++)
      {
          srcRexArr[k] = srcRexArr[k]/(len/2);
          srcImxArr[k] = -srcImxArr[k]/(len/2);
      }

      srcRexArr[0] = srcRexArr[0]/2;
      srcImxArr[0] = -srcImxArr[0]/2;

      for(i=0;i<len;i++)
      {
          idft_out_arr[i]=0;
        }
        for(k=0;k<len/2;k++)
        {
            for(i=0;i<len;i++)
            {
                idft_out_arr[i] = idft_out_arr[i]+ srcRexArr[k]*cos(2*PI*k*i/len);
                idft_out_arr[i] = idft_out_arr[i]+ srcImxArr[k]*sin(2*PI*k*i/len);

            }
        }
 }
