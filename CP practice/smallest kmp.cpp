#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		char* p = new char[100000];
		char *s = new char[100000];
		cin>>s>>p;
		int n = strlen(s);
		int m = strlen(p);
		
		int arr[26] = {0};
	    int arr2[26] = {0};
		
		for(int i=0;i<n;i++){
		    int in = s[i]-'a';
			arr[in]++;
		}
		for(int i=0;i<m;i++){
			int in2 = p[i]-'a';
			arr2[in2]++;
		}
		
		char second=p[0];
		for(int i=0;i<m;i++){
			if(second!=p[i]){
				second = p[i];
				break;
			}
		}
		
		char* output = new char[n+1];
		int k = 0;
		for(int i=0;i<26;i++){
			while(arr[i]>0){
				if((i==(p[0]-'a')) && (((arr[i]==arr2[i]) && second>p[0]) || (second<p[0]) )){
					int j=0;
					while(j<m){
						arr[(p[j]-'a')]--;
						arr2[(p[j]-'a')]--;
						output[k++] = p[j];
						j++;
					}
				}
				if(arr[i]>arr2[i]){
					arr[i]--;
					output[k++] = (char)('a'+i);
				}
				if((i!=(p[0]-'a')) && (arr[i]==arr2[i])){
					break;
				}
			}
		}
		output[k]='\0';
		for(int i=0;i<k+1;i++){
			cout<<output[i];
		}
		cout<<endl;
		delete[] output;
		delete[] p;
		delete[] s;
	}
}


