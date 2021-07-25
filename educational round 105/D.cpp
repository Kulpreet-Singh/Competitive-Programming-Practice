#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector< vector<int> > v(vector<int> (n, 0));
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>v[i][j];
			}
		}
		vector<int> a; 
		for(int i=0;i<n;i++){
			a.push_back(v[i][i]);
		
		}
	}
	
	return 0;
}
