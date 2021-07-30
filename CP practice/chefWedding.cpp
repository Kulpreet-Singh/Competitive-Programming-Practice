#include<bits/stdc++.h>
using namespace std;

int counter(unordered_map<int,int> &m){
    int sum = 0;
    for(auto itr = m.begin(); itr!=m.end();itr++){
        if((itr->second)>1){
            sum+=(itr->second);
        }
    }
    return sum;
}

int countBucket(unordered_map<int,int> &m){
    int sum = 0;
    for(auto itr = m.begin(); itr!=m.end();itr++){
        if((itr->second)>1){
            sum+=1;
        }
    }
    return sum;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		scanf("%d %d",&n,&k);
		vector<int> a(1001,0);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		if(k==1){
		    int table=0;
    		unordered_set<int> s;
    		for(int i=0;i<n;){
    		    int j=i;
    		    while(j<n && s.find(a[j])==s.end()){
    		        s.insert(a[j]);
    		        j++;
    		    }
    		    table++;
    		    s.clear();
    		    i=j;
    		}
    		printf("%d\n",(k*table));
		}
		else{
		    int cost = 0;
		    int table = 0;
		    unordered_map<int,int> m;
		    unordered_map<int,int> prev;
		    unordered_set<int> s;
		    for(int i=0;i<n;){
    		    int j=i;
    		    while(j<n){
    		        if((m.bucket_count()>=(k/2))){
    		            if(m.find(a[j])==m.end()){
    		                m[a[j]]+=1;
    		                j++;
    		            }
    		            else{
    		                int in = j;
    		                while(j<n && in<n && (prev.size()<=(k/2))){
    		                    if(prev.find(a[in])==prev.end()){
        		                    prev[a[in]] = in;
        		                    in++;
        		                }
        		                else{
        		                    if(prev[a[in]] == j){
        		                        m[a[j]]+=1;
        		                        j++;
        		                        while(s.find(j)!=s.end()){
        		                            m[a[j]]+=1;
        		                            s.erase(j);
        		                            j++;
        		                        }
        		                        prev[a[in]] = in;
        		                        in++;
        		                    }
        		                    else{
                                        s.insert(prev[a[in]]);
                                        prev[a[in]] = in;
                                        in++;
        		                    }
        		                }
    		                }
    		                if((prev.size())<(k/2)){
    		                    prev.clear();
    		                    s.clear();
    		                }
    		            }
    		        }
    		        else{
    		            m[a[j]]+=1;
    		            j++;
    		        }
    		        if(prev.size()>(k/2)){
    		            while(s.find(j)!=s.end()){
                            m[a[j]]+=1;
                            s.erase(j);
                            j++;
                        }
    		            s.clear();
    		            break;            
    		        }
    		      //  else{
    		      //      prev.clear();
    		      //      s.clear();
    		      //  }
    		    }
    		    
    		    cost+=counter(m);
    		    table++;
    		    m.clear();
    		    prev.clear();
    		    i=j;
    		}
    		int ans = cost + table*k;
    		printf("%d\n",ans);
		    
		}
		
	}
}
