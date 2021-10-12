#include<bits/stdc++.h>
using namespace std;

int reduce(int input1, int input2[]) 
    {
    	vector<pair<int, int>> mp;
    	
    	for(int i=0;i<input1;i++){
    		mp.push_back(make_pair(input2[i],i+1));
		}
		
        int n= input1;
        int max=0;
        sort(mp.begin(),mp.end());
        for(int i=0;i<n-1;i++)
        {
            int sum=0;
            auto itr = mp.begin();
            int k=0;
			while(k<i){
				itr++;
				k++;
			}
			auto itr2 = itr;
            while(itr!=mp.end())
            {
                sum = sum + itr->first * itr->second;
            	if(itr->second > itr2->second){
            		itr->second -= 1;
				}
                itr++;
            }
            if(sum>max)
                max=sum;
        }
        return max;   
    }
    
    int main(){
    	int n=5;
    	int input[] = {-1,-9,0,5,-7};
    	cout<<reduce(n, input)<<endl;
    	return 0;
	}
