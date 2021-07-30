#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

int countSubs(char* a,int n, int* dp, long &penalty){
    if(n==0){
        return 1;
    }
    dp[a[0]-'A']+=1;
     long count = 2 * countSubs(a+1,n-1,dp,penalty);
    	count = count%mod;
    if(dp[a[0]-'A']>1){
        penalty+=count/2;
        dp[a[0]-'A']-=1;
    }
    else
    	dp[a[0]-'A']-=1;
    return count;
}



int main()
{
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n = s.length();
        char *a= new char[n+1];
        for(int i=0;i<=n;i++){
            a[i] = s[i];
        }
        int *dp =  new int[26];
        for(int i=0;i<26;i++){
            dp[i]=0;
        }
        long penalty =0;
        long ans = countSubs(a,n,dp,penalty);
        cout<<ans-penalty<<endl;
        delete[] a;
        delete[] dp;
    }
    return 0;
}

