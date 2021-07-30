#include<bits/stdc++.h>
using namespace std;
int main() {

	// Write your code here
    int s,d;
    cin>>s>>d;
    if(d>1){
        for(int i=1;i<=9;i++){
            if((double)(s-i)/(d-1) <= 9){
            	cout<<i;
            	d--;
                s-=i;
                break;
        	}
        }
    }else{
        cout<<s;
        d--;
        s=0;
    }
    while(d>0){
        if(d>1){
	        for(int i=1;i<=9;i++){
	            if((double)(s-i)/(d-1) <= 9){
	            	cout<<i;
	            	d--;
	                s-=i;
	                break;
	        	}
	        }
    	}else{
        	cout<<s;
        	d--;
        	s=0;
    	}
    }
    cout<<endl;
}
