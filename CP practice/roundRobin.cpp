#include<bits/stdc++.h>
using namespace std;

struct pro{
	int id;
	int at;
	int bt;
};

bool comp(pro a, pro b){
	if(a.at == b.at){
		if(a.id < b.id){
			return true;
		}
	}
	if(a.at < b.at){
		return true;
	}
	return false;
}


vector<int> roundRobin(pro *arr, int n,int tq =1){
	vector<int> v;
	int t = arr[0].at;
	queue<pro> q;
	int i=0;
	while(i<n){
		while(i<n && t >= arr[i].at){
			q.push(arr[i]);
			i++;
		}
		while(!q.empty()){
			pro curr = q.front();
			q.pop();
			curr.bt-= tq;
			v.push_back(curr.id);
			t+=tq;
			while(i<n && t >= arr[i].at){
				q.push(arr[i]);
				i++;
			}
			if(curr.bt>0){
				q.push(curr);
			}
			
		}
		t++;
	}
	return v;
}

int main(){
	int n;
	cin>>n;
	pro *arr = new pro[n];
	for(int i=0;i<n;i++){
		cin>>arr[i].id>>arr[i].at>>arr[i].bt;
	}
	sort(arr,arr+n,comp);
//	for(int i=0;i<n;i++){
//		cout<<arr[i].id<<" "<<arr[i].at<<" "<<arr[i].bt<<endl;
//	}
	int tq =1;
	vector<int> v = roundRobin(arr,n,tq);
	vector<int>::iterator itr;
	for( itr = v.begin();itr!=v.end();itr++){
		cout<<*itr<<" ";
	}
	cout<<endl;
}
