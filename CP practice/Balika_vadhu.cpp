#include <bits/stdc++.h>
using namespace std;      

// int findSum(int *a,int n){
//     int sum=0 ;
//     for(int i=0;i<n;i++){
//         sum+=a[i];
//     }
//     return sum;
// }
// int findASum(int *a,int n,int k){
//     int sum=0 ;
//     if(findSum(a,n)<k){
//         return 0;
//     }
//     else if(findSum(a,n) == k){
//     	for(int i=0;i<n;i++){
//             sum+=(a[i]*(i+97));
//         }    
//     }
//     else{
//         int i =n-1;
//         while(k-a[i]>=0){
//             k-=a[i];
//             sum+=(a[i]*(i+97));
//             i--;
//             if(k==0){
//                 break;
//             }
//         }
//         if(k!=0){
//             sum+=(k*(i+97));
//         }
//     }
//     return sum;
// }
//backtrackng approach failed due to TLE
// int spotter(char* a,char* b, int m,int n,int k,int *dp){
//     if(m==0||n==0){
//         return findASum(dp,26,k);
//     }
//     int ans;
//     if(a[0] == b[0]){
//         dp[(a[0] - 'a')] +=1;
//         ans = spotter(a+1,b+1,m-1,n-1,k,dp);
//     	dp[(a[0] - 'a')] -= 1;
//     }
//     else{
//     	int option1 = spotter(a,b+1,m,n-1,k,dp);
//         int option2 = spotter(a+1,b,m-1,n,k,dp);
//         ans = max(option1,option2);
//     }
//     return ans;
// }

int spotter(char* a,char* b, int m,int n,int k,int ***dp){
    if(k==0){
        return 0;
    }
    if(m==0||n==0){
            return -10000;
    }
    
    if(dp[m][n][k]>-20000){
    	return dp[m][n][k];
    }
    
    int ans;
    if(a[0] == b[0]){
        int option1 = (int)a[0] + spotter(a+1,b+1,m-1,n-1,k-1,dp);            
		int option2 = spotter(a+1,b,m-1,n,k,dp);
		int option3 = spotter(a,b+1,m,n-1,k,dp);
    ans = max(option1,max(option2,option3));
        
    }
    else{
    	int option1 = spotter(a,b+1,m,n-1,k,dp);
        int option2 = spotter(a+1,b,m-1,n,k,dp);
    	ans = max(option1,option2);
    }
	
    dp[m][n][k] =ans;
    return ans;
}

int findMax(string s1,string s2,int k){
    int m = s1.length();
    int n = s2.length();
    char* a = new char[m+1];
    char* b = new char[n+1];
    for(int i=0;i<=m;i++){
        a[i] = s1[i];
    }
    for(int j=0;j<=n;j++){
        b[j] = s2[j];
    }
    // int * dp = new int[26];
    // int **res = new int*[m+1];
    // for(int i=0;i<=m;i++){
    //     res[i] = new int[n+1];
    //     for(int j=0;j<=n;j++){
    //         res[i][j] = -1;
    //     }
    // }
    // for(int i=0;i<26;i++){
    //     dp[i] = 0;
    // }
    int ***dp = new int**[m+1];
    for(int i=0;i<m+1;i++){
        dp[i] = new int*[n+1];
        for(int j=0;j<n+1;j++){
            dp[i][j] = new int[k+1];
            for(int l=0;l<k+1;l++){
                dp[i][j][l] = -20000;
            }
        }
    }
    int ans = spotter(a,b,m,n,k,dp);
    if(ans<0){
        ans =0 ;
    }
    // for(int i=0;i<=m;i++){
    //     delete[] res[i];
    // }
    // delete[] res;
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            delete[] dp[i][j];
            
        }
        delete[] dp[i];
    }
    delete[] dp;
    return ans;
}


int main()
{
    int t;
    cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
        int k;
        cin>>k;
        int ans = findMax(s1,s2,k);
        cout<<ans<<endl;
    }
    return 0;
}

