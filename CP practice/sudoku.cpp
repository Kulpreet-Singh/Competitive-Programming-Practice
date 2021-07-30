#include <iostream>
using namespace std;
int grid[9][9];
bool check(int num,int x,int y){
    for(int i=0;i<9;i++){
        if(grid[x][i]==num||grid[i][y]==num){
            return false;
        }
    }
    for(int i=3*(x/3);i<3*(x/3)+3;i++){
        for(int j=3*(y/3);j<3*(y/3)+3;j++){
            if(grid[i][j]==num){
                return false;
            }
        }
    }
    return true;
}
bool solver(){
	for(int i=0;i<9;i++){
		    for(int j=0;j<9;j++){
		        cout<<grid[i][j];
		    }
		    cout<<endl;
		}
	cout<<endl;
    int i,j;
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            if(grid[i][j]==0){
                break;
            }
            
        }
        if(j!=9){
            	break;
			}
    }
    if(i==9){
        return true;
    }
    for(int num=1;num<=9;num++){
        if(check(num,i,j)){
            grid[i][j]=num;
            if(solver()){
                return true;
            }
            // grid[i][j]=0;
        }
    }
    if(grid[i][j]==0){
        return false;
    }
}

int main() {
	// your code goes here
	for(int i=0;i<9;i++){
	    int x;
	    cin>>x;
	    for(int j=8;j>=0;j--){
	        grid[i][j]=x%10;
	        x/=10;
	    }
	}
	
	cout<<endl;
	if(solver()){
		for(int i=0;i<9;i++){
		    for(int j=0;j<9;j++){
		        cout<<grid[i][j];
		    }
		    cout<<endl;
		}
	}
	
	return 0;
}

