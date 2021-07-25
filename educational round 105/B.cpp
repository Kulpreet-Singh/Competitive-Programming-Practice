#include<bits/stdc++.h>
using namespace std;

bool comp(pair<char, int> p1, pair<char, int> p2){
	return (p1.second > p2.second);
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n, u, r, d, l;
		cin>>n>>u>>r>>d>>l;
		int fu = 2;
		int fr = 2;
		int fd = 2;
		int fl = 2;
		vector<pair<char, int> > v;
		v.push_back(make_pair('u', u));
		v.push_back(make_pair('r', r));
		v.push_back(make_pair('d', d));
		v.push_back(make_pair('l', l));
		sort(v.begin(), v.end(), comp);
		
		for(int i=0;i<v.size();i++){
			if(v[i].first=='r'){
				if(u>0 && r>0 && fr>0 && fu>0){
					u--;r--;
					fu--;fr--;
				}
				if(r>0 && d>0 && fr>0 && fd>0){
					r--;d--;
					fd--;fr--;
				}
			}else if(v[i].first == 'l'){
				if(u>0 && l>0&& fu>0 && fl>0){
					u--;l--;
					fu--;fl--;
				}
						
				if(l>0 && d>0&& fl>0 && fd>0){
					l--;d--;
					fl--;fd--;
				}
			}else if(v[i].first=='u'){
				if(u>0 && r>0 && fr>0 && fu>0){
					u--;r--;
					fu--;fr--;
				}
				if(u>0 && l>0 && fu>0 && fl>0){
					u--;l--;
					fu--;fl--;
				}
			}else if(v[i].first == 'd'){
				if(r>0 && d>0 && fr>0 && fd>0){
					r--;d--;
					fd--;fr--;
				}
				if(l>0 && d>0 && fl>0 && fd>0){
					l--;d--;
					fl--;fd--;
				}
			}
		}
		
		if(u<n-1 && r<n-1 && d<n-1 && l<n-1){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	
	return 0;
}
