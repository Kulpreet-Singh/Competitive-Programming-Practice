#include<stdio.h>
void main(){
	for(int j=0;j<5;j*=3){
		if(j==2 || j%3==1)
			break;
			else
				printf("%d", j+1);
				
				
	}
}
