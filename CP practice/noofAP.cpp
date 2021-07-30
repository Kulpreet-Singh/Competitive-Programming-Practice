#include <climits>
using namespace std; 
int numofAP(int *arr, int N){
    int minElem = INT_MAX, maxElem = INT_MIN;
    for (int i = 0; i < N; i++){
        minElem = min(minElem, arr[i]);
        maxElem = max(maxElem, arr[i]);
    } 
    int *dp = new int[N+1]; 
    int totalAPs = N + 1; 
    for (int d = (minElem-maxElem);d <= (maxElem-minElem);d++){ 
        int sum[1001] = {0};
        for (int i = 0; i < N; i++){ 
            dp[i] = 1;
            if (arr[i] - d >= 1 && arr[i] - d <= 1000)
                dp[i] += sum[arr[i] - d];
            totalAPs += (dp[i] - 1) % 100001; 
			sum[arr[i]] += dp[i];
        }
    }
    delete []dp;
    return totalAPs % 100001;
}











#include<bits/stdc++.h> 
using namespace std; 

#define INT_MIN -200
#define MAX 101

//max is maval of Array
int numofAP(int A[],int n){
    int d,i,j,ans=n+1;//each element and empty element form 1 array
    int maxval=INT_MAX,minval=INT_MAX;
    for(i=0;i<n;i++){
        maxval=max(maxval,A[i]);
        minval=min(minval,A[i]);
    }
    int dp[n],sum[MAX];
    for(d=(minval-maxval);d<=(maxval-minval);d++){
        for(i=0;i<MAX;i++){
            sum[i]=0;
        }
        for(i=0;i<n;i++){
            dp[i]=1;
            j=A[i]-d;
            if(j>=1&&j<MAX){
                dp[i]=dp[i]+sum[j];
            }
            ans=ans+dp[i]-1;
            sum[A[i]]=sum[A[i]]+dp[i];
        }
    }
    return ans;
}

