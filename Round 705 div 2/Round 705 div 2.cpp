#include<bits/stdc++.h>
using namespace std;

string incr(string a, int n){
	string out = "";
	out = out + a;
	int c = 1;
		for(int i=n-1;i>=0;i--){
			if(out[i] != '0'){
				out[i] = '0';
			}else{
				out[i] = '1';
				c = 0;
				break;
			}
		}
		return out;
}

string decr(string a, int n){
	string out = a;
	int c = 0;
	for(int i=n-1;i>=0;i--){
		if(c==0){
			if(out[i] != '0'){
				out[i] = '0';
				c = 1;
			}else{
				out[i] = '1';
				c = 0;
			}
		}else{
			if(out[i] != '0'){
				out[i] = '1';
				c = 1;
			}else{
				out[i] = '0';
				c = 1;
			}
		}				
	}
	return out;
}

string fn(string a, int n){
	string out = "";
	if(a[n-2] == '0' && a[n-1] == '0'){
		out = out + a;
	}
	if(a[n-2] == '0' && a[n-1] == '1'){
		for(int i=0;i<n-1;i++){
			out = out + "0"; 
		}
		out = out + "1";
	}
	if(a[n-2] == '1' && a[n-1] == '1'){
		for(int i=0;i<n-1;i++){
			out = out + "0"; 
		}
		out = out + "0";
	}
	if(a[n-2] == '1' && a[n-1] == '0'){
		out = incr(a,n);
		
	}
	return out;
}

string getXor(string a, string b, int n){
	string out = decr(a, n);
	string s1 = fn(out, n);
	string s2 = fn(b, n);
	string output = "";
	for(int i=0;i<n;i++){
		if(s1[i] == s2[i]){
			output = output + "0";
		}else{
			output = output + "1";
		}
	} 
	return output;
}

bool comp(string l, string r, int n){
	for(int i=0;i<n;i++){
		if(l[i] != r[i]){
			if(l[i] < r[i]){
				return true;
			}else{
				return false;
			}
		}
	}
	return true;
}

string max(string l, string r, int n){
	for(int i=0;i<n;i++){
		if(l[i] != r[i]){
			if(l[i] < r[i]){
				return r;
			}else{
				return l;
			}
		}
	}
	return l;
}

string fun(string l, string r, int n){
	string output = "";
	for(string i = l; comp(i,r,n); incr(i, n)){
		for(string j = i; comp(j, r, n);incr(j, n)){
			string out = getXor(i, j, n);
			if(output == ""){
				output = out;
			}
			output = max (output, out, n);
		}
	}
	return output;
}


int main(){
	// a, 1, a+1, 0
	
	int n;
	cin>>n;
	string l, r;
	cin>>l>>r;
	 string output = fun(l, r, n);
	 cout<<output<<endl;
	
	
	return 0;
}
