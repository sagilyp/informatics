   #include <stdio.h>                                                                                                             
   #include <stdlib.h>            
                                                                                                                                          
 void func(float a,float y0, int n, float delta, int *p){                                                                                         
     int i, l;                                                                                                                                
     float y1, tmp, d ;                                                                                                                          
     do{                                                                                                                     
         tmp = y0;               // цикл возведения                                                                                          
         for(l=1;l<n;l++){       // числа y0 в                                                                                               
             y0=y0*tmp;          // степень n                                                                                                
         }                                                                                                                                   
         //printf("%f\n",y0);                                                                                                                
         y1 = (tmp/(n*n))*(((n*n)-1.0)+0.5*(n+1.0)*(a/y0)-0.5*(n-1.0)*(y0/a));
         d = tmp - y1;                                                               
         y0 = y1;
         *p = *p + 1;                                                                                                                                 
     }           
     while (!((d < delta) && ( d > -delta)));                                                                                                                            
     printf("Результат вычислений равен : %f\n", y0);                                                                                         
     printf("В процессе вычислений с указанной точностью было произведено %d итераций\n", *p );                                                                                                                                         
 }                                                                                                                                            
                                                                                                                                             
                                                                                                                                             
                                                                                                                                             
 int main(){                                                                                                                                 
     int  x, r = 0;
     int *j = &r;                                                                                                                               
     float  y, t, z;                                                                                                                            
     printf("Введите степень радикала n : \n");                                                                                              
     scanf("%d", &x);                                                                                                                         
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
     printf("Введите желаемую точность вычислений :\n");
     scanf("%f", &z);
     func(y,t,x,z,j);
     return 0;
 }
