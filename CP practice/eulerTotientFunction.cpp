#include<bits/stdc++.h>
using namespace std;

vector<int> eulerTotient(int n){
	vector<int> phi(n+1, 0);
	for(int i=0;i<=n;i++){
		phi[i] = i;
	}
	for(int i=2;2*i<=n;i++){
		if(phi[i] == i){
			for(int j=i;j<=n;j+=i){
				phi[j] *= (i-1);
				phi[j] /= i;
			}
		}
		
	}
	return phi;
}

int main(){
	int n;
	cin>>n;
	vector<int> phi = eulerTotient(n);
	
	for(int i=0;i<=n;i++){
		cout<<phi[i]<<" ";
	}
	cout<<endl;
	return 0;
}
