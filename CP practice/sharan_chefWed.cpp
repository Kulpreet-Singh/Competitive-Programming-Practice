#include <iostream>
#include<unordered_map>
using namespace std;
int helper(int*arr,int si,int ei,int cost)
{
    if(si==ei)
    {
        return cost;
    }
    unordered_map<int,int> map;
    int index=-1,count=0,opt1,opt2;
    for(int i=si;i<=ei;i++)
    {
        if(map.count(arr[i])>0)
        {
            if(index==-1)
            {index=i;}
            map[arr[i]]++;
        }
        else
        {
          map[arr[i]]=1;  
        }
    }
    if(index==-1)
    {
        return cost;
    }
    else
    {
        for(auto it=map.begin();it!=map.end();it++)
        {
            if(it->second!=1)
            {count=count+it->second;}
        }
        opt1=cost+count;
        opt2=cost+helper(arr,index,ei,cost);
        return min(opt1,opt2);
    }
}
int main()
{
    int test;
    cin>>test;
    for(int i=0;i<test;i++)
    {
        int n,k;
        cin>>n>>k;
        int* arr=new int[n];
        for(int j=0;j<n;j++)
        {
            int num;
            cin>>num;
            arr[j]=num;
        }
        int a=helper(arr,0,n-1,k);
        cout<<a<<endl;
    }
    return 0;
}
