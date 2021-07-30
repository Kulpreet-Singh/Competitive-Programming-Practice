#include<bits/stdc++.h>
using namespace std;

int countNonZero(vector<int> q){
    int n = q.size();
    int count =0;
    for(int i=0;i<n;i++){
        if(q[i]>0){
            count++;
        }
    }
    return count;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		vector<int> a(1001,0);
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		vector<int> c(1001,-1);
		int maxCount = -1;
		for(int i=0;i<n;i++){
			if(c[a[i]]==-1){
			    c[a[i]] = 0;
			}
			c[a[i]]++;
			if(c[a[i]]>maxCount){
				maxCount = c[a[i]];
			}
		}
		
		vector<int> q;
		for(int i=1;i<1001;i++){
		    if(c[i]!=-1){
		        q.push_back(c[i]);
		    }
		}
		int no = q.size();
		int tables=0;
		while(countNonZero(q)>0){
		    for(int i=0;i<no;i++){
		        if(q[i]!=0){
		            q[i]--;
		            int j = i+1;
		            while(j<no && q[j]!=0){
		                q[j]--;
		                j++;
		            }
		            i=j-1;
		            tables++;
		        }
		    }
		}
		
		if(k==1){
			cout<<tables<<endl;
		}
		else{
		    cout<<tables<<endl;
		}
	}
}
