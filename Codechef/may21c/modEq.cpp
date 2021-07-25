#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n, m;
		cin>>n>>m;
		ll ans = 0;
		vector<ll> pairs(n+1, 1);
		for( ll a=2; a<=n; a++){
			ll x = m%a;
			ans += pairs[x];
			for (ll b=x; b<=n; b+=a)
				pairs[b]++;
		}
		cout<<ans<<endl;
	}
}
