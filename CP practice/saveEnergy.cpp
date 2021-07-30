#include<bits/stdc++.h>
using namespace std;
//greedy approach
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int i=0;
	int j=1;
	int cost =0;
	while(j<n-1){
		if((abs(a[i])>abs(a[j])) || (a[i] == abs(a[j]))){
			cost += (j-i)*a[i] + (j*j - i*i) * a[i]*a[i];
			i=j;
		}
		j++;
	}
	cost += (j-i)*a[i] + (j*j - i*i) * a[i]*a[i];
	
	cout<<cost<<endl;		
}
