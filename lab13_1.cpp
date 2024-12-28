#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}

void stat(const double A[],int N,double B[]){
    
    double sumA = 0;
    for(int i=0;i<N;i++){
        sumA += A[i];
    }
    B[0] = sumA/N;
    
    double sumS = 0;
    for(int i=0;i<N;i++){
        sumS += pow((A[i]-B[0]),2);
    }
    B[1] = sqrt(sumS/N);
    
    double sumG=1;
    for(int i=0;i<N;i++){
        sumG *= A[i];
    }
    B[2] = pow(sumG,(1.0/N));
    
    double sumH = 0;
    for(int i=0;i<N;i++){
        sumH += 1.0/A[i];
    }
    B[3] = N/sumH;
    
    double max = A[0];
    double min = A[0];
    for(int i=0;i<N;i++){
        if(A[i]>max) max =A[i];
        if(A[i]<min) min =A[i];
    }
    B[4]=max;
    B[5]=min;
        
}

