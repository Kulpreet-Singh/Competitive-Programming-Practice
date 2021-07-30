#include <bits/stdc++.h>
using namespace std;
#define max 100000000
#define sum_n (n*(n+1))/2
#define sum_m (m*(m+1))/2
#define sum_m_1 ((m-1)*m)/2
#define sum_i (i*(i+1))/2
#define sum_i_1 ((i-1)*i)/2
typedef long long ll;

int main() {
	// your code goes here
// 	vector<ll> sum(max+1);
// 	for(ll i=0;i<max+1;i++){
// 	    sum[i] = (i*(i+1))/2;
// 	}
	int t;
	cin>>t;
	while(t--){
	    ll n;
	    cin>>n;
	   // cout<<sum[n]<<",";
	    ll count = 0;
	    ll m;
	   // if(n<=max){
	   //     m = upper_bound(sum.begin(),sum.end(),(double)sum[n]/2) - sum.begin();
	   // }
	   // else{
	        ll sumn = sum_n;
	       // ll beg = 10000001;
	       ll beg = 1;
	        ll end = n;
	        while(beg<=end){
	            m = (beg + end)/2;
	            if(sum_m_1<=(double)sumn/2 && sum_m > (double)sumn/2){
	                break;
	            }
	            else if(sum_m > (double)sumn/2){
	                end = m-1;
	            }
	            else if(sum_m <= (double)sumn/2){
	                beg = m+1;
	            }
	        }
	   // }
	   // cout<<sum[m-1]<<endl;
	   // cout<<m-1<<","<<endl;
	    for(ll i=m;i>0;i--){
	       // cout<<i<<endl;
	       ll d;
	       //if(n<=max){
	       //   d = sum[n] - 2*sum[i]; 
	       //}
	       //else{
	           d = sum_n - 2*sum_i;
	       //}
	       // cout<<d<<endl;
	        if(d==0){
	           // if(i<=max){
	           //     count+=sum[i-1];
	           // }else{
	                count+=sum_i_1;
	           // }
	        }
	        else if(d>0){
	            if(d%2==0){
	                d=d/2;
	               // cout<<d<<endl;
	                int flag = 0;
	                for(ll j = n;(j>i && (j-d)>0);j--){
	                    if(j-d<=i){
	                        flag = 1;
	                        ll beg = i+1;
	                        ll end = j;
	                        ll mid;
	                        while(beg<=end){
	                            mid = (beg+end)/2;
	                            if(mid-d>0 && mid-1-d<=0){
	                                break;
	                            }else if(mid-d>0){
	                                end = mid-1;
	                            }
	                            else if(mid-d<=0){
	                                beg = mid+1;
	                            }
	                        }
	                        
	                        count+=j-mid+1;
	                        break;
	                       // count++;
	                    }
	                }
	                if(flag == 0){
	                    break;
	                }
	            }
	        }
	    }
	    cout<<count<<endl;
	}
	return 0;
}

