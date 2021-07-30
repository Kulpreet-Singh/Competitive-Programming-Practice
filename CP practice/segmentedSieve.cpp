#include <bits/stdc++.h>
using namespace std;

#define max 1000001

vector<int> sieve(){
    vector<bool> isPrime(max,true);
    for(int i=2;i*i<max;i++){
        if(isPrime[i] == true){
            for(int j=i*i;j<max;j+=i){
                isPrime[j] = false;
            }
        }
    }
    
    vector<int> primes;
    primes.push_back(2);
    for(int i=3;i<max;i+=2){
        if(isPrime[i]){
            primes.push_back(i);
        }
    }
    return primes;
}

void segmentedSieve(long long l, long long r, vector<int> &primes){
    vector<bool> isPrime(r-l+1,true);
    for(int i=0;primes[i]*(long long)primes[i] <=r;i++){
        int currPrime = primes[i];
        long long base = (l/currPrime)*currPrime;
        if(base<l){
            base+=currPrime;
        }
        for(long long j=base;j<=r; j+=currPrime){
            if(j == currPrime){
                continue;
            }
            isPrime[j-l] = false;
        }
    }
    for(int i=0;i<=r-l;i++){
        if(isPrime[i]){
            cout<<i+l<<endl;
        }
    }
}

int main()
{
	// Write your code here
    vector<int> primes = sieve();
    int t;
    cin>>t;
    while(t--){
        long long l,r;
        cin>>l>>r;
        segmentedSieve(l,r,primes);
    }
	return 0;
}
