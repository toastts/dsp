#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define len 320

extern double input_f32_1kHz_15kHz[len];
double sigVar(double * arr, double mean, int len);
double sigStdev(double sig_variance);
double sigMean(double *arr, int len );

double MEAN;
double VARIANCE;
double STD;

int main()
{

    MEAN = sigMean(&input_f32_1kHz_15kHz[0],len);
    VARIANCE = sigVar(&input_f32_1kHz_15kHz[0], MEAN, len);
    STD = sigStdev(VARIANCE);

    printf("\n\nStandard Deviation = %f\n\n\n",STD);

    return 0;
}





double sigMean(double *arr, int len )
{
    double mean =0.0;
    for(int i =0;i<len;i++)
    {
        mean = mean + arr[i];

    }

    mean = mean/(double)len;
    return mean;
}

double sigVar(double * arr, double mean, int len)
{
    double var =0.0;
    for(int i=0; i<len;i++)
    {
        var = var +pow((arr[i]-mean),2);

    }
    var = var /(len-1);
    return var;

}

double sigStdev(double sig_variance)
{

    double stdev = sqrt(sig_variance);
    return stdev;
}

