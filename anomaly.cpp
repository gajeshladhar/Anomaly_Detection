#include<iostream>
#include<cmath>
#include "anomaly.h"

using namespace std;
int main()
{
    double** dataset=new double*[100];
    for(int i=0;i<100;i++)
    {
        dataset[i]=new double[3];

        dataset[i][0]=(rand()/(RAND_MAX+1.0))*10 +30;
        dataset[i][1]=(rand()/(RAND_MAX+1.0))*10 +30;
        dataset[i][2]=(rand()/(RAND_MAX+1.0))*10 +30; 
    }

    double** test_set=new double*[10];
    for(int i=0;i<10;i++)
    {
        test_set[i]=new double[3];
        if(i%2==0)
        {
        test_set[i][0]=(rand()/(RAND_MAX+1.0))*10 +30;
        test_set[i][1]=(rand()/(RAND_MAX+1.0))*10 +30;
        test_set[i][2]=(rand()/(RAND_MAX+1.0))*10 +30;
        }
        else
        {
        test_set[i][0]=(rand()/(RAND_MAX+1.0))*10 +60;
        test_set[i][1]=(rand()/(RAND_MAX+1.0))*10 +60;
        test_set[i][2]=(rand()/(RAND_MAX+1.0))*10 +60;
        }
         
    }

    Anomaly* anomaly=new Anomaly(dataset,3,100);
    double** result=anomaly->make_prediction(test_set,10);
    cout<<"\n Results : \n";
    for(int i=0;i<10;i++)
    (i%2==0?cout<<"Normal : "<<result[i][0]<<endl:cout<<"Anomaly : "<<result[i][0]<<endl);

    return 0;
    
}