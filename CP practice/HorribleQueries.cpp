#include<bits/stdc++.h>
using namespace std;

void buildTree(long long int* a,long long int *tree, int start,int end,int treeNode){
    if(start>end){
        return;
    }
    if(start == end){
        tree[treeNode] = a[start];
        return;
    }
    int mid = (start+end)/2;
    buildTree(a,tree,start,mid,2*treeNode);
    buildTree(a,tree,mid+1,end,2*treeNode+1);
    tree[treeNode] = tree[2*treeNode] + tree[2*treeNode+1];
}

void updateInc(long long int* a,long long int* tree,long long int* lazy,int start,int end,int treeNode,int st,int nd,long long int val){
    if(start>end){
        return;
    }
    if(lazy[treeNode]!=0){
        tree[treeNode] += (end-start+1)*lazy[treeNode];
        if(start != end){
            lazy[2*treeNode] += lazy[treeNode];
        	lazy[2*treeNode+1] +=lazy[treeNode];
        }
        lazy[treeNode] = 0;
    }
    // completely outside
    if(start >nd || end < st){
        return;
    }
    //completely inside
    if(start>=st && end<=nd){
        tree[treeNode] += (end-start+1)*val;
        if(start != end){
            lazy[2*treeNode] += val;
        	lazy[2*treeNode+1] += val;
        }
        return;
    }
    
    //partially inside
    int mid = (start+end)/2;
    updateInc(a,tree,lazy,start,mid,2*treeNode,st,nd,val);
    updateInc(a,tree,lazy,mid+1,end,2*treeNode+1,st,nd,val);
	tree[treeNode] = tree[2*treeNode] + tree[2*treeNode+1];
}

long long int query(long long int *tree,long long int *lazy,int start, int end,int treeNode,int st,int nd){
    if(start>end){
       	return 0;
    }
    if(lazy[treeNode]!=0){
        tree[treeNode] += (end-start+1)*lazy[treeNode];
        if(start != end){
            lazy[2*treeNode] += lazy[treeNode];
        	lazy[2*treeNode+1] +=lazy[treeNode];
        }
        lazy[treeNode] = 0;
    }
    // completely outside
    if(start >nd || end < st){
        return 0;
    }
    //completely inside
    if(start>=st && end<=nd){
        return tree[treeNode];
    }
    
    //partially inside
    int mid = (start+end)/2;
    long long int option1 = query(tree,lazy,start,mid,2*treeNode,st,nd);
    long long int option2 = query(tree,lazy,mid+1,end,2*treeNode+1,st,nd);
	long long int ans = option1 + option2;
	return ans;
}

int main() {
	int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        long long int* a = new long long int[n]();
        long long int* tree = new long long int[4*n]();
        long long int* lazy = new long long int[4*n]();
        buildTree(a,tree,0,n-1,1);
        while(q--){
            int op;
            cin>>op;
            int st,nd;
            cin>>st>>nd;
            st--;
            nd--;
            if(op==1){
                long long int ans = query(tree,lazy,0,n-1,1,st,nd);
                cout<<ans<<endl;
            }
            else if(op == 0){
                long long int x;
                cin>>x;
                updateInc(a,tree,lazy,0,n-1,1,st,nd,x);
            }
        }
        delete[] a;
        delete[] tree;
        delete[] lazy;
    }
	// Write your code here
}
