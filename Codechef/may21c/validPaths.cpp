#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

typedef long long ll;

ll validPaths(vector<vector<int> > &graph, vector<bool> &visited, int src, ll &res, ll val){
	visited[src] = true;
	ll ans = 0;
	for(int i=0;i<graph[src].size(); i++){
		if(!visited[graph[src][i]]){
			ll temp = validPaths(graph, visited, graph[src][i], res, ((val*2)%mod + ans)%mod);
			ans += (2*temp)%mod;
			ans = ans%mod;
		}
	}
	res = (res + val)%mod;
	return (ans+1)%mod;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<vector<int> > graph(n+1, vector<int>());
		vector<bool> visited(n+1, 0);
		for(int i=1; i<n; i++){
			int u, v;
			cin>>u>>v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		ll res = 0;
		ll ans = validPaths(graph, visited, 1, res, 0);
		ans = (ans+res)%mod;
		cout<<ans<<endl;
	}
}
