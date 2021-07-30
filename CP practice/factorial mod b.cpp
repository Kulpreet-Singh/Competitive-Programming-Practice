#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int t;
	cin>>t;
	while(t--){
		ll a,b;
		cin>>a>>b;
		if(a>=b){
			cout<<0<<endl;
		}
		else{
			ll rem = 1;
			for(int i = 2;i<=a;i++){
				rem = (((rem)%b) * (i%b))%b;
				if(rem == 0){
					break;
				}
			}
			cout<<rem<<endl;
		}
		
	}
}

//4 8 10 5 140 18 19 20 21 
