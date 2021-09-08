#include<bits/stdc++.h>
using namespace std;

bool check(string s1, string s2){
	int n1 = s1.length();
	int n2 = s2.length();
	if(n1!=n2) {
		return false;	
	}
	int flag = 0;
	for(int i=0;i<n1;i++){
		if(s1[i]!=s2[i]){
			if(!flag){
				flag =  1;
			}
			else{
				return false;
			}
		}
	}
	if(!flag)
		return false;
	return true;
}

int main(){
	int n;
	cin>>n;
	vector<string> v(n);
	vector<bool> visited(n, false);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	queue<int> q;
	for(int i=0;i<n;i++){
		if(!visited[i]){
			q.push(i);
			visited[i] = true;
		}
		while(!q.empty()){
			int curr = q.front();
			q.pop();
			cout<<v[curr]<<" ";
			for(int i=0;i<n;i++){
				if(!visited[i]){
					if(check(v[curr], v[i])){
						q.push(i);
						visited[i]=true;
					}
				}
			}
		}
		cout<<"\n";
	}
	
	return 0;
}
