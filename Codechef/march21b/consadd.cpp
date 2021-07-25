#include<iostream>
#include<vector>
using namespace std;

bool func(int r, int c, int x, vector<vector<int>> &a, vector<vector<int>> &b){
    if(r<x && c<x){
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(a[i][j]!=b[i][j]){
                    return false;
                }
            }
        }
        return true;
    }
    else{
        if(r>=x && c>=x){
            for(int i=0;i<c;i++){
                for(int j=0;j<r-x+1;j++){
                    if(a[j][i]!=b[j][i]){
                        int diff = b[j][i] - a[j][i];
                        for(int k = j; k < j+x; k++){
                            a[k][i]+=diff;
                        }
                    }
                }
            }
            for(int i=0;i<r;i++){
                for(int j=0;j<c-x+1;j++){
                    if(a[i][j]!=b[i][j]){
                        int diff = b[i][j] - a[i][j];
                        for(int k = j; k < j+x; k++){
                            a[i][k]+=diff;
                        }
                    }
                    if(j==c-x){
                        for(int k=c-x+1;k<c;k++){
                            if(a[i][k] != b[i][k]){
                                return false;
                            }
                        }
                    }
                }
            }
            return true;
        }else if(c<x){
            for(int i=0;i<c;i++){
                for(int j=0;j<r-x+1;j++){
                    if(a[j][i]!=b[j][i]){
                        int diff = b[j][i] - a[j][i];
                        for(int k = j; k < j+x; k++){
                            a[k][i]+=diff;
                        }
                    }
                    if(j==r-x){
                        for(int k=r-x+1;k<r;k++){
                            if(a[k][i] != b[k][i]){
                                return false;
                            }
                        }
                    }
                }
            }
            return true;
        }else if(r<x){
            for(int i=0;i<r;i++){
                for(int j=0;j<c-x+1;j++){
                    if(a[i][j]!=b[i][j]){
                        int diff = b[i][j] - a[i][j];
                        for(int k = j; k < j+x; k++){
                            a[i][k]+=diff;
                        }
                    }
                    if(j==c-x){
                        for(int k=c-x+1;k<c;k++){
                            if(a[i][k] != b[i][k]){
                                return false;
                            }
                        }
                    }
                }
            }
            return true;
        }
    }
}


int main(){
    int t;
    cin>>t;
    while(t--){
        int r, c, x;
        cin>>r>>c>>x;
        vector<vector<int>> a(r, vector<int>(c, 0));
        vector<vector<int>> b(r, vector<int>(c, 0));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cin>>a[i][j];
            }
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cin>>b[i][j];
            }
        }

        bool ans = func(r, c, x, a, b);
        if(ans){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}