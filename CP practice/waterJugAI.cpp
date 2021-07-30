#include<iostream>
using namespace std;

int main(){
	int x = 0;
	int y=0;
	while(!(x==2 && y==0)){
		cout<<"x: "<<x<<",y: "<<y<<endl; 
		if(x!=2 && y==0){
			y=3;
		}
		else if(x==0){
			x = y;
			y = 0;
		}
		else if(x!=0 && y==0){
			y=3;
		}
		else if(x+y>=4 && y!=0){
			x=4;
			y=(y-(4-x));
		}
		
		if(x==4){
			x=0;
		}
	}
	cout<<"x: "<<x<<",y: "<<y<<endl;
}
