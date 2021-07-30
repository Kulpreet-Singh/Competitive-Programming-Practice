#include<bits/stdc++.h>
using namespace std;

void countSort(int *a, int n,int place){
	int *count = new int[n];
	for(int i=0;i<n;i++){
		count[i] =0;
	}
	for(int i=0;i<n;i++){
		count[(a[i]/place)%10]+=1;
	}
	for(int i=8;i>=0;i--){
		count[i] += count[i+1];
	}
	int * output = new int[n];
	for(int i=n-1;i>=0;i--){
		output[count[(a[i]/place)%10]-1] = a[i];
		count[(a[i]/place)%10]-=1;
	}
	for(int i=0;i<n;i++){
		a[i] = output[i];
	}
	delete[] count;
	delete[] output;
}

void radixSort(int *a,int n){
	int max = a[0];
	for(int i=1;i<n;i++){
		if(a[i]>max){
			max =a[i];
		}
	}
	int digits =0;
	while(max){
		max = max/10;
		digits++;
	}
	for(int i=0;i<digits;i++){
		countSort(a,n,pow(10,i));
		for(int j=0;j<n;j++){
			cout<<a[j]<<" ";
		}
		cout<<endl;
	}
}


int main(){
	int n;
	cin>>n;
	int * a = new int[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	radixSort(a,n);
	
	return 0;
}
