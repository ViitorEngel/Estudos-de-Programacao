#include <stdio.h>
#include <math.h>
#include <time.h>

int primes[100000];
int lim=0;

void print(){
    for (int i; i<lim; i++){
        if (primes[i]==0 || i==50){
            break;
        }
        else{
            printf("%d ",primes[i]);
        }
   }
}

void main(){

    int primesize=0;
    int aux=0;
    int count=0;
    while (lim<=2 || lim>1000000){
        printf("Upper limit: "); scanf("%d",&lim);
        if (lim<=2 || lim>1000000){
            printf("\nValue must be between 2 and 1000000\n");
        }
    }

    clock_t begin = clock();

    for (int i=2; i<lim; i++){
        for (int j=2; j < sqrt(i); j++){
            if (i%j==0){
                aux=1;
            }
        }
        if(aux==1){
            aux=0;
        }
        else{
            primes[count]=i;
            count++;
        }
    }

    print();

    clock_t end = clock();
    double times = (double)(end-begin)/CLOCKS_PER_SEC;
    printf("\nExecution time: %f", times);
}

