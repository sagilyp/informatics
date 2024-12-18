#include <stdio.h>


void func(float a,float y0, float n, int row){
    int i, l;
    float y1, tmp ;
    for(i=0;i<row;i++){
        tmp = y0;               // цикл возведения
    	for(l=1;l<n;l++){       // числа y0 в 
    		y0=y0*tmp;          // степень n
    	}  
	    y1 = (tmp/(n*n))*(((n*n)-1.0)+0.5*(n+1.0)*(a/y0)-0.5*(n-1.0)*(y0/a));	 
	    y0 = y1;
//	    printf("%f\n", y0); 
	}    
    printf("Результат вычислений равен : %f\n", y0);    
    
}



int main(){
    int z;
    float x, y, t;  
	printf("Введите степень радикала n : \n");
	scanf("%f", &x);
	printf("Введите число а для вычисления :\n");
	scanf("%f", &y);
	printf("Введите начальный член для расчётов меньший, чем число a :\n");
	do{
	    scanf("%f", &t);
	    	if(t >= y){
	    		 printf("Ошибка! Введите число меньшее, чем число a :\n");
	    	}
	    }    
	while(t >= y);  
    printf("Введите желаемое количество итераций :\n");
    scanf("%d", &z);
    func(y,t,x,z);
    return 0;
}
