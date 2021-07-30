#include <bits/stdc++.h>
using namespace std;

int kadaneSum(int *a, int n){
    int currSum=0;
    int maxSum =INT_MIN;
    for(int i=0;i<n;i++){
        if(currSum<0){
            currSum=0;
        }
        currSum+=a[i];
        if(maxSum<currSum){
            maxSum=currSum;
        }
    }
    return maxSum;
}

int maxSumRect(int ** a, int n,int m){
    int maxSum=INT_MIN;
    int currSum=0;
    int *sum = new int[n];
    for(int i=0;i<n;i++){
        sum[i]=0;
    }
    for(int i=0;i<m;i++){
        
        for(int k=0;k<n;k++){
            sum[k]=a[k][i];
        }
        currSum=kadaneSum(sum,n);
        if(maxSum<currSum){
            maxSum=currSum;
        }
        for(int j=i+1;j<m;j++){
        	for(int k=0;k<n;k++){
                sum[k]+=a[k][j];
            }
            currSum=kadaneSum(sum,n);
            if(maxSum<currSum){
                maxSum=currSum;
            }    
        }
    }
    delete[] sum;
    return maxSum;
}

void initializeSum(int** a,int n,int m, int** sum){
    sum[n-1][m-1]=a[n-1][m-1];
    for(int i=n;i>=0;i--){
        sum[i][m]=0;
    }
    for(int j=m;j>=0;j--){
        sum[n][j]=0;
    }
    for(int i=n-2;i>=0;i--){
        sum[i][m-1]=sum[i+1][m-1]+a[i][m-1];
    }
    for(int j=m-2;j>=0;j--){
        sum[n-1][j]=sum[n-1][j+1]+a[n-1][j];
    }
    for(int i=n-2;i>=0;i--){
        for(int j=m-2;j>=0;j--){
            sum[i][j]=a[i][j]+sum[i+1][j]+sum[i][j+1]-sum[i+1][j+1];
        }
    }
}

int maxSumRect2(int **a,int n,int m){
    int maxSum=INT_MIN;
    int currSum=0;
    int** sum= new int *[n+1];
    for(int i=0;i<n+1;i++){
        sum[i]=new int[m+1];
    }
    initializeSum(a,n,m,sum);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=i+1;k<=n;k++){
                for(int l=j+1;l<=m;l++){
                    currSum=sum[i][j]-sum[i][l]-sum[k][j]+sum[k][l];
                    if(maxSum<currSum){
                        maxSum=currSum;
                    }
                }
            }
        }
    }
    for(int i=0;i<=n;i++){
        delete[] sum[i];
    }
    delete[] sum;
    return maxSum;
}

int main()
{
    int n,m;
    cin>>n>>m;
    int** a = new int* [n];
    for(int i=0;i<n;i++){
        a[i]=new int[m];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    int res = maxSumRect2(a,n,m);
    cout<<res<<endl;
    for(int i=0;i<n;i++){
        delete[] a[i];
    }
    delete[] a;
    return 0;
}

