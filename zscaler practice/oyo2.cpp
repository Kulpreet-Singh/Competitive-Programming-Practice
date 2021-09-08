#include <bits/stdc++.h>
using namespace std;

int minNext(vector<int> weight, vector<bool> visited, int V){
	int min=-1;
    for(int i=0;i<V;i++){
        if(!visited[i] && (min==-1 || (weight[i] < weight[min])) ){
            min = i;
        }
    }
    return min;
}

int dijkstra(vector< vector<int> > edges, int V){
    vector<int> weight(V,INT_MAX);
    vector<bool> visited(V,false);
    int cv = 0;
	weight[cv] = 0;     
    while(cv!=-1){    
        visited[cv] = true;
        for(int i=0;i<V;i++){
            if(!visited[i] && edges[cv][i]!=0 && weight[cv]+edges[cv][i]<weight[i]){
                weight[i] = weight[cv]+edges[cv][i];
            }
        }
        cv = minNext(weight,visited,V);
	}
    return weight[V-1];
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n, m;
		cin>>n>>m;
		vector< vector<int> > edges(n,vector<int>(n,0));
		for(int i=0;i<m;i++){
			int x, y;
			cin>>x>>y;
			edges[x-1][y-1] = 1;
			edges[y-1][x-1] = 1;	
		}
		cout<< dijkstra(edges, n) << "\n";
	}
	
	return 0;
}
