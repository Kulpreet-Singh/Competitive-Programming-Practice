#include <bits/stdc++.h> 
using namespace std; 

#define mod 1000000007
typedef long long int ll;

ll gcd(ll a, ll b) 
{ 
	if (a == 0) 
		return b; 
	return gcd(b % a, a); 
} 

ll findGCD(ll arr[], int n) 
{ 
	ll result = arr[0]; 
	for (int i = 1; i < n; i++) 
	{ 
		result = gcd(arr[i], result); 

		if(result == 1) 
		{ 
			return 1; 
		} 
	} 
	return result; 
} 

int main() 
{
	int n, q;
	cin>>n>>q;
	ll* a = new ll[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	while(q--){
		int i;
		ll x;
		cin>>i>>x;
		a[i-1] = (a[i-1] * x) % mod;
		ll ans = findGCD(a, n);
		cout<<ans<<endl;
	}
	delete[] a;
} 

