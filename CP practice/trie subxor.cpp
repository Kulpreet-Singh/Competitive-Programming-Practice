#include<bits/stdc++.h>
using namespace std;

int dp[1000010] = {0};

class trieNode{
    public:
    long long int count;
    trieNode* left;
    trieNode* right;
    
    trieNode(){
        count = 0;
        left = NULL;
        right = NULL;
    }
};

void insert(trieNode* head,long long int n){
    if(dp[n] == 1){
        return;
    }
    dp[n] = 1;
    trieNode* curr = head;
    for(int i=31;i>=0;i--){
        curr->count++;
    	int b = (n>>i)&1;
        if(b==0){
            if(!curr->left){
                curr->left = new trieNode();
            }
            curr = curr->left;
        }
        else{
            if(!curr->right){
                curr->right = new trieNode();
            }
            curr = curr->right;
        }
    }
}

long long int subArrayXor(trieNode* head,long long int *a,int n, int k){
    long long int xr = 0;
    insert(head,0);
    long long int count = 0;
    for(int i=0;i<n;i++){
        xr = xr ^ a[i];
        insert(head,xr);
        int val = xr;
        int currXor = 0;
        trieNode* curr = head;
        for(int j=31;j>=0;j--){
            int b = (val>>j)&1;
            int ki = (k>>j)&1;
            if(b==0){
                if(ki==1){
                    if(curr->left)
                    	count += curr->left->count;
                    if(curr->right){
                    	curr = curr->right;
                	}else{
                    	break;
                	}
                }
                else{
                    if(curr->left){
                    	curr = curr->left;
                	}
                	else{
                        // currXor ++;
                    	break;
                	}
                }
            }
            else{
                if(ki==1){
                    if(curr->right)
                    	count += curr->right->count;
                    if(curr->left){
                    	curr = curr->left;
                	}else{
                    	break;
                	}
                }
                else{
                    if(curr->right){
                    	curr = curr->right;
                	}
                	else{
                        // currXor ++;
                    	break;
                	}
                }
            }
        // insert(head,xr);
        }
        // if(currXor == 0)
        	count--;
    }
    return count;
}

void DeleteTrie(trieNode* head){
    if(head->left){
        DeleteTrie(head->left);
    }
    if(head->right){
        DeleteTrie(head->right);
    }
    delete head;
}

int main() {

	// Write your code herei
    int t;
    cin>>t;
    while(t--){
    	int n,k;
        cin>>n>>k;
        long long int *a=new long long int[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        trieNode* head = new trieNode();
        long long int ans = subArrayXor(head,a,n,k);
        cout << ans << endl;
        delete[] a;
        DeleteTrie(head);
    }
    return 0;
}

