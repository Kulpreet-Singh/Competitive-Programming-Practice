#include<iostream>
using namespace std;

int main(){
	int n,m,x,in;
	long int y;
	long long int max;
	cin>>n>>m;
	long long int *a=new long long int[n];
	int *f = new int[n];
	for(int i=0;i<n;i++){
		a[i]=0;
		f[i]=0;
	}
	for(int i=0;i<m;i++){
		cin>>x>>y;
		f[x-1]=1;
		a[x-1]+=y;		
	}
	for(int i=0;i<n;i++){
		if(f[i]!=0){
			max=a[i];
			in=i;
			break;
		}
	}
	for(int i=0;i<n;i++){
		if(f[i]!=0){
			if(a[i]>max){
				max=a[i];
				in=i;
			}
		}
	}
	cout<<in+1<<endl;
	return 0;
}
