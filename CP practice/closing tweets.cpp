#include<iostream>
using namespace std;

int main(){
	int n,k;
	int count=0;
	cin>>n>>k;
	int x=0;
	char str[20];
	int *a=new int[n];
	for(int i=0;i<n;i++){
		a[i]=0;
	}
	cin.ignore();
	for(int i=0;i<k;i++){
		
		gets(str);
//		cout<<"input is: "<<str;
		if(str[2]=='O'){
			count=0;
			for(int i=0;i<n;i++){
		a[i]=0;
	}
			cout<<count<<endl;
		}
		else{
			x=0;
			for(int j=6;str[j]!='\0';j++){
//				cout<<"j value"<<str[j];
				x=x*10+(str[j]-'0');
			}
//			cout<<"pos"<<x<<endl;
			if(a[x-1]==0){
				count++;
				a[x-1]=1;
				cout<<count<<endl;
			}
			else if(a[x-1]==1){
				count--;
				a[x-1]=0;
				cout<<count<<endl;
			}
		}
	}
	return 0;
}
