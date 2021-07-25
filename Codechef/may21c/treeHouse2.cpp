#include<bits/stdc++.h>
using namespace std;

#define ll  long long
const ll  mod = 1e9+7;

vector<vector<ll> > sol;
vector<ll> temp, temp2;
vector<pair<ll , ll > > ch;

void depthfirstsearch(ll  begg, ll  enddd)
{
	for(auto x:sol[begg]){
		if (x==enddd) 
			continue;
		depthfirstsearch(x,begg);
	}
	
	ch.clear();
	for(auto x:sol[begg]){
		if (x!=enddd) 
			ch.push_back({temp[x],x});
	}
	sort(ch.rbegin(), ch.rend());
	ll  tol= 1;
	for(auto [val, id]: ch) 
		temp2[id]+=tol++;
	for (auto x:sol[begg]){
		if (x!=enddd){
			temp[begg] +=temp2[x] * temp[x];
		}
	}
}


int main(){
	int t;
	cin>>t;

	while(t--){
		ll n,x;
		cin>>n>>x;
		temp.assign(n,1);
		temp2.assign(n,0);

		sol.clear();
		sol.resize(n);

		while(n--){
			ll  u,v;
			cin>>u>>v;
			u=u-1;
			v=v-1;
			sol[u].push_back(v);
			sol[v].push_back(u);
		}
		
		depthfirstsearch(0,-1);
		
		ll answer= temp[0]%mod * x%mod;
		cout<<answer<<endl;
    
}
return 0;
}
