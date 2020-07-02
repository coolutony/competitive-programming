#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#define MIN(X,Y) ((X) < (Y) ? : (X) : (Y))
#define MAX(X,Y) ((X) > (Y) ? : (X) : (Y))
using namespace std;

const int N=100001;

int n,m;

int countServers(vector<vector<int>> & grid){
	vector<vector<int>> copy(grid.size(), vector<int>(grid[0].size(),0));
	for (int i = 0; i<grid.size(); i++){
		int s_count = 0;
		for (int j = 0; j< grid[0].size(); j++){
			if(grid[i][j] == 1){
				s_count ++;
			}
			if (s_count == 2){
				break;
			}
		}
		if (s_count == 2){
			for (int j =0; j< grid[0].size(); j++){
				if(grid[i][j] == 1) copy[i][j] = 1;
			}
		}
	}
	for (int i = 0; i<grid[0].size(); i++){
		int s_count = 0;
		for (int j = 0; j< grid.size(); j++){
			if(grid[j][i] == 1){
				s_count ++;
			}
			if (s_count == 2){
				break;
			}
		}
		if (s_count == 2){
			for (int j =0; j< grid.size(); j++){
				if(grid[j][i] == 1) copy[j][i] = 1;
			}
		}
	}
	int count = 0;
	for (int i =0; i< grid.size(); i++){
		for (int j =0; j< grid[0].size(); j++){
			count += copy[i][j];
		}
	}
	return count;
}
int main(void) {
	vector<vector<int>> sample = {{1,0},{0,1}};
	cout << countServers(sample);
}