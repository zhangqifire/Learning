#include <stdlib.h>
#include <math.h>
#include<stdio.h>
double gaussrand()
{
    static double V1, V2, S;
    static int phase = 0;
    double X;
    
    if(phase == 0) {
		do {
		    double U1 = (double)rand() / RAND_MAX;
		    double U2 = (double)rand() / RAND_MAX;
            
		    V1 = 2 * U1 - 1;
		    V2 = 2 * U2 - 1;
		    S = V1 * V1 + V2 * V2;
		} while(S >= 1 || S == 0);
        
		X = V1 * sqrt(-2 * log(S) / S);
    } else
		X = V2 * sqrt(-2 * log(S) / S);
    
    phase = 1 - phase;
    
    return X;
}
int main()
{
    FILE *fp;
    fp=fopen("/Users/zq/Desktop/data.txt","w");
    double x[10000];
    for (int i=0;i<1000;i++){
        x[i]=gaussrand();
        
        printf("%f\n",x[i]);
        fprintf(fp,"%f\n",x[i]);
    }
    return 0;
    }