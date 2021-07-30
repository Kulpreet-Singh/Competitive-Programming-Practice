#include<bits/stdc++.h>
using namespace std;

void reverseSub(string &s,int in,int jn){
    for(int i=0;i<jn/2;i++){
        char a;
        a=s[i+in];
        s[i+in]=s[in+jn-i-1];
    	s[in+jn-i-1]=a;
    }
}

void invertSub(string &s,int in,int jn){
    for(int i=in;i<(in+jn);i++){
        s[i]='1';
    }
}

int main()
{
    int n,x,y;
    long cost=0;
    cin>>n>>x>>y;
    string s;
    cin>>s;
    if(x<y){
        int ini,inj;
        for(int i=0;i<n;){
            if(s[i]=='0'){
                ini=i;
                inj=0;
                int k=0;
                int t=0;
                int f=0;
                int j=1;
                while((s[i+j]=='0') && ((i+j)<n)){
                    j++;
                    k=j;
                }
                while((s[i+j]=='1') && ((i+j)<n)){
                    j++;
                    if((i+j)==n){
                        t=1;
                    }
                    inj++;
                    f=1;
                }
                if(t==1){
                    	// invertSub(s,ini,k);
                    	cost+=y;
                    	i+=(j-1);
                    	break;
    
                }
                if(j>1 && f==1){
                    
                    // reverseSub(s,ini,j);
                    cost+=x; 
                    i+=(j-1);
                }
                else if(f==0){
                    // invertSub(s,ini,j);
                    cost+=y;
                    i+=(j-1);
                    break;
                }

            }
            else
                i++;

        }
    }else{
        int ini;
        for(int i=0;i<n;){
            if(s[i]=='0'){
                ini=i;
                int f=0;
                int j=1;
                while((s[i+j]=='0') && ((i+j)<n)){
                    j++;
                }
                // invertSub(s,ini,j);
                cost+=y;
            	i+=j;

            }
            else
                i++;

        }
    }
    
    cout<<cost<<endl;
	return 0;
}

