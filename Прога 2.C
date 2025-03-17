#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

double random_x();
int random_l();
int input_l();
double input_x();
double add_new_term( double, int);

int main()
{
    srand(time(NULL));
    
    int l;
    double sum1 = 0, x = 0;
    
    l = input_l();
    x = input_x();
    
    double sum2 = pow((1-x/2),(float)-1/3) - 1;
    x = x/2;
    
    do
    {   
        sum1 = add_new_term(x, l);
        printf("\nСумма слева равна %lf\n",sum1);
        printf("Сумма справа равна %lf\n",sum2);
        printf("Разность по модулю равна = %lf. Достаточная точность? Если да, то введите 0, если нет, то введите новое число слагаемых ",fabs(sum2-sum1));
        
        scanf("\n%d",&l);
        
        if (l == 0) return 0;
    } while (l != 0);
}  

double random_x() {
    float a,b;
    printf("Введите нижнюю и верхнюю границу рандомного x<2 с точностью до двух знаков ");
    scanf("%f %f",&a, &b);
    return (rand()%(int)((b-a)*100))/100.0+a; // генерация случайного х<2
}


int random_l() {
    int a, b;
    printf("Введите нижнюю и верхнюю границу количества слагаемых для рандома ");
    scanf("%d %d",&a,&b);
    return (rand()%(b-a+1)+a); // генерация случайного числа слагаемых
}

//функция ввода числа слагаемых
int input_l(){
    int m;
    printf("Необходимо задать число слагаемых.\nХотите задать количество слагаемых вручную - введите 0.\nХотите задать количество слагаемых случайно - введите любое другое число.\n");
    scanf("%d", &m);
    
    if(m){
        m = random_l();
        printf("Рандом решил, что количество слагаемых будет %d\n",m);
        return m;
    }
    else{
        printf("Введите число слагаемых\n");
        scanf("%d", &m);
        return m;
    }
}

//функция ввода х
double input_x(){
    double m;
    printf("Как задать х?\nХотите задать x вручную - введите 0.\nХотите задать x случайно - введите любое другое число.\n");
    scanf("%lf", &m);
    
    if(m){
        m = random_x();
        printf("Рандом решил, что x = %lf", m);
        return  m;
    }
    
    else{
        printf("Введите x<2\n");
        scanf("%lf", &m);
        return m;
    }
}

double add_new_term(double x, int l){
    double pl = 1, sum1 = 0, n = 1, k = 3;
    int i = 1;
    while(i<=l){
    pl = pl*(n/k)*x;
    sum1 = sum1+pl;
    n = n+3;
    k = k+3;
    i++;
    }
    return sum1;
}
