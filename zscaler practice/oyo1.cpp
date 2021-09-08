#include<bits/stdc++.h>
using namespace std;
void reversePrint(string ans){
	for(int i=ans.length()-1; i>=0;i--){
		cout<<ans[i];
	}
	cout<<"\n";
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string ans = "";
		while((n-1)/26 > 0){
			int k = (n-1)%26;
			n = (n-1)/26;
			ans+=('A'+k);
		}
		if(n-1>=0){
			ans+=('A'+(n-1));
		}
		reversePrint(ans);
	}
	return 0;
}
