#include<bits/stdc++.h>
using namespace std;


void buildTree(int p[],char a[],int *tree,int start,int end,int treeNode){  
    if(start == end){
        tree[treeNode] = a[start] - '0';
        return;
    }
    int mid = (start+end)/2;
    buildTree(p,a,tree,start,mid,2*treeNode);
    buildTree(p,a,tree,mid+1,end,2*treeNode+1);
	tree[treeNode] = (3+(3+tree[2*treeNode]*p[end-mid])%3 + tree[2*treeNode+1])%3;   
}

void update(int p[],char a[],int *tree,int start,int end,int treeNode,int in){  
    if(start>end){
        return;
    }
    if(start == end){
        a[in] = '1';
        tree[treeNode] = 1;
        return;
    }
    int mid = (start+end)/2;
    if(in>mid){
    	update(p,a,tree,mid+1,end,2*treeNode+1,in);
    }
    else{
    	update(p,a,tree,start,mid,2*treeNode,in);        
    }
	tree[treeNode] = (3+(3+tree[2*treeNode]*p[end-mid])%3 + tree[2*treeNode+1])%3;   
}

int  query(int p[],int *tree,int start,int end,int treeNode,int left,int right){
    if(start>end){
        return 0;
    }
    if(start>right || end<left){
        return 0;
    }
    if(start >=left && end<=right){
        return tree[treeNode];
    }
    int mid = (start+end)/2;
    int option1 = query(p,tree,start,mid,2*treeNode,left,right);
    int option2 = query(p,tree,mid+1,end,2*treeNode+1,left,right);
    int ans;
    if(right>end)
        ans = (3+(3+option1*p[end-mid])%3 + option2)%3;       
    else{
        if(right>=mid)
    		ans = (3+(3+option1*p[right-mid])%3 + option2)%3;       
		else{
            ans = option1;
        }
    }
        return ans;
}

int main() {
	int n,q;
    cin>>n;
	int p[999999];
    p[0] =1;
    for(int i=1;i<999999;i++){
        p[i] = (2*p[i-1])%3;
        // cout<<p[i]<<" ";
    }
    // cout<<endl;
    char a[n+1];
    cin>>a;
    int *tree = new int[4*n];
    buildTree(p,a,tree,0,n-1,1);
    cin>>q;
    while(q--){
        int op;
        int l, r;
        cin>>op;
        if(op==0){
            cin>>l>>r;
            int ans = query(p,tree,0,n-1,1,l,r);
            cout<<ans<<endl;
        }
        else if(op==1){
            cin>>l;
            update(p,a,tree,0,n-1,1,l);
        }
    }
    delete[] tree;
	// Write your code here
}
