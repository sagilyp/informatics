#include <stdio.h>
#include <stdlib.h>

int main(){
 	int x=1, b, k; 
	while (x!=0){
  	  printf("Введите целое число:");
	  scanf("%d",&x);
	  int a=x;	 
	  if (a<0)
		 a=-a;
 	  b=0;
 	  k=1;
  	  do{
     	  int z = a % 2;
    	  b = z*k + b;
          a = a/2;
    	  k = k*10;
    	}
       while (a>1);
       if (a == 1)
    	{
           b = 1*k+b;
        }
       else
    	{
           b = 0*k+b;
        }
       if (x<0)
           b=-b;
       printf("%d\n",b);
       printf("Введите ноль, если хотите завершить программу. Введите любое другое целое число, если хотите продолжить \n");
       scanf("%d",&x);
   	}
    printf("Завершение работы программы.\n");   	
    return 0;
}
