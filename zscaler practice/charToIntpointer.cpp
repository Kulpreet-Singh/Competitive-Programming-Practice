#include<stdio.h>

int main(){
	int x = 2; 
	int *ptr = &x; 
	printf(“%d”, *((char*) ptr));
	return 0;
}
