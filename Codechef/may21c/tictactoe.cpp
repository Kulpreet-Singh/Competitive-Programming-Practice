#include<bits/stdc++.h>
using namespace std;

 int main(){
 	int t;
 	cin>>t;
 	while(t--){
 		char s[3][3];
 		int cx = 0, co = 0, c_ = 0;
		int winx = 0, wino = 0;
		
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				cin>>s[i][j];
				
				if(s[i][j]=='X')
					cx++;
				else if(s[i][j]=='O')
					co++;
				else
					c_++;
			}
		}
		
		for(int i=0;i<3;i++){
			if(s[i][0] == s[i][1] && s[i][1] == s[i][2]){
				if(s[i][0] == 'X')
					winx++;
				else if(s[i][0] == 'O')
					wino++;
			}
		}
		
		for(int i=0;i<3;i++){
			if(s[0][i] == s[1][i] && s[1][i] == s[2][i]){
				if(s[0][i] == 'X')
					winx++;
				else if(s[0][i] == 'O')
					wino++;
			}
		}
		
		if(s[0][0] == s[1][1] && s[1][1] == s[2][2]){
			if(s[0][0] == 'X')
				winx++;
			else if(s[0][0] == 'O')
				wino++;
		}
		
		if(s[0][2] == s[1][1] && s[1][1] == s[2][0]){
			if(s[0][2] == 'X')
				winx++;
			else if(s[0][2] == 'O')
				wino++;
		}
		
		if(cx < co)
			cout<<3<<endl;
		else if(cx-1 > co)
			cout<<3<<endl;
		else if(cx>co && winx == 1 && wino == 0)
			cout<<1<<endl;
		else if(cx == co && winx == 0 && wino == 1)
			cout<<1<<endl;
		else if(c_ == 0 && ((winx + wino)==0))
			cout<<1<<endl;
		else if(c_ == 0 && winx==2)
			cout<<1<<endl;
		else if(c_ > 0 && ((winx + wino)==0))
			cout<<2<<endl;	
		else 
			cout<<3<<endl;
 	 }
 	 return 0;
 }
