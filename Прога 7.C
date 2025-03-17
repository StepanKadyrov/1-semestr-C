/*Определить, является ли матрица симметричной(относительно главной оси). Найти максимальный элемент среди стоящиях на
главной и побочной диагонали и поменять его местами с элементом, стоящим на пересечении этих диагоналей
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int** array_creation(int);
void filling_array(int**, int);//функция заполнения массива
void print_array(int**, int);//функция печати массива
void random_array(int**, int);//функция генерации случайных элементов массива
int is_symmetry(int**, int);//функция, проверяющая, является ли матрица симметричной
int maximum(int**, int);//функция по поиску максимального элемента на главной и побочной оси
int** swap(int**, int, int);//свап максимального элемента на диагоналях с элементом, стоящим на месте пересечения диагоналей
void copy_array(int**, int**, int);//функция создания копии массива
void free_2(int**, int);

int main()
{
    srand(time(NULL));
    int N;
    printf("Введите порядок матрицы ");
    scanf("%d", &N);
    int** A = array_creation(N);
    filling_array(A, N);
    print_array(A, N);

    if(is_symmetry(A, N)){
        printf("\nМатрица не симметричная");
    }
    else{
        printf("\nМатрица симметричная");
    }
    int max = maximum(A, N);
    printf("\nМаксимальный элемент на диагоналях %d\n",max);
    int** B = swap(A,N, max);//поиск максимального элемента на главной и побочной оси и свап его с элементом, стоящим на месте пересечения диагоналей
    print_array(B, N);
    free_2(A, N);
    free_2(B, N);
}

int** array_creation(int N){
    int** array = (int **)malloc(N*sizeof(int *));// инициализация массива
    for(int i = 0; i < N; i++){
        *(array+i)=(int*)malloc(N*sizeof(int));
    }
    return array;
}

void filling_array(int** A, int N){
    float a;
    printf("Как заполнить массив? Если вручную, то введите 0. Если случайно, то введите любое другое число ");//выбор варианта заполнения массива
    scanf("%f", &a);
    if(a == 0){
        printf("Заполните массив");//заполнение вручную
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                printf("\nA[%d][%d] = ", i,j);
                scanf("%d",*(A+i)+j);
            }
        }
    }
    else {
        random_array(A, N);//заполнение рандомно
    }
}

void print_array(int** A, int N){
    printf("Матрица:\n");
    int i,j;
    for(i = 0; i < N;i++){
        for (j = 0; j < N; j++){
        printf("%d\t",*(*(A+i)+j));
    }
      printf("\n");
    }
}

void random_array(int** A, int N){
  int a,b;
  printf("Введите нижнюю и верхнюю границу для рандома ");
  scanf("%d %d",&a,&b);
  if(b<a){
      a = a+b;
      b = a-b;
      a = a-b;
  }
  for(int i = 0; i < N;i++){
      for (int j = 0; j < N; j++){
        *(*(A+i)+j) = rand()%(b-a+1)+a;
      }
  }
}

int is_symmetry(int ** A, int N){
    int flag = 0;
    for(int i = 0; i < N;i++){
      for (int j = 0; j < N; j++){
        if(*(*(A+i)+j) != *(*(A+j)+i)){
            flag = 1;
        }
        if(flag) break;
      }
    }
    return flag;
}

void copy_array(int** A, int** B, int N){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                *(*(B+i)+j) = *(*(A+i)+j);
            }
        }
}

int maximum(int** B, int N){
    int i = 0, n = N-1, max = **B;// записываем в максимум первый элемент(он всегда лежит на главной диагонали)
    for(i = 0;i < N; i++, n--){//поиск максимального элемента на диагоналях(сразу на двух диагоналях идёт проверка)
        if(*(*(B+i)+i)>max){
            max = *(*(B+i)+i);
        }
        if(*(*(B+i)+n)>max){
            max = *(*(B+i)+n);
        }
    }
    return max;
}

int** swap(int** A, int N, int max){
    int** B = array_creation(N);//Создание и заполнение копии начального массива, чтобы далее работать с ней и не изменять начальный массив
    copy_array(A, B, N);
    if(N%2 == 0){//проверка порядка матрицы на чётность
        printf("\nНевозможно поменять максимальный элемент местами с элементом, стоящим на пересении этих диагоналей, так как пересечение пусто\n");
    }
    else{
        int center = *(*(B+N/2)+N/2);//записываем центральный элемент в переменную
        int i = 0, n = N-1;
        for(i = 0;i < N; i++, n--){//проходимся по двум диагоналям снова и сравниваем их с максимумом. Если true, то меняем элемент на центральный
            if(*(*(B+i)+i)==max){
                *(*(B+i)+i) = center;
            }
            if(*(*(B+i)+n)==max){
                *(*(B+i)+n) = center;
            }
        }
        *(*(B+N/2)+N/2) = max;//запись в центральный элемент максимума
    }
    return B;
}

void free_2(int** A, int N){
    for(int i = 0; i<N; i++){
        free(*(A+i));
    }
    free(A);
}