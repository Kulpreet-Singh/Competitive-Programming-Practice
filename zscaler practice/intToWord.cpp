// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include<bits/stdc++.h>
using namespace std;
const string EMPTY = "";
 
const string X[] = { EMPTY, "One", "Two", "Three", "Four", "Five",
                "Six", "Seven", "Eight", "Nine", "Ten", "Eleven",
                "Twelve", "Thirteen", "Fourteen", "Fifteen",
                "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
 
const string Y[] = { EMPTY, EMPTY, "Twenty ", "Thirty ", "Forty ", "Fifty ",
                "Sixty ", "Seventy ", "Eighty ", "Ninety " };
 
string convertToDigit(int n, string suffix)
{
    
    if (n == 0) {
        return EMPTY;
    }
 
    if (n > 19) {
        return Y[n / 10] + X[n % 10] + suffix;
    }
    else {
        return X[n] + suffix;
    }
}
 
string solution(int n)
{
    string res;
    if(n == 0){
        res = "Zero";
        return res;
    }
    res = convertToDigit((n % 100), "");
 
    if (n > 100 && n % 100) {
        res = res;
    }
 

    res = convertToDigit(((n / 100) % 10), " Hundred ") + res;

    res = convertToDigit(((n / 1000) % 100), " Thousand ") + res;

    res = convertToDigit(((n / 100000) % 10), " Hundred ") + res;
 
    res = convertToDigit(((n / 1000000) % 100), " Million ") + res;
 
    res = convertToDigit(((n / 100000000) % 10), " Hundred ") + res;

    res = convertToDigit(((n / 1000000000) % 100), " Billion ") + res;
 
    res = convertToDigit(((n / 100000000000) % 10), " Hundred ") + res;
 
 
    return res;
}

int main(){
	cout<<solution(1234567891);
	return 0;
}
