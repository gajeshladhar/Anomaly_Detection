#include "matrix.h"

class Anomaly
{
    double** dataset;
    int features;
    int batch_size;
    double* means;
    double* sigmas;

    public :
    Anomaly(double** dataset,int features,int batch_size):
    dataset(dataset),features(features),batch_size(batch_size)
    {
        calculate();
    }
    private : void calculate()
    {
        means=get_mean(dataset,batch_size,features);
        sigmas=get_std(dataset,batch_size,features);
        
    }
    private : double guassian(double x,int j)
    {
       return exp(-(x-means[j])*(x-means[j])/(2.0*sigmas[j]*sigmas[j]))/(sqrt(2.0*3.14)*sigmas[j]) ;
    }
    public : double** make_prediction(double** input,int n)
    {
        double** result=new double*[n];
        for(int i=0;i<n;i++)
        result[i]=new double[1];

        double probs=1.0*pow(10,features);
        for(int i=0;i<n;i++)
        {   
            probs=1.0*pow(10,features);
            for(int j=0;j<features;j++)
            {
                probs*=guassian(input[i][j],j);
            }
            result[i][0]=probs;
        }

    return result;
    }
};