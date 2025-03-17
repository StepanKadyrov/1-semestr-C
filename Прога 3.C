//переставить элементы массива в обратном порядке
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 10

float random_term(float, float);

int main()
{
    srand(time(NULL));
    int n = N;
    float A[N];
    float a, x;
    
    printf("Как заполнить массив? Если вручную, то введите 0. Если случайно, то введите любое другое число ");
    scanf("%f", &a);
    if(a == 0){
        printf("Заполните массив");
        for(int k = 0; k < N; k++){
            printf("\nA[%d] = ", k);
            scanf("%f",&A[k]);
        }
    }
    else {
        float min, max;
        printf("Введите нижнюю и верхнюю границу для рандома элементов массива с точностью до двух знаков ");
        scanf("%f %f", &min,&max);
        for(int k = 0; k < N; k++){
            A[k] = random_term(min, max);
            printf("A[%d] = %f\n", k, A[k]);
        }
    }
    
    for(int k = 0; k < N/2 ; k++,n--){
        A[n-1] = A[n-1]+A[k];
        A[k] = A[n-1] - A[k];
        A[n-1] = A[n-1] - A[k];
    }
    
    printf("Обратный массив:\n");
    for(int k = 0; k < N; k++){
    printf("\nA[%d] = %f\n", k, A[k]);
    }
}

float random_term(float min, float max) {
    return (rand()%(int)((max-min)*100+1))/100.0+min;
}