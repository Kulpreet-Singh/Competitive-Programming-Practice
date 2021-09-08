#include<bits/stdc++.h>
using namespace std;

int last3num(int p){
	int num = 0;
	for(int i=0;i<3;i++){
		num += (pow(10,i)*(p%10));
		p/=10;
	}
	return num;
}

int helper(int n, int p){
	vector<int> day(50,0);
	for(int i=1;i<50;i++){
		day[i] = i+day[i-1];
	}
	int passDay = last3num(p);
	int index = lower_bound(day.begin(), day.end(), passDay) - day.begin();
	p -= passDay;
	p -= index * 5000;
	int k = p/5000;
	return k;
}

int main(){
	int n, p;
	cin>>n>>p;
	cout<<helper(n, p);	
	return 0;
}
