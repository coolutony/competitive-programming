#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <utility> 
#include <string>
#include "mheap.cpp"

using namespace std;
//Shortest distances between nodes (0,1,2, ...)
vector<int> shortest_distances(vector<vector<pair<int, int>>> & adj_list, const int & root, vector<int> nodes, int n){//n: number of nodes
    vector<int> dist_to;
    mheap<int,int> dheap;
    dheap.insert(root,0);
    for (int node = 0; node < n; node++ ){
        if (node != root){
            dheap.insert(node, INT32_MAX);
        }
    }
    while(dist_to.size() != n){
        int chosen = dheap.pop();
        dist_to[chosen] = dheap.keyval[chosen];
        for(auto neighbor : adj_list[chosen]){
            int neigh_node = neighbor.first;
            int neigh_dist = neighbor.second;
            int new_dist = neigh_dist + dist_to[chosen];
            if(new_dist < dheap.keyval[neigh_node]){
                dheap.update_key(neigh_node, new_dist);
            }
        }
    }
    return dist_to;
}
int main (void){
    /* Example for reading input - TODO
    int n;
    cin >> n;
    map<string, vector<sipair>> ex;
    for (int i = 0; i < n; i++){
        vector<sipair> temp;
        string name;
        int dist;
        cin >> name;
        cin >> dist;
        temp.push_back(make_pair(name,dist));
    }*/
    //example input
}