#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		string a;
		cin>>a;
		stack<char> s1, s2, s3;
		// ( 
		// ) 
		map<char, char> m1, m2, m3;
		m1.insert(make_pair(a[0], '('));
		m2.insert(make_pair(a[0], '('));
		m3.insert(make_pair(a[0], '('));
		if(a[0] == 'A'){
			m1.insert(make_pair('B', '('));
			m1.insert(make_pair('C', ')'));
			m2.insert(make_pair('B', ')'));
			m2.insert(make_pair('C', '('));
			m3.insert(make_pair('B', ')'));
			m3.insert(make_pair('C', ')'));
		} else if(a[0] == 'B'){
			m1.insert(make_pair('A', '('));
			m1.insert(make_pair('C', ')'));
			m2.insert(make_pair('A', ')'));
			m2.insert(make_pair('C', '('));
			m3.insert(make_pair('A', ')'));
			m3.insert(make_pair('C', ')'));
		} else if(a[0] == 'C'){
			m1.insert(make_pair('B', '('));
			m1.insert(make_pair('A', ')'));
			m2.insert(make_pair('B', ')'));
			m2.insert(make_pair('A', '('));
			m3.insert(make_pair('B', ')'));
			m3.insert(make_pair('A', ')'));
		}
		int n = a.length();
		int flag = 0;
		int i=0;
		for(i=0;i<n;i++){
			if(s1.empty() || m1[a[i]] == '('){
				s1.push(m1[a[i]]);
			}
			else if(m1[a[i]] == ')' && s1.top() == '('){
				s1.pop();
			} else{
				break;
			}
		}
		if(i==n && s1.empty()){
			flag = 1;
			cout<<"YES"<<endl;
		}
		if(flag == 0){
			for(i=0;i<n;i++){
				if(s2.empty() || m2[a[i]] == '('){
					s2.push(m2[a[i]]);
				}
				else if(m2[a[i]] == ')' && s2.top() == '('){
					s2.pop();
				} else{
					break;
				}
			}
			if(i==n && s2.empty()){
				flag = 1;
				cout<<"YES"<<endl;
			}
		}
		if(flag == 0){
			for(i=0;i<n;i++){
				if(s3.empty() || m3[a[i]] == '('){
					s3.push(m3[a[i]]);
				}
				else if(m3[a[i]] == ')' && s3.top() == '('){
					s3.pop();
				} else{
					break;
				}
			}
			if(i==n && s3.empty()){
				flag = 1;
				cout<<"YES"<<endl;
			}
		}
		if(flag == 0){
			cout<<"NO"<<endl;
		}
		 
	}
	
	return 0;
}
