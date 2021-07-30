#include <bits/stdc++.h>
using namespace std;

int findMax(int *a,int n,int k1, int k2, int***dp){
    if(n==0){
        if(k1>0 || k2>0){
            return -10000;
        }
    }
    if(k1<0 || k2<0){
        return -10000;
    }
    if(k1==0 && k2 == 0){
        return 0;
    }
    if(dp[n][k1][k2]>-20000){
        return dp[n][k1][k2];
    }
    int option1=-10000,option2=-10000,option3=-10000;
    if(k1==k2){
    	option1 = findMax(a,n-1,k1,k2-1,dp) + a[n-1];
		option1 = max(option1,findMax(a,n,k1,k2-1,dp) + a[n-1]);        
    }
    if(k1>k2){
    	option2 = findMax(a,n-1,k1-1,k2,dp) - a[n-1];
        option2 = max(option2,findMax(a,n,k1-1,k2,dp) - a[n-1]);
    }
    option3 = findMax(a,n-1,k1,k2,dp);
    int ans = max(option1,max(option2,option3));
    dp[n][k1][k2] = ans;
    return ans;
}

int main()
{	
    int t;
    cin>>t;
    while(t--){
        int k,n;
        cin>>k>>n;
        int * a = new int[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int ***dp = new int **[n+1];
        for(int i=0;i<=n;i++){
           dp[i] = new int *[k+1];
            for(int j=0;j<=k;j++){
                dp[i][j] = new int[k+1];
                for(int l=0;l<=k;l++){
                    dp[i][j][l] = -20000;
                }
            }
        }
        int ans = findMax(a,n,k,k,dp);
        cout<<ans<<endl;
		
        for(int i=0;i<=n;i++){
            for(int j=0;j<=k;j++){
                delete[] dp[i][j];
                
            }
            delete[] dp[i];
        }
        delete[] dp;
        delete[] a;
    }
        
    return 0;
}

