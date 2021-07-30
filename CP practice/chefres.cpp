#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pp;
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n,m;
	    cin>>n>>m;
	    vector<pp> v;
	    for(int i=0;i<n;i++){
	        int x,y;
	        cin>>x>>y;
	        v.push_back(make_pair(x,y));
	    }
	    sort(v.begin(),v.end());
	    while(m--){
	        int x;
	        cin>>x;
	        int index=lower_bound(v.begin(),v.end(),make_pair(x,0))-v.begin();
	        if(index == 0){
	            cout<<v[index].first - x<<endl;
	        }
	        else{
	            int ans=-1;
	            if(index<n){
	                if(v[index-1].second > x){
	                    ans = 0;
	                }
	                else{
	                    ans=v[index].first - x;
	                }
	            }
	            else{
	               if(v[index-1].second > x){
	                    ans = 0;
	                } 
	            }
	            cout<<ans<<endl;
	        }
	        
	    }
	}
	
	
	return 0;
}
