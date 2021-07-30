#include<bits/stdc++.h>
using namespace std;

int main(){
	int q;
	cin>>q;
	while(q--){
		string s,t;
		cin>>s>>t;
		string temps,tempt;
		temps = s;
		tempt = t;
		int n = 0;
		while(n<100 && temps.length() != tempt.length()){
			if(temps.length() > tempt.length()){
				tempt = tempt + t;
			}else{
				temps = temps + s;
			}
			n++;
		}
		if(temps.length() == tempt.length()){
			if(temps == tempt){
				cout<<temps<<endl;
			}
			else{
				cout<<-1<<endl;
			}
		}else{
			cout<<-1<<endl;
		}	
	}
}
