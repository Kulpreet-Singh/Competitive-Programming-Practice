#include <bits/stdc++.h>
using namespace std;

int gcd(int dividend,int divisor){
    if(dividend%divisor == 0){
        return divisor;
    }
    return gcd(divisor,dividend%divisor);
}

// int findSubs(int n,int a[],int *dp){
//     if(n==0){
//         return 1;
//         dp[n][a[n]] += 1;
//     }
//     if(dp[n]>0){
//         return dp[n];
//     }
//     int output = 1;
//     int k = n;
//     for(int i=n-1;i>0;i--){
        
//     }
// }

int main()
{
	cout<<gcd(4,6);
//    int n;
//    cin>>n;
//    int a[n];
//    for(int i=0;i<n;i++){
//        cin>>a[i];
//    }
//    int ** dp = new int*[n];
//    for(int i=0;i<n;i++){
//        dp[i] = new int[101];
//        for(int j=0;j<101;j++){
//            dp[i][j] = 0;
//        }
//    }
//    dp[0][a[0]] = 1;
//    for(int i=1;i<n;i++){
//        for(int j=i-1;j>=0;j--){
//        	if(a[i]>a[j]){
//                for(int k=1;k<101;k++){
//                    if(dp[j][k]!=0)
//                    	dp[i][gcd(max(a[i],k),min(a[i],k))]+=1;
//                }
//            }
//        }
//    }
//    long count=0;
//    for(int i=0;i<n;i++){
//        count+=dp[i][1];
//    }
//    int ans = count%1000000007;
//    cout<<ans<<endl;
//    for(int i=0;i<n;i++){
//        delete[] dp[i];
//    }
//    delete[] dp;
    return 0;
}

