#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		int c =0;
		int f=0;
		vector<int> a(n);
		vector<int> temp(n);
		for(int i=0;i<n;i++){
			cin>>a[i];
			temp[i] = a[i];
			if(a[i] > d){
				f=1;
			}
		}
		if(f==0){
			cout<<"YES"<<endl;
		}else{
			sort(temp.begin(), temp.end());
			if(temp[0]+temp[1]<=d){
				cout<<"YES"<<endl;
			}	
			else{
				cout<<"NO"<<endl;
			}
		}
	}
	return 0;
}
