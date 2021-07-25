#include<bits/stdc++.h>
using namespace std;

int func(int n, int m, int k){
	int ans = 0;
	if(m == 0 || n == 0){
		return ans;
	}
	if(n==m){
		for(int i=1;i<=n;i++){
			ans = ans ^ (k+2*i);
		}
	}
	else if(n<m){
		int a = m/n;
		for(int i=0;i<a;i++){
			for(int j=1;j<=n;j++){
				ans = ans ^ (k+j+((i*n)+j));
			}
		}
		int b = m%n;
		ans = ans ^ func(n , b, k+(a*n));
	}else{
		swap(m,n);
		int a = m/n;
		for(int i=0;i<a;i++){
			for(int j=1;j<=n;j++){
				ans = ans ^ (k+j+((i*n)+j));
			}
		}
		int b = m%n;
		ans = ans ^ func(n , b, k+(a*n));
	}
	return ans;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n, m, k;
		cin>>n>>m>>k;
		int ans = func(n,m,k);
		cout<<ans<<endl;
	}
	
	return 0;
}
