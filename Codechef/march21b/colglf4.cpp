#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

struct item{
    ll price;
    int egg;
    int choc;
    int cap;
    int alloc;
};

ll orderFood(int n, int e, int h, item a[], int i){
    if(e<0 || h<0){
    	return -1;
	}
	if(n==0){
        ll ans = 0;
        for(int k=0;k<3;k++){
            ans += a[k].alloc * a[k].price;
        }
        return ans;
	}

	if(i>2){
        return -1;
    }

    if(a[i].egg == 2){
        a[i].cap = e/a[i].egg;
    } else if(a[i].egg == 1){
        a[i].cap = min(e, h);
    } else if(a[i].choc == 3){
        a[i].cap = h/a[i].choc;
    }
    
    for(int j=a[i].cap; j>=0;j--){
        if(n>j){
            a[i].alloc = j;
            ll ans = orderFood(n-j, e-(a[i].egg * j), h-(a[i].choc * j), a, i+1);
            if(ans!=-1){
                return ans;
            }
        }else{
    		a[i].alloc = n;
            ll ans = orderFood(0, e-(a[i].egg * n), h-(a[i].choc * n), a, i+1);
            return ans;
        }
    }
    return -1;
}

bool comp(item a, item b){
    return (a.price<b.price);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int e, h;
        cin>>e>>h;
        item a[3];
        cin>>a[0].price;
        a[0].egg = 2;
        a[0].choc = 0;
        a[0].cap = e/a[0].egg;
        a[0].alloc = 0;

        cin>>a[1].price;
        a[1].egg = 0;
        a[1].choc = 3;
        a[1].cap = h/a[1].choc;
        a[1].alloc = 0;

        cin>>a[2].price;
        a[2].egg = 1;
        a[2].choc = 1;
        a[2].cap = min(e, h);
        a[2].alloc = 0;

        sort(a, a+3, comp);  
        int i=0;
        ll ans = orderFood(n, e, h, a, i);
        cout<<ans<<endl;
        
    }
    return 0;
}
