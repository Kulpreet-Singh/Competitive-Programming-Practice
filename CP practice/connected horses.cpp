#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

void dfs(int start, vector<int>* edges, int n, unordered_set<int> &visited, int &count){
    visited.insert(start);
	count++;
    for(int i=0;i<edges[start].size();i++){
        if(!(visited.count(edges[start][i])>0)){
            dfs(edges[start][i],edges,n,visited,count);
        }
    }
}
vector<int> getComponents(vector<int>* edges, int n) {
	unordered_set<int> visited;
	vector<int> output;
	for (int i = 0; i < n; i++) {
		if (visited.count(i) == 0) {
			int count = 0;
			dfs(i, edges,n, visited, count);
			output.push_back(count);
		}
	}
	return output;
}
long long int fact(long long int n){
    if(n==0 || n==1){
        return 1;
    }
    return (n*fact(n-1))%mod;
}

int main()
{
	//code
    int t;
    cin>>t;
    while(t--){
        int n,m,q;
        cin>>n>>m>>q;
        vector<int>* edges = new vector<int>[n*m];
        vector<vector<bool>> horse(n,vector<bool>(m,false));
        for(int i=0;i<q;i++){
            int x,y;
            cin>>x>>y;
            x--;
            y--;
            horse[x][y] = true;
            if(x-2>=0){
                if(y-1>=0 && horse[x-2][y-1]){
                    edges[m*x + y].push_back(m*(x-2)+y-1);
                    edges[m*(x-2)+y-1].push_back(m*x + y);
                }
                if(y+1<m && horse[x-2][y+1]){
                    edges[m*x + y].push_back(m*(x-2)+y+1);
                    edges[m*(x-2)+y+1].push_back(m*x + y);
                }
            }
            if(x-1>=0){
                if(y-2>=0 && horse[x-1][y-2]){
                    edges[m*x + y].push_back(m*(x-1)+y-2);
                    edges[m*(x-1)+y-2].push_back(m*x + y);
                }
                if(y+2<m && horse[x-1][y+2]){
                    edges[m*x + y].push_back(m*(x-1)+y+2);
                    edges[m*(x-1)+y+2].push_back(m*x + y);
                }
            }
            if(x+1<n){
                if(y-2>=0 && horse[x+1][y-2]){
                    edges[m*x + y].push_back(m*(x+1)+y-2);
                    edges[m*(x+1)+y-2].push_back(m*x + y);
                }
                if(y+2<m && horse[x+1][y+2]){
                    edges[m*x + y].push_back(m*(x+1)+y+2);
                    edges[m*(x+1)+y+2].push_back(m*x + y);
                }
            }
            if(x+2<n){
                if(y-1>=0 && horse[x+2][y-1]){
                    edges[m*x + y].push_back(m*(x+2)+y-1);
                    edges[m*(x+2)+y-1].push_back(m*x + y);
                }
                if(y+1<m && horse[x+2][y+1]){
                    edges[m*x + y].push_back(m*(x+2)+y+1);
                    edges[m*(x+2)+y+1].push_back(m*x + y);
                }
            }
        }
        long long int ans = 1;
        vector<int> counts = getComponents(edges,n*m);
        vector<int>::iterator it = counts.begin();
        while(it!=counts.end()){
            long long int c = *it;
            c = c%mod;
            ans = (ans * fact(c))%mod;
            it++;
        }
        cout<<ans<<endl;
    }
	return 0;
}

