#include<bits/stdc++.h>
using namespace std;

bool check(int n,int a[][1000],int i,int j){
    
//	for(int i=0;i<n;i++){
//        for(int j=0;j<n;j++){
//            cout<<a[i][j]<<" ";
//        }
//    }
//    cout<<endl;
	if(i==0){
        return true;
    }
    for(int ini=0;ini<i;ini++){
        if(a[ini][j]==1){
            return false;
        }
    }
    int inil=i;
    int injl=j;
    int inir=i;
    int injr=j;
    while(inil>0&&inir>0){
        if(injl>0){
            inil--;
        	injl--;
        	if(a[inil][injl]==1){
            	return false;
        	}
        }
        if(injr<(n-1)){
        	inir--;
        	injr++;
        	if(a[inir][injr]==1){
        	    return false;}
        }
        if((injl=0)&&(injr=(n-1)))
        	break;
    }
    
    // for(int ini=1;ini<i;ini++){
    //     for(int inj=(ini-j);inj<(ini+j);inj++){
    //         if(((ini+inj)==(i+j))&&(a[ini][inj]==1))
    //             return false;
    //         else if((ini==inj+(j-i))&&(a[ini][inj]==1))
    //             return false;
    //         else if((inj==j)&& (a[ini][inj]==1)){
    //             return false;
    //         }
    //     }
    // }
    return true;
}

void trace(int n,int in,int j){
    static int a[1000][1000]={0};
    if(in==n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<a[i][j]<<" ";
            }
        }
        cout<<endl;
        return;
    }
    while(j<n){
        if(check(n,a,in,j)){
            a[in][j]=1;
            trace(n,in+1,0);
            a[in][j]=0;
        }
        j++;
    }
    if(j==n){
        return;
    }
}

void placeNQueens(int n){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Print output as specified in the question
  */
	
	trace(n,0,0);

}
int main(){
	int n;
	cin>>n;
	placeNQueens(n);
	return 0;
}
