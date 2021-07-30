#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		int x = abs(a-b);
		int y = abs(c-d);
		if(x==0){
		    cout<<"YES"<<endl;
		}
		else if(y==0){
		    cout<<"NO"<<endl;
		}
		else if((x%y)==0){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
		
	}
	
	return 0;
}
