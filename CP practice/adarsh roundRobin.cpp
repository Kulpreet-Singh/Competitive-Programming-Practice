#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
vector<pair<int,pi>> v;
int n,idx=0,t=0,tt;
struct node{
    int num;
    int bt;
    node *next;
    node(int a,int b){
        num=a;
        bt=b;
    }
};
node *temp=NULL;
node *ptr=NULL,*prptr;
void checkNewNode(){
    while(v[idx].first==t){
	    node *newnode=new node(v[idx].second.first,v[idx].second.second);
	    if(temp==NULL){
	        newnode->next=newnode;
	        temp=newnode;
	        ptr=newnode;
	        prptr=newnode;
	    }
	    else{
	        newnode->next=temp->next;
	        temp->next=newnode;
	        temp=newnode;
	        while(prptr->next!=ptr)
	            prptr=prptr->next;
	    }
	    if(idx==n-1)
	        break;
	    idx++;
	}
}
void process(){
    while(ptr==NULL){
        checkNewNode();
        if(ptr==NULL)
            t++;
    }
    while(tt--){
    ptr->bt--;
    cout<<ptr->num<<" ";
    t++;
    if(idx<n)
        checkNewNode();
    if(ptr->bt==0)
        prptr->next=prptr->next->next;
    else 
        prptr=ptr;
    ptr=ptr->next;
    }
}
int main() {
	// your code goes here
	cin>>n;
	for(int i=0;i<n;i++){
	    int inp1,inp2,inp3;
	    cin>>inp1>>inp2>>inp3;
	    tt+=inp3;
	    v.push_back({inp2,{inp1,inp3}});
	}
	sort(v.begin(),v.end());
    process();
	return 0;
}
