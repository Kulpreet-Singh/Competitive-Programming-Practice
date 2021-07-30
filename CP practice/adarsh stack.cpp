#include <bits/stdc++.h>
using namespace std;
void func(int num1,int num2);
stack<int> s1;
stack<int> s2;
int fl=0;
void func2(int num1,int num2){
    if(fl==0)
        s1.pop();
    s2.pop();
    s1.push(num2);
    if(!s2.empty()){
        fl=1;
        func(num1,s2.top());
    }
    else
        s2.push(num1);
}
void func(int num1,int num2){
        int ns1=num1;
	    int ns2=num2;
	    int cs1=0,cs2=0;
	    vector<int> v1,v2;
	    if(num1==0){
	        cs1=1;
	        v1.push_back(0);
	    }
	    if(num2==0){
	        cs2=1;
	        v2.push_back(0);
	    }
	    while(ns1!=0){
	        v1.push_back(ns1%10);
	        ns1=ns1/10;
	        cs1++;
	    }
	    while(ns2!=0){
	        v2.push_back(ns2%10);
	        ns2=ns2/10;
	        cs2++;
	    }
	    if(cs1==1 && cs2==1){
	        if(v1.front()-v2.front()==1){
	            if(fl==0)
	                s1.pop();
	            s2.pop();
	            s2.push(v1.front()*10+v2.front());
	        }
	        else if(v2.front()-v1.front()==1){
	            if(fl==0)
	                s1.pop();
	            s2.pop();
	            s2.push(v2.front()*10+v1.front());
	        }
	        else if(num1>=num2){
	            s2.push(s1.top());
	            if(fl==0)
	                s1.pop();
	        }
	        else
	            func2(num1,num2);
	    }
	    else if(cs1==1 && cs2==2){
	        int p=abs(v1.front()-v2.front());
	        int ss=*(v2.begin()+1);
	        int q=abs(v1.front()-ss);
	        if(p==1 || q==1){
	            int maxi=max(ss,v1.front());
	            int mini=min(v2.front(),v1.front());
	            if(fl==0)
	                s1.pop();
	            s2.pop();
	            s2.push(maxi*10+mini);
	        }
	        else if(num1>=ss){
	            s2.push(s1.top());
	            if(fl==0)
	                s1.pop();
	        }
	        else
	            func2(num1,num2);
	    }
	    else if(cs1==2 && cs2==1){
	        int p=abs(v1.front()-v2.front());
	        int ss=*(v1.begin()+1);
	        int q=abs(v2.front()-ss);
	        if(p==1 || q==1){
	            int maxi=max(ss,v1.front());
	            maxi=max(maxi,v2.front());
	            int mini=min(v2.front(),v1.front());
	            mini=min(mini,ss);
	            if(fl==0)
	                s1.pop();
	            s2.pop();
	            s2.push(maxi*10+mini);
	        }
	        else{
	            s2.push(ss*10+v1.front());
	            if(fl==0)
	                s1.pop();
	        }
	    }
	    else if(cs1==2 && cs2==2){
	        int ss1=*(v1.begin()+1);
	        int p=abs(ss1-v2.front());
	        int ss2=*(v2.begin()+1);
	        int q=abs(v1.front()-ss2);
	        if(p==1 || q==1){
	            int maxi=max(ss1,v1.front());
	            maxi=max(maxi,ss2);
	            int mini=min(v2.front(),v1.front());
	            mini=min(mini,ss1);
	            if(fl==0)
	                s1.pop();
	            s2.pop();
	            s2.push(maxi*10+mini);
	        }
	        else if(num1>=num2){
	            s2.push(s1.top());
	            if(fl==0)
	                s1.pop();
	        }
	        else
	            func2(num1,num2);
	    }
	    else{
	        if(num1>=num2){
	            s2.push(num1);
	            if(fl==0)
	                s1.pop();
	        }
	        else
	            func2(num1,num2);
	    }
}
int main() {
	// your code goes here
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
	    cin>>arr[i];
	    s1.push(arr[i]);
	}
	while(!s1.empty()){
	    if(s2.empty()){
	        s2.push(s1.top());
	        s1.pop();
	        continue;
	    }
	    fl=0;
	  //  cout<<s1.top()<<" "<<s2.top()<<endl;
	    func(s1.top(),s2.top());
	}
	while(!s2.empty()){
	    cout<<s2.top()<<" ";
	    s2.pop();
	}
	cout<<endl;
	sort(arr,arr+n);
	for(int i=n-1;i>=0;i--)
	    cout<<arr[i]<<" ";
	return 0;
}
