#include<bits/stdc++.h>
using namespace std;

int findPlayer(int *p, int n, int k){
	int turn=-1;
	
	for(int i=0;i<n;i++){
		if(p[i]<k && ((k%p[i])==0)){
			if(p[i]>turn){
				turn = p[i];
			} 
		}
	}
	
	return turn;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int *p = new int[n];
		for(int i=0;i<n;i++){
			cin>>p[i];
		}
		int ans = findPlayer(p,n,k);
		cout<<ans<<endl;
		delete[] p;
	}
}
