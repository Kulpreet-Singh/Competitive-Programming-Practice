#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

#define mod 1000000007
typedef long long ll;

bool comp(pair<int, int> &a, pair<int, int> &b){
	return a.second > b.second;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		ll x;
		cin>>n>>x;
		map<int, vector<int> > d;
		for(int i=2; i<n+1; i++){
			int u, v;
			cin>>u>>v;
			auto itr = d.find(u);
			if(itr!=d.end()){
				itr->second.push_back(v);
			}
			else{
				vector<int> l;
				l.push_back(v);
				d.insert({u, l});
			}
		}

		for(auto i = d.begin(); i!=d.end();i++){
			vector<pair<int, int> > temp;
			auto v = i->second;
			for(auto x = v.begin(); x!= v.end(); x++){
				int c = 0;
				auto it = d.find(*x);
				if(it != d.end()){
					c = it->second.size();
				}
				else
					c = 0;
				temp.push_back({*x, c});
			}
			sort(temp.begin(), temp.end(), comp);
			vector<int> l;
			for(auto it = temp.begin(); it!=temp.end(); it++){
				l.push_back(it->first);
			}
			i->second = l;
		}
		map<int, ll> d1;
		for(int i=1; i<n+1; i++){
			auto ir = d.find(i);
			if(ir != d.end()){
				ll num = 0;
				if(i==1)
					num = x;
				else
					num = d1.find(i)->second;
				ll j = 1;
				for(auto itr = ir->second.begin(); itr!=ir->second.end(); itr++){
					d1.insert({*itr, num*j});
					j++;
				}
			}
		}
		ll sum = x;
		for(auto itr = d1.begin(); itr!=d1.end(); itr++){
			sum += itr->second;
			sum = sum%mod;
		}
		cout<<sum%mod<<endl;		
	}
}


/* 

	  1
  1   _	 2
1_2_3	2  _  4
	   2_4   4_8


	= 34

	  1
  2   _	 1
2_4_6	1  _  2
	   1_2   2_4

	   = 28

	   */