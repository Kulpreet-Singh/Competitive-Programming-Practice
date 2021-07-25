#include<bits/stdc++.h>
using namespace std;

#define max 1000000


int divisor(int a) 
{ 
    int div = 1, count = 0; 
    for (int i = 2; i <= sqrt(a); i++) { 
        while (a % i == 0) { 
            count++; 
            a = a / i; 
        } 
        div = div * (count + 1); 
        count = 0; 
    } 

    if (a > 1) { 
        div = div * (2); 
    } 
    return div; 
} 

vector<int> oddDivisors() { 
	vector<int> v;
    int res = 0; 
    for (int i = 1; i <= max; ++i) { 
        int divCount = divisor(i); 
        if (divCount % 2) { 
            v.push_back(i);
        } 
    } 
    return v; 
} 


int main(){
	vector<int> factors = oddDivisors();
	for(int i=0;i<factors.size();i++){
		cout<<factors[i]<<" ";
	}
	cout<<endl<<divisor(100);
//	int t;
//	cin>>t;
//	while(t--){
//		int x = 0;
//		for(int i=0;i<factors.size();i++){
//			cout<<factors[i] <<flush;
//			cin>>x; 
//			if(x==1){
//				break;
//			}
//			if(x==0){
//				continue;
//			}
//			if(x==-1){
//				break;
//			}
//			
//		}
//	}
	return 0;
}
