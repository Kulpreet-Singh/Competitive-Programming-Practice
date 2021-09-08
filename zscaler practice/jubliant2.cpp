#include<bits/stdc++.h>
using namespace std;

Result postDeliver(int input1, int input2[], int input3, int input4, int** input5){
	Result ans;
	vector<int> parent(input1, 0);
	for(int i=0;i<input1;i++){
		parent[i] = i;
	}
	for(int i=1;i<input1;i++){
		if(input2[i]-input2[i-1] <= input3){
			parent[i] = parent[i-1];
		}
	}
	for(int i=0;i<input4;i++){
		if(parent[input5[i][0]-1] == parent[input5[i][1]-1]){
			ans.output1[i] = 1;
		} else {
			ans.output1[i] = 0;
		}
	}
	
	return ans;
	
}

int main(){
	int n,
	vector<int> parent;
	
}
