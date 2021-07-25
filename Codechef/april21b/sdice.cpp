#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		ll a = n/4;
		ll b = n%4;
		ll sum = a * 44;
		if(a!=0){
			sum += ((4-b)*4);
		}
		if(b == 1){
			sum+=20;
		}else if(b==2){
			sum+=36;
		}else if(b==3){
			sum+=51;
		}
		cout<<sum<<endl;
	}
}
