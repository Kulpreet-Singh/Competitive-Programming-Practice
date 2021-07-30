#include<bits/stdc++.h>
using namespace std;

int max_ele(vector<int> &a, vector<bool> &isin){
	int max = INT_MIN;
	int idx = -1;
	for(int i=0;i<a.size();i++){
		if(isin[i] == true){
			if(max < a[i]){
				max = a[i];
				idx = i;
			}
		}
	}
	return idx;
}

bool check(vector<int> &a, vector<bool> &isin, int prev){
	int id = max_ele(a, isin);
	if(id == -1){
		return true;
	}
	int ele = prev - a[id];
	vector<int>::iterator itr = find(a.begin(), a.end(), ele);
	if(itr!=a.end()){
		int i = itr - a.begin();
		isin[i] = false; 
		if (check(a,isin,a[id]) == false){
			isin[i] = true;
			return false;
		}else{
			isin[i] = true;
			return true;
		}
	}else{
		return false;
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> a(2*n);
		vector<bool> isin(2*n, true);
		int x;
		for(int i=0;i<2*n;i++){
			cin>>x;
			a.push_back(x);
		}
		int id = max_ele(a, isin);
		isin[id] = false;
		int flag = 0;
		for(int i=0;i<2*n;i++){
			if(i!=id){
				isin[i] = false;
				if(check(a, isin, a[id]) == true){
					x = a[id] + a[i];
					flag = 1;
					cout<<"YES"<<endl;
					cout<<x<<endl;
					cout<<a[id]<<" "<<a[i];
					
					break;
				}
				isin[i] = true;	
			}	
		}
		if(flag == 0){
			cout<<"NO"<<endl;
		}
	}
}
