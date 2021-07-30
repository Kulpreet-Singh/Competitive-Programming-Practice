#include <bits/stdc++.h>
using namespace std;

void DFS(vector<vector<bool>> edges, int V,int sv, vector<bool> &visited){
    visited[sv] = true;
    for(int i=0;i<V;i++){
        if(sv!=i){
            if(!visited[i] && edges[sv][i]){
                DFS(edges,V,i,visited);
            }
        }
    }
}

vector<int> BFS(vector<vector<bool>> edges, int V,int sv, vector<bool> &visited){
    queue<int> q;
    vector<int> v;
    q.push(sv);
    visited[sv] = true;
    while(!q.empty()){
        int cv = q.front();
        v.push_back(cv);
        q.pop();
        for(int i=0;i<V;i++){
            if(cv!=i && !visited[i] && edges[cv][i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
    return v;
}

vector<vector<int>> allConnected(vector<vector<bool>> edges, int V){
    vector<bool> visited(V,false);
	vector<vector<int>> v;
    for(int i=0;i<V;i++){
        if(!visited[i]){
            vector<int> v1 = BFS(edges,V,i,visited);
            sort(v1.begin(),v1.end());
            v.push_back(v1);
        }
    }
    return v;
}

int main() {
    int V, E;
    cin >> V >> E;
    
	vector<vector<bool>> edges(V,vector<bool>(V,false));
    for(int i=0;i<E;i++){
        int x,y;
        cin>>x>>y;
        edges[x][y] = edges[y][x] = true;
    }
    vector<vector<int>> v = allConnected(edges,V);
	for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

