//переставить элементы массива в обратном порядке
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

float* array_creation(int*);//функция создания массива
void filling_array(float *,int);//функция заполнения массива
void print_array(float *,int);//функция печати массива
void make_reverse_array(float *,int);//функция перестановки массива в обратном порядке
float random_term(float, float);//функция генерации рандомного числа

int main()
{
    srand(time(NULL));
    float* A;
    int n;//размер массива
    int* pn = &n;//адрес переменной n. Это необходимо, чтобы из функции вытащить и массив, и размер массива
    A = array_creation(pn);//создание массива
    
    filling_array(A,n);
    print_array(A,n);
    make_reverse_array(A,n);
    print_array(A,n);
    free(A);
}

float* array_creation(int* pn){
    printf("Введите размер массива ");
    scanf("%d",pn);
    float* A = (float *)malloc(*pn*sizeof(float));
    return A;
}

void filling_array(float*A, int n){
    float a;
    printf("Как заполнить массив? Если вручную, то введите 0. Если случайно, то введите любое другое число ");
    scanf("%f", &a);
    if(a == 0){
        printf("Заполните массив");
        for(int k = 0; k < n; k++){
            printf("\nA[%d] = ", k);
            scanf("%f",(A+k));
        }
    }
    else {
        float min, max;
        printf("Введите нижнюю и верхнюю границу для рандома элементов массива с точностью до двух знаков ");
        scanf("%f %f", &min,&max);
        if(max<min){
          min = min+max;
          max = min-max;
          min = min-max;
        }
        for(int k = 0; k < n; k++){
            *(A+k) = random_term(min, max);
        }
    }
}

void print_array(float*A, int n){
    printf("Массив:\n");
    for(int k = 0; k < n;k++){
        printf("A[%d] = %f\n", k, *(A+k));
    }
    printf("\n");
}

void make_reverse_array(float* A, int n){
        for(int k = 0; k < n/2 ; k++){
            *(A+n-k-1) = *(A+n-k-1) + *(A+k);
            *(A+k) = *(A+n-k-1) - *(A+k);
            *(A+n-k-1) = *(A+n-k-1) - *(A+k);
        }
}

float random_term(float min, float max) {
    return (rand()%(int)((max-min)*100+1))/100.0+min;
}