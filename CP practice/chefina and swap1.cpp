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
	int t;
	cin>>t;
	while(t--){
	    ll n;
	    cin>>n;
	    ll count = 0;
	    ll m;
		ll sumn = sum_n;
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
	   
	    for(ll i=m-1;i>0;i--){
	       ll d;
	       d = sum_n - 2*sum_i;
	       if(d==0){
                count+=sum_i_1;
	        }
	        else if(d>0){
	            if(d%2==0){
	                d=d/2;
	                int flag = 0;
	                ll beg1 = i+1;
	                ll end1 = n;
	                ll j;
	                while(beg1<=end1){
	                    j = (beg1+end1)/2;
	                    if((j-d)<=i && ((j+1>n)||((j+1-d)>i))){
	                        break;
	                    }
	                    else if((j-d)>i){
	                        end1 = j-1;
	                    }
	                    else if((j-d)<=i){
	                        beg1 = j+1;
	                    }
	                }
                    if(j-d<=i && j-d>0){
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

