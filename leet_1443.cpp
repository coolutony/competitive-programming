#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MIN(X,Y) ((X) < (Y) ? : (X) : (Y))
#define MAX(X,Y) ((X) > (Y) ? : (X) : (Y))
using namespace std;

const int N=100001;

struct Tree {
	bool hasApple;
	int ind;
	vector<Tree *> children;
	Tree(bool b, int i){
		hasApple = b;
		ind = i;
	}
};
vector<vector<int>> make_adj_list(int n, vector<vector<int>>& edges, vector <bool>& hasApple){
	vector<vector<int>> adj_list (n);
	for(auto & pair : edges){
		adj_list[pair[0]].push_back(pair[1]);
		adj_list[pair[1]].push_back(pair[0]);
	}
	return adj_list;

}
int collect_time(int node, vector<vector<int>> & adj_list, vector<bool> & hasApple, vector<bool> visited){
	visited[node] = true;
	int count = 0;
	int child_count = 0;
	for (int child: adj_list[node]){
		if (visited[child]) continue;
		int time = collect_time(child, adj_list, hasApple, visited);
		if (time >=0 ) count += 2 + time;
		child_count ++;
	}
	if (child_count == 0){
		if (hasApple[node]) {
			return 0;
		}
		return -1;
	}

	if (count == 0) {
		if (hasApple[node]){
			return 0;
		}
		return -1;
	}
	return count;
}
int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
	vector<vector<int>> adj_list = make_adj_list(n,edges,hasApple);
	vector<bool> visited (n,false);
	int time = collect_time(0, adj_list, hasApple, visited);
	if (time == -1) return 0;
	return time;
}
int main(void) {
	vector<vector<int>> edges = {{0,1},{0,2},{1,4},{1,5},{2,3},{2,6}};
	vector<bool> hasApple = {false,false,false,false,false,false,false};
	int n = 7;
	cout << minTime(n,edges, hasApple);
}