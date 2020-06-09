#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <utility> 
#include <string>
#include "mheap.cpp"

using namespace std;
typedef pair<string, int> sipair;
template<class Key>
map<Key, int> shortest_distances(map<Key,vector<pair<Key, int>>> & adj_list, const Key & root, vector<Key> nodes){
    map<Key, int> dist_to;
    mheap<Key,int> dheap;
    dheap.insert(root,0);
    for (auto node: nodes){
        if (node != root){
            dheap.insert(node, INT32_MAX);
        }
    }
    while(dist_to.size() != nodes.size()){
        Key chosen = dheap.pop();
        dist_to[chosen] = dheap.keyval[chosen];
        for(auto neighbor : adj_list[chosen]){
            Key neigh_node = neighbor.first;
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