#include <iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n,0);
        for (int i = 0; i <n; i++) 
            cin>>v[i];
        int maxi=1;
        
        for(int i=0;i<n-1;i++){
            float m = INT_MIN;
            int mx = 0;
            for(int j=i+1;j<n;j++){
                if(m <= (float)(v[j]-v[i])/(j-i)){
                    m = (float)(v[j]-v[i])/(j-i);
                    mx = j-i;
                }
            }
            if(mx > maxi){
                maxi = mx;   
            }
            i+=mx-1;
        }
        cout<<maxi<<endl;
    }
    return 0;
}
