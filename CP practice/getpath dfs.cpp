#include <bits/stdc++.h>
using namespace std;

// bool findDFS(int** edges,int V, int sv,int ev,bool *visited,vector<int> &v){
//     if(sv == ev){
//         return true;
//     }
//     for(int i=0;i<V;i++){
//         if(i!=sv){
//              if(edges[sv][i] == 1){
//                  if(!visited[i]){
//                      visited[i] = true;
//                      if(i == ev){
//                          v.push_back(i);
//                          return true;
//                      }
//                      if(findDFS(edges,V,i,ev,visited,v)){
//                         v.push_back(i);
//                         return true;
//                      }
//                  }
//              }
//         }
//     }
//     return false;
// }

vector<int> findDFS(int **edges,int V,int sv,int ev,bool *visited){
    vector<int> v;
    visited[sv] = true;
    if(sv == ev){
        // visited[ev] = true;
        v.push_back(ev);
        return v;
    }
    for(int i=0;i<V;i++){
        if(edges[sv][i] == 1 && sv!=i){
            if(!visited[i]){
                visited[i] = true;
                v = findDFS(edges,V,i,ev,visited);
                if(!v.empty()){
                    v.push_back(sv);
                    return v;
                }
            }
        }
    }
    return v;
}

int main()
{
  int V, E, tempX, tempY;
  cin >> V >> E;
    int **edges = new int*[V];
	bool * visited =  new bool[V];
    for(int i=0;i<V;i++){
		visited[i] = false;
        edges[i] = new int[V];
        for(int j=0;j<V; j++){
            edges[i][j] = 0;
        }
    }
    for( int i =0; i<E;i++){
        cin>>tempX>>tempY;
        edges[tempX][tempY] = 1;
        edges[tempY][tempX] = 1;
    }
	cin>>tempX>>tempY;
    vector<int> v;
    // bool found = findDFS(edges,V,tempX,tempY,visited,v);
    // if(found){
    //     v.push_back(tempX);
    // }
    v = findDFS(edges,V,tempX,tempY,visited);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
  /*

  	   Write Your Code Here
	   Complete the Rest of the Program
	   You have to Print the output yourself
	 
  */
    delete[] visited;
	for(int i=0;i<V;i++){
        delete[] edges[i];
    }
    delete[] edges;
  return 0;
}

