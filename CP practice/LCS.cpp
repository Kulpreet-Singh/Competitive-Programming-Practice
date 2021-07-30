#include<iostream>
#include<cstring>
using namespace std;

int lcsHelper(string *s1,string *s2,int m,int n,int **dp){
    if(m==0||n==0){
        return 0;
    }
    if(dp[m][n]>-1){
        return dp[m][n];
    }
    int ans;
    if((*s1)[0] == (*s2)[0]){
        ans = 1+lcsHelper(s1++,s2++,m-1,n-1,dp);
    }
    else{
    	string* temps1 = s1;
        string* temps2 = s2;
        int option2 = lcsHelper(s1,temps2++,m,n-1,dp);
        int option1 = lcsHelper(temps1++,s2,m-1,n,dp);
        ans = max(option1,option2);
    }
    dp[m][n] = ans;
    return ans;
}

int lcs(string s1, string s2){

  /*  Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Return output and don't print it.
   *  Taking input and printing output is handled automatically.
   */
	int m = s1.length();
    int n = s2.length();
    int ** dp = new int *[m+1];
    for(int i=0;i<m+1;i++){
        dp[i] = new int[n+1];
        for(int j=0;j<n+1;j++){
            dp[i][j] = -1;
        }
    }
    int ans = lcsHelper(&s1,&s2,m,n,dp);
    for(int i=0;i<m+1;i++){
        delete[] dp[i];
    }
    delete[] dp;
    return ans;
}
int main(){
	string s1,s2;
	cin>>s1>>s2;
	int ans = lcs(s1,s2);
	cout<<ans<<endl;
	return 0;
}
