#include <stdio.h>
#include <limits.h>



int main(){
     int fib1 = 1, fib2 = 1;
     int m;
     unsigned long long int sum = fib1;
     printf("Введите количество чисел в последовательности Фибоначчи >>\n");
     do{
     	   if(m < 0)
     	   	printf("Некорректное значение. Попробуйте ещё раз\n");
	   scanf("%d",&m);
	}while(m <= 0);	  
	printf("%3d  %d\n", 1, 1);
     for(int i = 2; i <= m; ++i){
     		if(i >= 1000 || sum >= ULONG_MAX)
     			break;
     		printf("%3d  %llu\n", i, sum);
     		sum += fib2;
     		int tmp = fib1;
     		fib1 = fib2;
     		fib2 += tmp;
     }
	printf("Окончание работы\n");
    return 0;
}
