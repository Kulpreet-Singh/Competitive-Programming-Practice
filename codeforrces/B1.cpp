#include<bits/stdc++.h>
using namespace std;

int main(){
	vector<bool> isPrime(1000000,true);
	isPrime[0] = isPrime[1]= false;
	for(int i=2;i*i<=1000000;i++){
		if(isPrime[i]){
			for(int j=i;j*i<=1000000;j++){
				isPrime[j*i] = false;
			}
		}
	}
	vector<int> primes;
	primes.push_back(1);
	for(int i=2;i<1000000;i++){
		if(isPrime[i]){
			primes.push_back(i);
		}
	}
	int n = primes.size();
	int t;
	cin>>t;
	while(t--){
		int d;
		cin>>d;
		int prev = 1;
		int c = 2;
		long long int val = 1;
		for(int i=1;i<n;i++){
			if(c>0){
				if((primes[i] - prev)>=d){
					prev = primes[i];
					c--;
					val *= primes[i];
				}
			}
			else{
				break;
			}
		}
		cout<<val<<endl;	
	}
	return 0;
}
