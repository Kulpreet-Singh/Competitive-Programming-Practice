 #include<iostream>
 using namespace std;
 
 void swap(int &a,int &b,int &count){
	if(a==b){
		return;
	}
 	int temp = a;
 	a=b;
 	b=temp;
	count++;
 }
 
 int main(){
 	int n;
 	cin>>n;
 	int a[n][n] ={0};
 	for(int i=0;i<n;i++){
 		for(int j=0;j<n;j++){
 			cin>>a[i][j];
		}
	}
	int count =0;
	for(int k=0;k<n;k++){
		
		for(int i=0;i<n;i++){
			int min = INT_MAX;
			int in = k;
			for(int j=k;j<n;j++){
				if(a[j][i]<min){
					min = a[j][i];
					in = j;
				}
			}
			swap(a[k][i],a[in][i],count);
		}
		for(int i=0;i<n;i++){
			int min = INT_MAX;
			int in = k;
			for(int j=k;j<n;j++){
				if(a[i][j]<min){
					in = j;
					min = a[i][j];
				}
			}
			swap(a[i][k],a[i][in],count);
		}
	}
	cout<<count<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<a[i][j]<<" ";
		}
	}	
 }
