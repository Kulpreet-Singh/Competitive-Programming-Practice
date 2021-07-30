#include<iostream>
using namespace std;

string alpha[] = {"ka","kha","ga","gha","na","cha","chha","ja","jha","ana","tta","ttha","dda","ddha","nna","ta","tha","da","dha","na","pa","pha","ba","bha","ma","ya","ra","la","va","sha","sh","sa","ha"};

int main(){
	int arr1[] = {19,14,13};
	int arr2[] = {1,14,3};

	int shift = 1;
	
	for(;shift<33;shift++){
		cout<<"shift = "<<shift<<endl;
	
		for(int i=0;i<3;i++){
			cout<<alpha[(arr1[i]+shift)%33]<<" ";
		}
		for(int i=0;i<3;i++){
			cout<<alpha[(arr2[i]+shift)%33]<<" ";
		}
		cout<<endl;
		
		for(int i=0;i<3;i++){
			cout<<alpha[(arr2[i]+shift)%33] <<" ";
		}
		for(int i=0;i<3;i++){
			cout<<alpha[(arr1[i]+shift)%33] <<" ";
		}
		cout<<endl;
		
	}
}
