#include<bits/stdc++.h>
using namespace std;

struct node1{
    int ss;
    int s;
};

struct node2{
    int value;
    int type;
};

void buildTree(int* a,node1 *tree, int start,int end,int treeNode){
    if(start>end){
        return;
    }
    if(start == end){
        tree[treeNode].s = a[start];
        tree[treeNode].ss = a[start] * a[start];
        return;
    }
    int mid = (start+end)/2;
    buildTree(a,tree,start,mid,2*treeNode);
    buildTree(a,tree,mid+1,end,2*treeNode+1);
    tree[treeNode].s = tree[2*treeNode].s + tree[2*treeNode+1].s;
    tree[treeNode].ss = tree[2*treeNode].ss + tree[2*treeNode+1].ss;
}

void updateInc(int* a,node1* tree,node2* lazy,int start,int end,int treeNode,int st,int nd,int val){
    if(start>end){
        return;
    }
    if(lazy[treeNode].type!=0){
        if(lazy[treeNode].type == 1){
            tree[treeNode].ss += (end-start+1)*lazy[treeNode].value*lazy[treeNode].value + 2*tree[treeNode].s*lazy[treeNode].value;
            tree[treeNode].s += (end-start+1)*lazy[treeNode].value;
            if(start!=end){
                if(lazy[2*treeNode].type == 0){
                	lazy[2*treeNode].type = 1;    
                }
                lazy[2*treeNode].value += lazy[treeNode].value;
                if(lazy[2*treeNode+1].type == 0){
                	lazy[2*treeNode+1].type = 1;    
                }
                lazy[2*treeNode+1].value += lazy[treeNode].value;
            }
            lazy[treeNode].value = 0;
            lazy[treeNode].type = 0;
        }
        else if(lazy[treeNode].type == 2){
            tree[treeNode].ss = (end-start+1)*lazy[treeNode].value*lazy[treeNode].value;
            tree[treeNode].s = (end-start+1)*lazy[treeNode].value;
            if(start!=end){
            	lazy[2*treeNode].type = 2;  
                lazy[2*treeNode].value = lazy[treeNode].value;
                lazy[2*treeNode+1].type = 2;
                lazy[2*treeNode+1].value = lazy[treeNode].value;
            }
            lazy[treeNode].value = 0;
            lazy[treeNode].type = 0;
        }
    }
    // completely outside
    if(start >nd || end < st){
        return;
    }
    //completely inside
    if(start>=st && end<=nd){
        tree[treeNode].ss += (end-start+1)*val*val + 2*tree[treeNode].s*val;
    	tree[treeNode].s += (end-start+1)*val;
        if(start!=end){
            if(lazy[2*treeNode].type == 0){
            	lazy[2*treeNode].type = 1;    
            }
            lazy[2*treeNode].value += val;
            if(lazy[2*treeNode+1].type == 0){
            	lazy[2*treeNode+1].type = 1;    
            }
            lazy[2*treeNode+1].value += val;
        }
        return;
    }
    
    //partially inside
    int mid = (start+end)/2;
    updateInc(a,tree,lazy,start,mid,2*treeNode,st,nd,val);
    updateInc(a,tree,lazy,mid+1,end,2*treeNode+1,st,nd,val);
	tree[treeNode].s = tree[2*treeNode].s + tree[2*treeNode+1].s;
    tree[treeNode].ss = tree[2*treeNode].ss + tree[2*treeNode+1].ss;
}

void updateSet(int* a,node1* tree,node2* lazy,int start,int end,int treeNode,int st,int nd,int val){
    if(start>end){
        return;
    }
    if(lazy[treeNode].type!=0){
        if(lazy[treeNode].type == 1){
            tree[treeNode].ss += (end-start+1)*lazy[treeNode].value*lazy[treeNode].value + 2*tree[treeNode].s*lazy[treeNode].value;
            tree[treeNode].s += (end-start+1)*lazy[treeNode].value;
            if(start!=end){
                if(lazy[2*treeNode].type == 0){
                	lazy[2*treeNode].type = 1;    
                }
                lazy[2*treeNode].value += lazy[treeNode].value;
                if(lazy[2*treeNode+1].type == 0){
                	lazy[2*treeNode+1].type = 1;    
                }
                lazy[2*treeNode+1].value += lazy[treeNode].value;
            }
            lazy[treeNode].value = 0;
            lazy[treeNode].type = 0;
        }
        else if(lazy[treeNode].type == 2){
            tree[treeNode].ss = (end-start+1)*lazy[treeNode].value*lazy[treeNode].value;
            tree[treeNode].s = (end-start+1)*lazy[treeNode].value;
            if(start!=end){
            	lazy[2*treeNode].type = 2;  
                lazy[2*treeNode].value = lazy[treeNode].value;
                lazy[2*treeNode+1].type = 2;
                lazy[2*treeNode+1].value = lazy[treeNode].value;
            }
            lazy[treeNode].value = 0;
            lazy[treeNode].type = 0;
        }
    }
    // completely outside
    if(start >nd || end < st){
        return;
    }
    //completely inside
    if(start>=st && end<=nd){
        tree[treeNode].ss = (end-start+1)*val*val;
    	tree[treeNode].s = (end-start+1)*val;
        if(start!=end){
            lazy[2*treeNode].type = 2;    
            lazy[2*treeNode].value = val;
            lazy[2*treeNode+1].type = 2;    
            lazy[2*treeNode+1].value = val;
        }
        return;
    }
    
    //partially inside
    int mid = (start+end)/2;
    updateSet(a,tree,lazy,start,mid,2*treeNode,st,nd,val);
    updateSet(a,tree,lazy,mid+1,end,2*treeNode+1,st,nd,val);
	tree[treeNode].s = tree[2*treeNode].s + tree[2*treeNode+1].s;
    tree[treeNode].ss = tree[2*treeNode].ss + tree[2*treeNode+1].ss;
}

node1 query(node1 *tree,node2 *lazy,int start, int end,int treeNode,int st,int nd){
    if(start>end){
        node1 ans;
        ans.ss=0;
        ans.s =0;
        return ans;
    }
    if(lazy[treeNode].type!=0){
        if(lazy[treeNode].type == 1){
            tree[treeNode].ss += (end-start+1)*lazy[treeNode].value*lazy[treeNode].value + 2*tree[treeNode].s*lazy[treeNode].value;
            tree[treeNode].s += (end-start+1)*lazy[treeNode].value;
            if(start!=end){
                if(lazy[2*treeNode].type == 0){
                	lazy[2*treeNode].type = 1;    
                }
                lazy[2*treeNode].value += lazy[treeNode].value;
                if(lazy[2*treeNode+1].type == 0){
                	lazy[2*treeNode+1].type = 1;    
                }
                lazy[2*treeNode+1].value += lazy[treeNode].value;
            }
            lazy[treeNode].value = 0;
            lazy[treeNode].type = 0;
        }
        else if(lazy[treeNode].type == 2){
            tree[treeNode].ss = (end-start+1)*lazy[treeNode].value*lazy[treeNode].value;
            tree[treeNode].s = (end-start+1)*lazy[treeNode].value;
            if(start!=end){
            	lazy[2*treeNode].type = 2;  
                lazy[2*treeNode].value = lazy[treeNode].value;
                lazy[2*treeNode+1].type = 2;
                lazy[2*treeNode+1].value = lazy[treeNode].value;
            }
            lazy[treeNode].value = 0;
            lazy[treeNode].type = 0;
        }
    }
    // completely outside
    if(start >nd || end < st){
        node1 ans;
        ans.ss=0;
        ans.s =0;
        return ans;
    }
    //completely inside
    if(start>=st && end<=nd){
        return tree[treeNode];
    }
    
    //partially inside
    int mid = (start+end)/2;
    node1 ans;
    node1 option1 = query(tree,lazy,start,mid,2*treeNode,st,nd);
    node1 option2 = query(tree,lazy,mid+1,end,2*treeNode+1,st,nd);
	ans.s = option1.s + option2.s;
    ans.ss = option1.ss + option2.ss;
	return ans;
}

int main() {
	int t;
    cin>>t;
    int c;
    c=1;
    while(t--){
        int n,q;
        cin>>n>>q;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        node1* tree = new node1[4*n];
        node2* lazy = new node2[4*n];
        for(int i=0;i<4*n;i++){
        	tree[i].s=0;
        	tree[i].ss=0;
        	lazy[i].value =0;
        	lazy[i].type =0;
		}
        buildTree(a,tree,0,n-1,1);
        cout<<"Case "<<c<<":"<<endl;
        c++;
        while(q--){
            int op;
            cin>>op;
            int st,nd;
            cin>>st>>nd;
            st--;
            nd--;
            if(op==2){
                node1 ans = query(tree,lazy,0,n-1,1,st,nd);
                cout<<ans.ss<<endl;
            }
            else if(op == 1){
                int x;
                cin>>x;
                updateInc(a,tree,lazy,0,n-1,1,st,nd,x);
            }
            else if(op == 0){
                int x;
                cin>>x;
                updateSet(a,tree,lazy,0,n-1,1,st,nd,x);
            }
        }
        delete[] tree;
        delete[] lazy;
    }
	// Write your code here
}
