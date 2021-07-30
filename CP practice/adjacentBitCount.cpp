#include <bits/stdc++.h>
using namespace std;

#define m 1000000007
int helper(int n,int k,int firstBit,int ***dp){
    if(n==1){
        if(k==0){
            return 1;
        }
        if(k>0){
            return 0;
        }
        
    }
    if(k<0){
        return 0;
    }
    if(dp[n][k][firstBit]>-1){
        return dp[n][k][firstBit];
    }
    long ans;
    if(firstBit == 1){
        ans = helper(n-1,k,0,dp)+helper(n-1,k-1,1,dp);
    }
    if(firstBit == 0){
        ans = helper(n-1,k,0,dp)+helper(n-1,k,1,dp);
    }
    dp[n][k][firstBit] = ans%m;
    return ans%m;
}

int main()
{	
    int p;
    cin>>p;
    int ***dp = new int**[101];
    for(int i=0;i<101;i++){
        dp[i] = new int*[101];
        for(int j=0;j<101;j++){
            dp[i][j] = new int[2];
            for(int l=0;l<2;l++){
                dp[i][j][l] = -1;
            }
        }
    }
    while(p--){
        int q;
        int n;
        int k;
        cin>>q>>n>>k;
        long ans = helper(n,k,0,dp) + helper(n,k,1,dp);
    	cout<<q<<" "<<ans%m<<endl;
        
    }
    for(int i=0;i<101;i++){
        for(int j=0;j<101;j++){
            delete[] dp[i][j];
        }
        delete[] dp[i];
    }
    delete[] dp;
    return 0;
}

