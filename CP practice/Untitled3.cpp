#include<iostream>
#include<list>
#include<set>
using namespace std;

typedef struct nodes {
   int dest;
   int cost;
}node;

class Graph {
   int n;
   list<node> *adjList;
   private:
      void showList(int src, list<node> lt) {
         list<node> :: iterator i;
         node tempNode;

         for(i = lt.begin(); i != lt.end(); i++) {
            tempNode = *i;
            cout << "(" << src << ")---("<<tempNode.dest << "|"<<tempNode.cost<<") ";
         }
         cout << endl;
      }

   public:
      Graph() {
         n = 0;
      }

      Graph(int nodeCount) {
         n = nodeCount;
         adjList = new list<node>[n];
      }

      void addEdge(int source, int dest, int cost) {
         node newNode;
         newNode.dest = dest;
         newNode.cost = cost;
         adjList[source].push_back(newNode);
      }

      void displayEdges() {
         for(int i = 0; i<n; i++) {
            list<node> tempList = adjList[i];
            showList(i, tempList);
         }
      }

      friend Graph primsMST(Graph g, int start);
};

set<int> difference(set<int> first, set<int> second) {
   set<int> :: iterator it;
   set<int> res;

   for(it = first.begin(); it != first.end(); it++) {
      if(second.find(*it) == second.end())
         res.insert(*it);    //add those item which are not in the second list
   }

   return res;    //the set (first-second)
}

Graph primsMST(Graph g, int start) {
   int n = g.n;
   set<int> B, N, diff;
   Graph tree(n);        //make tree with same node as graph
   B.insert(start);     //insert start node in the B set

   for(int u = 0; u<n; u++) {
      N.insert(u); //add all vertices in the N set
   }

   while(B != N) {
      int min = 9999;             //set as infinity
      int v, par;
      diff = difference(N, B);    //find the set N - B

      for(int u = 0; u < n; u++) {
         if(B.find(u) != B.end()) {
            list<node>::iterator it;
            for(it = g.adjList[u].begin(); it != g.adjList[u].end(); it++) {
               if(diff.find(it->dest) != diff.end()) {
                  if(min > it->cost) {
                     min = it->cost;    //update cost
                     par = u;
                     v = it->dest;
                  }
               }
            }
         }
      }

      B.insert(v);
      tree.addEdge(par, v, min);
      tree.addEdge(v, par, min);
   }
   return tree;
}

main() {
   Graph g(41), tree(41);
       g.addEdge( 0, 1, 7); 
    g.addEdge( 0, 3, 5); 
    g.addEdge( 1, 2, 4); 
    g.addEdge( 1, 3, 13); 
    g.addEdge( 1, 4, 11); 
    g.addEdge( 2, 4, 15); 
    g.addEdge( 2, 5, 9); 
    g.addEdge( 3, 4, 4); 
    g.addEdge( 3, 7, 14); 
    g.addEdge( 3, 8, 6); 
    g.addEdge( 4, 5, 8); 
    g.addEdge( 4, 7, 5); 
    g.addEdge( 5, 6, 3); 
    g.addEdge( 5, 7, 16); 
    g.addEdge( 6,9,17);
	g.addEdge( 7,9,10);
    g.addEdge( 8,9,16);
    g.addEdge( 9,10,19);
    g.addEdge( 9,11,8);
    g.addEdge( 10,12,12);
    g.addEdge( 11,12,17);
    g.addEdge( 12,13,20);
    g.addEdge( 12,17,25);
    g.addEdge( 12,15,9);
    g.addEdge( 12,14,6);
    g.addEdge( 13,18,6);
    g.addEdge( 13,17,14);
    g.addEdge( 14,15,2);
    g.addEdge( 15,16,8);
    g.addEdge( 15,17,22);
    g.addEdge( 15,26,4);
    g.addEdge( 16,17,5);
    g.addEdge( 16,19,14);
    g.addEdge( 16,20,9);
    g.addEdge( 16,24,9);
    g.addEdge( 16,26,8);
    g.addEdge( 17,18,9);
    g.addEdge( 17,19,8);
    g.addEdge( 18,19,12);
    g.addEdge( 19,20,1);
    g.addEdge( 19,21,8);
    g.addEdge( 19,22,3);
    g.addEdge(  20,22,6);
    g.addEdge(  20,23,5);
    g.addEdge(  20,24,10);
    g.addEdge(  21,22,3);
    g.addEdge(  22,23,4);
    g.addEdge(  23,24,11);
    g.addEdge(  24,25,5);
    g.addEdge(  24,26,13);
    g.addEdge(  25,27,26);
    g.addEdge(  25,28,5);
    g.addEdge(  25,29,5);
    g.addEdge(  26,27,17);
    g.addEdge(  27,28,6);
    g.addEdge(  28,29,9);
    g.addEdge(  29,30,3);
    g.addEdge(  30,31,7);
    g.addEdge(  31,32,6);
    g.addEdge(  32,33,5);
    g.addEdge(  33,34,17);
    g.addEdge(  33,35,10);
    g.addEdge(  33,36,16);
    g.addEdge(  33,38,19);
    g.addEdge(  34,35,14);
    g.addEdge(  36,37,6);
    g.addEdge(  37,38,8);
    g.addEdge(  37,40,16);
    g.addEdge(  38,39,5);
    g.addEdge(  39,40,13);


   tree = primsMST(g, 0);
   tree.displayEdges();
}
