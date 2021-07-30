#include <iostream>
using namespace std;

// long long getPermutations(int n, long long mask,long long* dp){
//     for(mask=0;mask<(1<<n);mask++){
//         for(int i=0;i<n;i++){
//             if(!(mask&(1<<i))){
// 		        int flag = 0;
//                 for(int k = i-1;k>=0;k--){
//                     if(k!=i && !(mask&(1<<k)) && (k+1)&(i+1) == (k+1)){
//                         flag = 1;
//                         break;
//                     }
//                 }
//             	if(flag ==  0){
//                     dp[mask|(1<<i)]+=dp[mask];
//                 }
//             }
//         }
//     }
//     return dp[(1<<n)-1];
// }

long long helper(int N, int p,long long mask,long long* dp){
    if(mask == (1<<N)-1){
        return 1;
    }
    if(dp[mask] != -1){
        return dp[mask];
    }
    long long count = 0;
    for(int j=0;j<N;j++){
    	int flag = 1;
        if(!(mask&(1<<j))){
            for(int i=j-1;i>=0;i--){
                if((!(mask&(1<<i))) && ((i+1)&(j+1)) == (i+1)){
                    flag = 0;
                }
            }
            if(flag == 1){
                count+=helper(N,p+1,mask|(1<<j),dp);
            } 
        }
        
    }
    dp[mask] = count;
    return count;
}
int main()
{
    int n;
    cin>>n;
    long long* dp = new long long[(1<<(n+1))]; 
    for(int i=0;i<=(1<<(n+1));i++){
        dp[i] = -1;
    }
    // dp[0] = 1;
    // long long ans = getPermutations(n,0,dp);
    long long ans = helper(n,0,0,dp);
    cout<<ans<<endl;
    delete[] dp;
    return 0;
}


