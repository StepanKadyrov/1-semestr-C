#include <stdlib.h>
#include <stdio.h>

void korpus(long long int, long long int*, long long int*, int, int);
long long int* make_new_array(long long int*, long long int*, int, int);

int main()
{
    int n1, n2;
    printf("Input size of first array: ");
    scanf("%d", &n1);
    long long int* A = (long long int*)malloc(n1*sizeof(long long int));
    
    for(int i = 0; i < n1; i++){
        printf("Input number %d: ", i+1);
        scanf("%lld", A+i);
    }
    
    printf("Input size of second array: ");
    scanf("%d", &n2);
    long long int* B = (long long int*)malloc(n2*sizeof(long long int));
    
    for(int i = 0; i < n2; i++){
        printf("Input number %d: ", i+1);
        scanf("%lld", B+i);
    }
    
    long long int* C =  make_new_array(A, B, n1, n2);
    
    printf("Cpravochnik vseh nomerov:\n");
    for(int i = 0; i < n1+n2; i++){
        printf("%lld\n", *(C+i));
    }
    
    int j = 0;
    do{
        long long int number;
        printf("Vvedite nomer, kotory hotite nayti: ");
        scanf("%lld", &number);
        korpus(number, A, B, n1, n2);
        printf("\nEsli ne hotite iskat drugie nomera, to vvedite 0. B inom sluchae lubuu drugoe chislo: ");
        scanf("%d", &j);
    }while(j != 0);
    return 0;
}

void korpus(long long int number, long long int* A, long long int* B, int n1, int n2){
    int flag = 0;
    for(int i = 0; i < n1; i++){
        if(number == *(A+i)){
            printf("1 ");
            flag++;
        }   
    }

    for(int i = 0; i < n2; i++){
        if(number == *(B+i)){
            printf("2 ");
            flag++;
        }   
    }
    
    if(flag == 0){
        printf("Takovo nomera net v spravochnike");
    }
}

long long int* make_new_array(long long int* A, long long int* B, int n1, int n2){
    long long int* C = (long long int*)malloc((n1+n2)*sizeof(long long int));
    for(int i = 0; i < n1; i++){
        *(C + i) = *(A + i);    
    }
    for(int i = 0; i < n2; i++){
        *(C + i + n1) = *(B + i);    
    }
    
    for(int i = 0; i < n1 + n2 -1; i++){
        for(int k = 0; k < n1 + n2 - 1 - i; k++){
            if(C[k] > C[k+1]){
                long long int temp = C[k];
                C[k] = C[k+1];
                C[k+1] = temp;
            }
        }        
    }
    
    re