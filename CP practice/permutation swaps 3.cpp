#include<bits/stdc++.h>
using namespace std;

int topParent(vector<int> parent, int i){
    if(parent[i] == i){
        return i;
    }
    return topParent(parent,parent[i]);
}

void dfs(int start, vector<vector<int>> edges, int n, unordered_set<int> &visited, unordered_set<int>* component){
    visited.insert(start);
    component->insert(start);
    for(int i=0;i<edges[start].size();i++){
        if(!(visited.count(edges[start][i])>0)){
            dfs(edges[start][i],edges,n,visited,component);
        }
    }
}

void bfs(int start, vector<vector<int>> edges, int n, unordered_set<int> &visited, unordered_set<int>* component){
    queue<int> q;
    q.push(start);
    visited.insert(start);
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        component->insert(curr);
        for(int i=0;i<edges[curr].size();i++){
            if(!(visited.count(edges[curr][i])>0)){
                q.push(edges[curr][i]);
    			visited.insert(edges[curr][i]);
            }
        }
    }
}

// unordered_set<unordered_set<int>*>* getComponents(vector<vector<int>> edges, int n){
//     unordered_set<int> visited;
//     unordered_set<unordered_set<int>*>* output = new unordered_set<unordered_set<int>*>();
//     for(int i=0;i<n;i++){
//         if(visited.count(i) == 0){
//             unordered_set<int>* component = new unordered_set<int>();
//             bfs(i,edges,n,visited,component);
//             output->insert(component);
//         }
//     }
//     return output;
// }

unordered_set<unordered_set<int>*>* getComponents(vector<pair<int,int>> edges, int n){
    vector<int> parent(n,0);
    for(int i=0;i<n;i++){
        parent[i] = i;
    }
    unordered_set<unordered_set<int>*>* output = new unordered_set<unordered_set<int>*>();
    for(int i=0;i<edges.size();i++){
        if(topParent(parent,edges[i].first) != topParent(parent,edges[i].second)){
            parent[topParent(parent,edges[i].second)] = topParent(parent,edges[i].first);
        }
    }
    vector<unordered_set<int>*> component(n,NULL);
    for(int i=0;i<n;i++){
        if(component[topParent(parent,i)]==NULL){
            unordered_set<int>* temp = new unordered_set<int>();
            temp->insert(i);
            component[topParent(parent,i)] = temp;
        }
        else{
        	component[topParent(parent,i)]->insert(i);    
        }
    }
    auto it = component.begin();
    for(;it!=component.end();it++){
        if(!(*it  == NULL)){
        	output->insert(*it);     
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
        // vector<vector<int>> edges(n,vector<int>());
        vector<pair<int,int>> edges;
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
            // edges[x].push_back(y);
            // edges[y].push_back(x);
            edges.push_back(make_pair(x,y));
        }
        int flag = 0;
       
        unordered_set<unordered_set<int>*>* components = getComponents(edges,n);
        unordered_set<unordered_set<int>*>::iterator it = components->begin();
        while(it!=components->end()){
            unordered_set<int>* component = *it;
            unordered_set<int>* valP = new unordered_set<int>();
            unordered_set<int>::iterator it2 =  component->begin();
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

