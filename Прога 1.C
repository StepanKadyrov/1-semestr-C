#include <stdio.h>
#include <math.h>

int main()
{
    double n = 1, k = 3, pl = 1, sum1 = 0, x = 0;
    int i = 1, l=0;
    
    printf("Введите число слагаемых и х<2 ");
    scanf("%d %lf",&l,&x);
    
    double sum2 = pow((1-x/2),(float)-1/3) - 1;
    x = x/2;
    
    do
    {   
        if(i>l){ 
            printf("\nСумма слева равна %lf\n",sum1);
            printf("Сумма справа равна %lf\n",sum2);
            printf("Разность равна = %lf. Достаточная точность? Если да, то введите 0, если нет, то введите новое, большее предыдущего число слагаемых ",sum2-sum1);
            scanf("%d",&l);
            if (l == 0) return 0;
        }
            pl = pl*(n/k)*x;
            sum1 = sum1 + pl;
            n = n+3;
            k = k+3;
            i++;
        
    } while (l != 0);
}  