#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string a,b;
		cin>>b;
		int prev = 0;
		for(int i=0;i<n;i++){
			if((b[i]-'0')+1!=prev){
			
				a += "1";
				prev = (b[i]-'0')+1;
			}else{
				prev = b[i]-'0';
				a += "0";
			}
		}
		cout<<a<<endl;
	}
}
