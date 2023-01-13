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

double AM(const double a[],int b){
    double sum = 0;
    for(int i = 0; i < b; i++){
        sum += a[i];
    }
    return sum/b;
}

double SD(const double a[],int b){
    double sum = 0;
    double sd;
    for(int i = 0; i < b; i++){
        sum += pow(a[i],2);
    }
    sd = sqrt((sum/b)-(pow(AM(a,b),2)));
    return sd;
}

double GM(const double a[],int b){
    double x = 1;
    for(int i = 0; i < b; i++){
        x *= a[i];
    }
    return pow(x,(double)1/b);
}

double HM(const double a[],int b){
    double x = 0;
    for(int i = 0; i < b; i++){
        x = x + (double)1/a[i];
    }
    return (double)b/x;
}

double MAX(const double a[],int b){
    double max = a[0];
    for(int i = 0; i < b; i++){
        if(a[i] > max){
            max = a[i];
        }
    }
    return max;
}

double MIN(const double a[],int b){
double min = a[0];
    for(int i = 0; i < b; i++){
        if(a[i] < min){
            min = a[i];
        }
    }
    return min;
}

void stat(const double A[],int N,double B[]){
    B[0] = AM(A,N);
    B[1] = SD(A,N);
    B[2] = GM(A,N);
    B[3] = HM(A,N);
    B[4] = MAX(A,N);
    B[5] = MIN(A,N);
}