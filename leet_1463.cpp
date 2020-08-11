#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))
#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))
using namespace std;

const int N=100001;

int n,m;

int cherryPickup(vector<vector<int>> & grid){
	vector<vector<int>> dp = vector<vector<int>> (grid.size(), vector<int> (grid[0].size(), -1));
	for(int i = 1; i < grid[0].size() - 1; i++){
		dp[0][i] = 0;
	}
}

int main(void) {
	scanf("%d%d", &n, &m);
}