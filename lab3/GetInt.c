#include <stdio.h>

int GetInt(int *a){
	int n;
	while ((n=scanf("%d", a)) != 1){
		scanf("%*[^\n]");
		scanf("%*c");
	}
	return n==1;
}
