// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 
#define N 2005 
  
// To store vertices, edges 
// and the required answer 
int n, m, ans; 
  
// To store parent and rank 
int par[N], Rank[N]; 
  
// To store edges and the edges in MST 
vector<pair<int, pair<int, int> > > edges, mst; 
  
// To store the edges with weight zero 
queue<pair<int, int> > zeros; 
  
// Function for initialize 
void initialize() 
{ 
    for (int i = 0; i <= n; i++) { 
        par[i] = i; 
        Rank[i] = 0; 
    } 
} 
  
// Function to add edges 
void Add_edge(int u, int v, int weight) 
{ 
    edges.push_back({ weight, { u, v } }); 
} 
  
// Utility function to find set of an element i 
// (uses path compression technique) 
int find(int x) 
{ 
    if (par[x] != x) 
        par[x] = find(par[x]); 
  
    return par[x]; 
} 
  
// Function that performs union of two sets x and y 
// (uses union by rank) 
void Union(int x, int y) 
{ 
    int xroot = find(x); 
    int yroot = find(y); 
  
    if (Rank[xroot] < Rank[yroot]) 
        par[xroot] = yroot; 
    else if (Rank[xroot] > Rank[yroot]) 
        par[yroot] = xroot; 
    else { 
        par[yroot] = xroot; 
        Rank[xroot]++; 
    } 
} 
  
// Function to compute minimum spanning tree 
void compute_MST() 
{ 
    // Sort edges in increasing order of weight 
    sort(edges.begin(), edges.end()); 
  
    // Go through all the edges 
    for (int i = 0; i < m; i++) { 
        int u = find(edges[i].second.first); 
        int v = find(edges[i].second.second); 
  
        if (u == v) 
            continue; 
  
        // Build minimum spanning tree 
        // and store minimum cost 
        mst.push_back(edges[i]); 
        ans += edges[i].first; 
        Union(u, v); 
    } 
} 
  
// Function to find the cost of minimum 
// spanning tree 
void Modified_Kruskal(pair<int, int> x) 
{ 
    initialize(); 
  
    // Make answer zero 
    ans = 0; 
    int sz = zeros.size(); 
  
    // Keep the edges which only have zero weights 
    // and remove all the other edges 
    for (int i = 0; i < sz; i++) { 
        pair<int, int> Front = zeros.front(); 
        zeros.pop(); 
  
        if (Front.first == x.first 
            and Front.second == x.second) 
            continue; 
  
        // Make union between the vertices of 
        // edges which have weight zero and keep 
        // them in queue 
        Union(Front.first, Front.second); 
        zeros.push(Front); 
    } 
  
    // Find the cost of the minimum spanning tree 
    for (int i = 0; i < mst.size(); i++) { 
        int u = find(mst[i].second.first); 
        int v = find(mst[i].second.second); 
  
        if (u == v) 
            continue; 
  
        ans += mst[i].first; 
        Union(u, v); 
    } 
} 
  
// Function to handle different queries 
void query(int type, int u = 0, int v = 0) 
{ 
  
    // Update edge weight to 0 
    if (type == 2) { 
        // push edge in zeros 
        zeros.push({ u, v }); 
        Modified_Kruskal({ -1, -1 }); 
    } 
  
    // Restore edge weight to original value 
    else if (type == 3) { 
        // push edge in zeros 
        zeros.push({ u, v }); 
        Modified_Kruskal({ u, v }); 
    } 
    else
        cout << ans << endl; 
} 
  
// Driver code 
int main() 
{ 
  
    // Number of nodes and edges 
    n = 41, m = 70; 
    initialize(); 
  
    // Add edges 
    Add_edge( 0, 1, 7); 
    Add_edge( 0, 3, 5); 
    Add_edge( 1, 2, 4); 
    Add_edge( 1, 3, 13); 
    Add_edge( 1, 4, 11); 
    Add_edge( 2, 4, 15); 
    Add_edge( 2, 5, 9); 
    Add_edge( 3, 4, 4); 
    Add_edge( 3, 7, 14); 
    Add_edge( 3, 8, 6); 
    Add_edge( 4, 5, 8); 
    Add_edge( 4, 7, 5); 
    Add_edge( 5, 6, 3); 
    Add_edge( 5, 7, 16); 
    Add_edge( 6,9,17);
	Add_edge( 7,9,10);
    Add_edge( 8,9,16);
    Add_edge( 9,10,19);
    Add_edge( 9,11,8);
    Add_edge( 10,12,12);
    Add_edge( 11,12,17);
    Add_edge( 12,13,20);
    Add_edge( 12,17,25);
    Add_edge( 12,15,9);
    Add_edge( 12,14,6);
    Add_edge( 13,18,6);
    Add_edge( 13,17,14);
    Add_edge( 14,15,2);
    Add_edge( 15,16,8);
    Add_edge( 15,17,22);
    Add_edge( 15,26,4);
    Add_edge( 16,17,5);
    Add_edge( 16,19,14);
    Add_edge( 16,20,9);
    Add_edge( 16,24,9);
    Add_edge( 16,26,8);
    Add_edge( 17,18,9);
    Add_edge( 17,19,8);
    Add_edge( 18,19,12);
    Add_edge( 19,20,1);
    Add_edge( 19,21,8);
    Add_edge( 19,22,3);
    Add_edge(  20,22,6);
    Add_edge(  20,23,5);
    Add_edge(  20,24,10);
    Add_edge(  21,22,3);
    Add_edge(  22,23,4);
    Add_edge(  23,24,11);
    Add_edge(  24,25,5);
    Add_edge(  24,26,13);
    Add_edge(  25,27,26);
    Add_edge(  25,28,5);
    Add_edge(  25,29,5);
    Add_edge(  26,27,17);
    Add_edge(  27,28,6);
    Add_edge(  28,29,9);
    Add_edge(  29,30,3);
    Add_edge(  30,31,7);
    Add_edge(  31,32,6);
    Add_edge(  32,33,5);
    Add_edge(  33,34,17);
    Add_edge(  33,35,10);
    Add_edge(  33,36,16);
    Add_edge(  33,38,19);
    Add_edge(  34,35,14);
    Add_edge(  36,37,6);
    Add_edge(  37,38,8);
    Add_edge(  37,40,16);
    Add_edge(  38,39,5);
    Add_edge(  39,40,13);

  
    // Build the minimum spanning tree 
    compute_MST(); 
  
    // Execute queries 
    query(1); 
  
    return 0; 
} 
