#include<bits/stdc++.h>
using namespace std;

void func(int n, int k, int a, int b, int day, int max, int min, int &count){
	if(day == n){
		if(k<=b && k>=a){
			count++;
		}
		return;
	}
	if(k>max){
		max = k;
	} 
	if(k<min){
		min = k;
	}
	func(n, max+1, a, b, day+1, max, min, count);
	func(n, max+2, a, b, day+1, max, min, count);
	func(n, min-1, a, b, day+1, max, min, count);
	func(n, min-2, a, b, day+1, max, min, count);
}

int main(){
	int n,k,a,b;
	cin>>n>>k>>a>>b;
	int count = 0;
	func(n,k,a,b, 1, k, k, count);
	cout<<count;
}
