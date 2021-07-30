#include <iostream>
using namespace std;
bool func(int a[],int n){
    int i=0;
	    int j=1;
	    while(i<n){
	        if(a[i]==0){
	            i++;
	        }
	        else{
	            j=i+1;
	            while(j<n){
	                if(j-i<6){
    	                if(a[j]==1){
    	                    return false;
    	                }
    	                j++;
    	            }
    	            else{
    	                i=j;
    	                break;
    	            }
	            }
	            
	        }
	    }
	    return true;
}
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    bool x=func(a,n);
	    if(x){
	        cout<<"YES"<<endl;
	    }
	    else{
	        cout<<"NO"<<endl;
	    }
	    
	    
	}
	return 0;
}

