#include<bits/stdc++.h>
using namespace std;

struct rect{
	int l;
	int h;
};
bool comp(rect r1,rect r2){
	return r1.l<r2.l;
}
int main(){
	int n;
	cin>>n;
	rect r[n];
	int l,h;
	int area=0;
	for(int i=0;i<n;i++){
		cin>>l>>h;
		r[i].l=l/2;
		r[i].h=h;
	}
	sort(r,r+n,comp);
	int currh;
	currh=r[n-1].h;
	l=r[n-1].l;
	int j=n-2;
	for(int i=l;i>0;i--){
		while(r[j].l==i && j>=0){
			if(r[j].h>currh){
				currh=r[j].h;
			}
			j--;
		}
		area+=currh;
	}
	cout<<area*2<<endl;
}

