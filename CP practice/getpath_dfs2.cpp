#include <bits/stdc++.h>
using namespace std;

void getpath(const vector<vector<bool>> &am, int n, int x, int y, vector<bool> &visited, vector<int> &ans,bool &found){
    visited[x] = true;
	if(x == y){
        //ans.push_back(x);
        found = true;
        return ;
    }
    for(int i=0;i<n;i++){
        if(am[x][i] and !visited[i]){
           
            if(!found) 
            	getpath(am,n,i,y,visited, ans, found);
            if(found){
                ans.push_back(i);
            	return;
            }
        }
    }
}


int main()
{
  int V, E, tempX, tempY;
  cin >> V >> E;

  vector<vector<bool>> am(V,vector<bool>(V, false));
    
	while(E--){
        int i,j;
        cin>>i>>j;
        am[i][j] = am[j][i] = true;
    }
    int t,d;
    cin>>t>>d;
    vector<bool> visited(V,false);
    vector<int> ans; 
    bool found{false};
	getpath(am,V,t,d,visited, ans, found);
    if(found) ans.push_back(t);
    for(int i: ans) cout<<i<<" ";
 
  return 0;
}
