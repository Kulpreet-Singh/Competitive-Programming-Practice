#include <bits/stdc++.h>
using namespace std;

struct edge{
    int v1;
    int v2;
    int w;
};

int topParent(int parent[], int v1){
    while(parent[v1] != v1){
        v1 = parent[v1];
    }
    return v1;
}

bool comp(edge e1,edge e2){
    if(e1.w == e2.w){
        if(e1.v1 == e2.v1){
            return e1.v2 < e2.v2;
        }
        return e1.v1<e2.v1;
    }
    return e1.w < e2.w;
}

bool comp1(edge e1,edge e2){
    if(e1.v1 == e2.v1){
        if(e1.v2 == e2.v2){
            return e1.w < e2.w;
        }
        return e1.v2<e2.v2;
    }
    return e1.v1 < e2.v1;
}

int main()
{
  int V, E;
  cin >> V >> E;
    edge edges[E];
	for(int i=0;i<E;i++){
        cin>>edges[i].v1>>edges[i].v2>>edges[i].w;
    }
    sort(edges,edges+E,comp);
    int count =0;
    edge output[V-1];
	int parent[V];
    for(int i=0;i<V;i++){
    	parent[i] = i;
    }
    int i=0;
    int o = 0;
    while(count<V-1){
        if(topParent(parent,edges[i].v1) != topParent(parent,edges[i].v2)){
            output[o].v1 = min(edges[i].v1,edges[i].v2);
            output[o].v2 = max(edges[i].v1,edges[i].v2);
            output[o].w = edges[i].w;

            parent[topParent(parent,edges[i].v2)] = topParent(parent,edges[i].v1);
            count++;
            o++;
        }
        i++;
    }
    sort(output,output+V-1,comp1);
    for(i=0;i<V-1;i++){
        cout<<output[i].v1<<" "<<output[i].v2<<" "<<output[i].w<<endl;
    }

  return 0;
}

