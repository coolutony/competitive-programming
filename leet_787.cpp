#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stdexcept>
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))
#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))
using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
	vector<vector<int>> dp (n, vector<int>(K+2, INT32_MAX));
	vector<vector<int>> adj_list (n,vector<int>()); //incoming
	vector<vector<int>> edge(n,vector<int> (n, INT32_MAX));
	for(auto & list : flights){
		adj_list[list[1]].push_back(list[0]);
		edge[list[0]][list[1]] = list[2];
	}
	for (int i = 0; i <= K; i++){
		dp[src][i] = 0;
	}
	for(int k = 1; k<=K; k++){
		for(int node = 0; node < n; node++){
			if(node == src) continue;
			for (int & neigh: adj_list[node]){ //adj_list should have neigh's incoming
				if(dp[neigh][k-1] != INT32_MAX){
					dp[node][k] = MIN(dp[node][k], dp[neigh][k-1] + edge[neigh][node]);
				}
			}
		}
	}
	for (int & neigh: adj_list[dst]){
		if(dp[neigh][K] != INT32_MAX){
			dp[dst][K+1] = MIN(dp[dst][K+1], dp[neigh][K] + edge[neigh][dst]);
		}
	}
	if (dp[dst][K+1] == INT32_MAX) return -1;
	return dp[dst][K+1];
}
int main(void) {
	int n = 3;
	vector<vector<int>> flights = {{0,1,100},{1,2,100},{0,2,500}};
	int src = 0;
	int dst = 2;
	int K = 1;
	cout << findCheapestPrice(n,flights,src,dst,K);
}