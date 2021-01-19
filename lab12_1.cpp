#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double A[],int n, double B[]){
    double sum=0,sqsum=0, amean, multi=1, recip=0, max, min;
    min = max = A[0];
    for(int i=0;i<n;i++){
        sum+=A[i];
        sqsum+=A[i]*A[i];
        multi*=A[i];
        recip+=1/A[i];
        if(A[i]<min)min=A[i];
        if(A[i]>max)max=A[i];
    }
    amean = sum/n;
    B[0]=amean;
    B[1]=sqrt((sqsum/n)-pow(amean,2));
    B[2]=pow(multi,(1.0/n));
    B[3]=n/recip;
    B[4]=max;
    B[5]=min;
}
