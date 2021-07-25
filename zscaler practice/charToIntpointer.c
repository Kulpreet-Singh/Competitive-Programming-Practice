#include<stdio.h>

int main(){
	int x = 2; 
	int *ptr = &x; 
	printf("%d", *((char*) ptr));
	
	char str[5] = "Hell"; 
	str[4] = 'o'; 
	printf("%s", str);
	return 0;
}
