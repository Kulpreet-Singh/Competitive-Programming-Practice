#include <bits/stdc++.h>
using namespace std;

int min_health(int** input,int si,int sj,int ei,int ej){
    if(si==ei && sj==ej){
        return 1;
    }
    if(si==ei || sj==ej){
        return INT_MAX;
    }
    int option1 = max(1,min_health(input,si+1,sj,ei,ej)-input[si+1][sj]);
    int option2 = max(1,min_health(input,si,sj+1,ei,ej) - input[si][sj+1]);
//    int ans=INT_MIN;
    int ans=min(option1,option2);
    return ans;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int r,c;
        cin>>r>>c;
        int **grid = new int*[r];
        for(int i=0;i<r;i++){
        	grid[i]=new int[c];
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cin>>grid[i][j];
            }
        }
    	int res= min_health(grid,0,0,r-1,c-1);
        cout<<res<<endl;
    	for(int i=0;i<r;i++){
            delete[] grid[i];
        }
        delete [] grid;
    }
    
    return 0;
}

