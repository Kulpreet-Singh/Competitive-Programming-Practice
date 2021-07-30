#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll helper(int n, int mask, vector<vector<ll> > &v,ll* dp){
	if(mask == (1<<(n))-2){
		return 1;
	}
    if(dp[mask] != -1){
        return dp[mask];
    }
    ll count = 0;
    for(int i=1;i<n;i++){
    	int flag = 0;
        if(!(mask&(1<<i))){
            for(int j=0;j<v[i].size();j++){
                if(!(mask&(1<<v[i][j]))){
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){
                count+=helper(n,mask|(1<<i),v,dp);
            } 
        }
        
    }
    dp[mask] = count;
    return count;
	
}

int main(){
	int n;
	cin>>n;
	vector<vector<ll> > v(n+1);
	
	long long* dp = new long long[(1<<(n+1))]; 
    for(int i=0;i<=(1<<(n+1))-1;i++){
        dp[i] = -1;
    }
	
	for(int i=1;i<=n;i++){
		for(int j=i-1;j>0;j--){
			if((j&i) == j){
				v[i].push_back(j);
			}
		}
	}
	
	ll ans = helper(n+1,0,v,dp);
	cout<<ans <<endl;
	delete[] dp;

	return 0;
}
