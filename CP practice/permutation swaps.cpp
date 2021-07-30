#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>
using namespace std;

void dfs(int start, vector<vector<bool> > edges, int n, unordered_set <int> &visited, unordered_set<int>* component){
    visited.insert(start);
    component->insert(start);
    for(int i=0;i<n;i++){
        if(!(visited.count(i)>0) && edges[start][i]){
            dfs(i,edges,n,visited,component);
        }
    }
}

void bfs(int start, vector<vector<bool>> edges, int n, unordered_set<int> &visited, unordered_set<int>* component){
    queue<int> q;
    q.push(start);
    visited.insert(start);
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        component->insert(curr);
        for(int i=0;i<n;i++){
            if(!(visited.count(i)>0) && edges[curr][i]){
                q.push(i);
    			visited.insert(i);
            }
        }
    }
}

unordered_set<unordered_set<int>* >* getComponents(vector<vector<bool>> edges, int n){
    unordered_set<int> visited;
    unordered_set <unordered_set <int>* >* output = new unordered_set<unordered_set <int>*>();
    for(int i=0;i<n;i++){
        if(visited.count(i) == 0){
            unordered_set <int>* component = new unordered_set <int>();
            bfs(i,edges,n,visited,component);
            output->insert(component);
        }
    }
    return output;
}


int main()
{
	//code
    int t;
    cin>>t;
    while(t--){
        int  n,m;
        cin>>n>>m;
        vector<int> p(n);
        vector<int> q(n);
        vector<vector<bool> > edges(n,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            cin>>p[i];
        }
        for(int i=0;i<n;i++){
            cin>>q[i];
        }
        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            x--;
            y--;
            edges[x][y] = edges[y][x] = true;
        }
        int flag = 0;
        unordered_set <unordered_set <int>* >* components = getComponents(edges,n);
        unordered_set <unordered_set <int>* >::iterator it = components->begin();
        while(it!=components->end()){
            unordered_set <int>* component = *it;
            unordered_set <int>* valP = new unordered_set <int>();
            unordered_set <int>::iterator it2 =  component->begin();
            while(it2!=component->end()){
                valP->insert(p[*it2]);
                it2++;
            }
            it2 = component->begin();
            while(it2!=component->end()){
                if(valP->count(q[*it2]) == 0){
                    flag = 1;
                    break;
                }
                it2++;
            }
            if(flag == 1){
                break;
            }
            it++;
            delete component;
            delete valP;
        }
        delete components;
        if(flag == 1){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }
    }
	return 0;
}
