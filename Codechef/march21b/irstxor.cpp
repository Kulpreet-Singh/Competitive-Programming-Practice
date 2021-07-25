#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    ll c;
	    cin>>c;
	    int d = 0;
	    ll temp = c;
	    while(temp){
	        temp = temp>>1;
	        d++;
	    }
	    temp = c;
	    ll a = 0;
	    ll b = 0;
	    ll res;
	    for(int i=1;i<=d;i++){
	        if((temp&(1<<(d-i)))){
	            // 512 + 128 = 640 // 163840
	            // 256 + 128 = 384 // 196608 Increment smaller one
                if(a<b){
                    a++;
    	            a = a<<1;
                    b = b<<1;
                }else{
                    b++;
                    a = a<<1;
                    b = b<<1;
                }            
	        }else{
	            a++;
	            b++;
	            a = a<<1;
	            b = b<<1;
	        }
	    }
		a= a>>1;
		b = b>>1;
	    res = a*b;
	    cout<<res<<endl;
	}
	
	return 0;
}
