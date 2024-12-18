#include <stdlib.h>
#include <string.h>
#include "mystring.h"

#define DELIM " \t"

char *ind(char *str1){
    char *s1, *res1, *word1;
    s1 = strdup(str1);
    int s_len1, c;
    s_len1 = strlen(s1);
    c = s_len1;
    res1 = calloc(s_len1 + 1, sizeof(char));
    word1 = strtok(str1, DELIM);
    while (word1 != NULL){
        int w_len;
        w_len = strlen(word1);
        if (w_len > 0){
            s_len1 -= w_len;
            memcpy(res1 + s_len1, word1, w_len * sizeof(char));
            if (s_len1 != 0){
            	--s_len1;
            	res1[s_len1] = ' ';
            }
        }
        word1 = strtok(NULL, DELIM);
    }
    free(s1);
    if (s_len1 > 0){
        --s_len1;
    }
    res1[c] = '\0';
    return res1;

}
