#include<bits/stdc++.h>
using namespace std;

int findDigits(int a){
	int count =1;
	while(a/10){
		a/=10;
		count++;
	}
	return count;
}

int findMSD(int a){
	int msd = a;
	while(msd/10){
		msd/=10;
	}
	return msd;
}

void print(stack<int> s) 
{ 
    while (!s.empty()) 
    { 
        cout<<s.top()<<" "; 
        s.pop(); 
    } 
    cout<<endl; 
} 

void printEle(stack<int> s){
	while(!s.empty()){
		if(findDigits(s.top()) == 2){
			int a = s.top()/10;
			int b = s.top()%10;
			for(int i=a;i>=b;i--){
				cout<<i<<" ";
			}
		}
		else if(findDigits(s.top()) == 1){
			cout<<s.top()<<" ";
		}
		s.pop();
	}
}
int form(int a,int b){
	int ten = max(a,b);
	int one = min(a,b);
	return (ten*10)+one;
}
int form(int a,int b,int c){
	int ten = max(a,max(b,c));
	int one = min(a,min(b,c));
	return (ten*10)+one;
}
int form(int a,int b,int c,int d){
	int ten = max(max(a,d),max(b,c));
	int one = min(min(a,d),min(b,c));
	return (ten*10)+one;
}

int main(){
	int n;
	cin>>n;
	int * a = new int[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	stack<int> s1;
	stack<int> s2;
	for(int i=0;i<n;i++){
		s1.push(a[i]);
	}
	while(!s1.empty()){
		if(s2.empty()){
			int x = s1.top();
			s1.pop();
			s2.push(x);
			continue;
		}
		int x = s1.top();
		int y = s2.top();
		if(findDigits(x) == 1 && findDigits(y) == 1){
			if(abs(x-y) == 1){
				int res = form(x,y);
				s1.pop();
				s2.pop();
				s2.push(res);
			continue;}
		}
		else if(findDigits(x) == 1 && findDigits(y) == 2){
			int a = y/10;
			int b = y%10;
			if(x>a){
				s1.pop();
				s2.push(x);
				continue;
			}
			if(abs(a-x)==1||abs(b-x)==1){
				s1.pop();
				s2.pop();
				int res = form(a,b,x);
				s2.push(res);	
			continue;
			}

		}
		else if(findDigits(x) == 2 && findDigits(y) == 1){
			int a = x/10;
			int b = x%10;
			if(abs(a-y)==1||abs(b-y)==1){
				s1.pop();
				s2.pop();
				int res = form(a,b,y);
				s2.push(res);	
			continue;}
		}
		else if(findDigits(x) == 2 && findDigits(y) == 2){
			int a = x/10;
			int b = x%10;
			int c = y/10;
			int d = y%10;
			
			if(abs(a-d)==1||abs(b-c)==1){
				s1.pop();
				s2.pop();
				int res = form(a,b,c,d);
				s2.push(res);	
			continue;}
		}
		if(s1.empty()){
			break;
		} 
		if((s2.top() < s1.top())&& (findMSD(s2.top()) < findMSD(s1.top()))){
			int x = s1.top();
			s1.pop();
			s2.push(x);
		}
		else{
			int temp = s1.top();
			s1.pop();
			s1.push(s2.top());
			s2.pop();
			s1.push(temp);
		}
		
	}
	print(s2);
	printEle(s2);
	return 0;

}
