#include<bits/stdc++.h>
using namespace std;

/*
1 0 0 1 0 0 0 1 
0 1 0 0 0 1 1 1 
1 1 0 0 0 0 0 0
0 0 1 1 0 0 0 0
0  0 0 0 1 1 0 0

No of Distinct islands - > 4
*/


void dfs(int a[][8], int m, int n, int start_i, int start_j,int rel_i, int rel_j, bool visited[][8], string &curr){
	if(start_i + rel_i < m && start_i + rel_i >=0 && start_j + rel_j < n && start_j + rel_j >=0 ){
		if(!visited[start_i + rel_i][start_j + rel_j]){
			visited[start_i + rel_i][start_j + rel_j] = true;
			
			if(start_i + rel_i-1 < m && start_i + rel_i-1 >=0 && start_j + rel_j < n && start_j + rel_j >=0 )
				dfs(a, m, n, start_i, start_j, rel_i-1, rel_j, visited, curr+"U");
			
			if(start_i + rel_i < m && start_i + rel_i >=0 && start_j + rel_j-1 < n && start_j + rel_j-1 >=0 )
				dfs(a, m, n, start_i, start_j, rel_i, rel_j-1, visited, curr+"L");
			
			if(start_i + rel_i+1 < m && start_i + rel_i+1 >=0 && start_j + rel_j < n && start_j + rel_j >=0 )
				dfs(a, m, n, start_i, start_j, rel_i+1, rel_j, visited, curr+"D");
				
			if(start_i + rel_i < m && start_i + rel_i >=0 && start_j + rel_j+1 < n && start_j + rel_j+1 >=0 )
				dfs(a, m, n, start_i, start_j, rel_i, rel_j+1, visited, curr+"R");
		}
	}
}


int main(){
	int a[][8] = {
					{1, 0, 0, 1, 0, 0, 0, 1},			 
					{ 0, 1, 0, 0, 0, 1, 1, 1 },
					{ 1, 1, 0, 0, 0, 0, 0, 0},
					{0, 0, 1, 1, 0, 0, 0, 0	},
					{0, 0, 0, 0, 1, 1, 0, 0}
		};
	bool visited[5][8] = {0};
	set<string> v;
	int m = 5;
	int n = 8;
	
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			string curr = "S";
			if(!visited[i][j] && a[i][j]==1){
				dfs(a, m, n, i, j, 0, 0, visited, curr);
				if(v.find(curr) == v.end()){
					v.insert(curr);
				}
			}
		}
	}
	cout<<v.size()<<endl;
}
