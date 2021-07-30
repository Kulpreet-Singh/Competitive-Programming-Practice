#include<bits/stdc++.h>
using namespace std;

void swap(char &x, char &y){
	char temp = x;
	x=y;
	y=temp;
}
void flip(char &x){
	if(x=='0'){
		x='1';
	}else{
		x='0';
	}
}

int main(){
	int n;
	cin>>n;
	string a,b;
	cin>>a>>b;
	int cost=0;
	for(int i=0;i<n;i++){
		if(a[i]!=b[i]){
			if(a[i+1]!=a[i] && a[i+1]!=b[i+1] && i<(n-1)){
				swap(a[i+1],a[i]);
				cost++;
				i++;
			}
			else{
				flip(a[i]);
				cost++;
			}
		}
	}
	cout<<cost<<endl;	
}
