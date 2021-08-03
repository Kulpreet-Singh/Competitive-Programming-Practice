#include <bits/stdc++.h>
using namespace std;

struct node{
    
    int c1;//max
	int c2;//maxs
};

void buildTree(int a[],node *tree,int start,int end,int treeNode){  
    if(start == end){
        tree[treeNode].c1 =a[start];
        tree[treeNode].c2 =INT_MIN;
        return;
    }
    int mid = (start+end)/2;
    buildTree(a,tree,start,mid,2*treeNode);
    buildTree(a,tree,mid+1,end,2*treeNode+1);
    vector<int> v;
    v.push_back(tree[2*treeNode].c1);
    v.push_back(tree[2*treeNode+1].c1);
    v.push_back(tree[2*treeNode].c2);
    v.push_back(tree[2*treeNode+1].c2);
    sort(v.begin(), v.end(), greater<int>());
	tree[treeNode].c1 = v[0];
    tree[treeNode].c2 = v[1];
}

node query(node *tree,int start,int end,int treeNode,int left,int right){
    if(start>right || end<left){
        node ans;
        ans.c1 = 0;
        ans.c2 = 0;
        return ans;
    }
    if(start >=left && end<=right){
        return tree[treeNode];
    }
    int mid = (start+end)/2;
    node option1 = query(tree,start,mid,2*treeNode,left,right);
    node option2 = query(tree,mid+1,end,2*treeNode+1,left,right);
    node ans;
    vector<int> v;
    v.push_back(option1.c1);
    v.push_back(option2.c1);
    v.push_back(option1.c2);
    v.push_back(option2.c2);
    sort(v.begin(), v.end(), greater<int>());
	ans.c1 = v[0];
    ans.c2 = v[1];
    return ans;
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
        
        set<int> s;
        
        node *tree = new node[4*n];
        buildTree(a,tree,0,n-1,1);
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                node ans = query(tree,0,n-1,1,i,j);
                s.insert(ans.c1-ans.c2);
            }
        }
        
        // for(int i=0;i<n-1;i++){
        //     int max= (a[i]>a[i+1])?a[i]:a[i+1];
        //     int maxs = min(a[i], a[i+1]);
        //     s.insert(max-maxs);
        //     for(int j=i+2;j<n;j++){
        //         if(a[j] > max){
        //             maxs = max;
        //             max = a[j];
        //         }else if(a[j] > maxs){
        //                 maxs = a[j];
        //         }
        //         s.insert(max-maxs);
        //     }
        // }
        // for(auto itr = s.begin(); itr!=s.end();itr++){
        //     cout<<*itr<<" ";
        // }
        cout<<s.size()<<endl;
        
    }
	return 0;
}
