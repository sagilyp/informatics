#include "mystring.h"
 #include <stdlib.h>
 #include <string.h>
 
 #define DELIM " \t"
 
 char* del_spc(char *str){
     char *s, *res, *word;
     s  = strdup(str);
     int s_len, len = 0;
     s_len = strlen(s);
     res = calloc(s_len + 1, sizeof(char));
     word = strtok(str,DELIM);
     while (word != NULL){
         int w_len;
         w_len = strlen(word);
         if (w_len > 0){
             memcpy(res + len, word, w_len * sizeof(char));
             len += w_len;
             res[len] = ' ';
             ++len;
         }
         word = strtok(NULL, DELIM);
     }
     free(s);
     if (len > 0){
         --len;
     }
     res[len] = '\0';
     res = realloc(res, (len + 1) * sizeof(char));
     return res;
 }
