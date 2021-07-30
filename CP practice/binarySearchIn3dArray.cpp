#include<bits/stdc++.h>
using namespace std;

int main(){
	int x,y,z,n;
	cin>>x>>y>>z>>n;
	int a[x][y][z];
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			for(int k=0;k<z;k++){
				cin>>a[i][j][k];
			}
		}
	}
	int inx=-1;
	int iny=-1;
	int inz=-1;
	int count =0;
	//for row wise
	int beg = 0;
	int end = x-1;
	while(beg<=end){
		int mid = (beg + end )/2;
		count++;
		if(a[mid][0][0]<=n && a[mid][y-1][z-1]>=n){
			inx = mid;
			break;
		}
		else if(a[mid][0][0]>n){
			end = mid -1;
		}
		else if(a[mid][y-1][z-1]<n){
			beg = mid+1;
		}
	}
	if(inx ==-1){
		cout<<0<<endl;
		cout<<count<<endl;
		return 0;
	}
	cout<<a[inx][0][0]<<" "<<a[inx][y-1][z-1]<<endl;
	//for col wise
	beg = 0;
	end = y-1;
	while(beg<=end){
		int mid = (beg + end )/2;
		count++;
		if(a[inx][mid][0]<=n && a[inx][mid][z-1]>=n){
			iny = mid;
			break;
		}
		else if(a[inx][mid][0]>n){
			end = mid -1;
		}
		else if(a[inx][mid][z-1]<n){
			beg = mid+1;
		}
	}
	if(iny ==-1){
		cout<<0<<endl;
		cout<<count<<endl;
		return 0;
	}
	cout<<a[inx][iny][0]<<" "<<a[inx][iny][z-1]<<endl;
	//for 3rd dimension wise
	beg = 0;
	end = z-1;
	while(beg<=end){
		int mid = (beg + end )/2;
		count++;
		if(a[inx][iny][mid]<=n && a[inx][iny][mid]>=n){
			inz = mid;
			break;
		}
		else if(a[inx][iny][mid]>n){
			end = mid -1;
		}
		else if(a[inx][iny][mid]<n){
			beg = mid+1;
		}
	}
	if(inz ==-1){
		cout<<0<<endl;
		cout<<count<<endl;
		return 0;
	}
	cout<<inx<<" "<<iny<<" "<<inz<<endl;
	cout<<count<<endl;
	return 0;
}
