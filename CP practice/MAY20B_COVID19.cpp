#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
//		int x[11]={0};
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
//			x[a[i]] = 1;
		}
		int min = INT_MAX;
		int max= INT_MIN;
//		int count = 0;
		sort(a,a+n);
		for(int i=0;i<n;i++){
			int count = 1;
//			int temp = a[i];
			for(int j=i-1;j>=0;j--){
				if((a[j+1]-a[j])>2){
					break;
				}
				count++;
			}
			for(int j=i+1;j<n;j++){
				if((a[j]-a[j-1])>2){
					break;
				}
				count++;
			}
			if(max<count){
				max = count;
			}
			if(min>count){
				min = count;
			}
		}
		cout<<min<<" "<<max<<endl;
	}
	return 0;
}
