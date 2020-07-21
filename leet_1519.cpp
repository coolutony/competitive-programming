#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#define MIN(X,Y) ((X) < (Y) ? : (X) : (Y))
#define MAX(X,Y) ((X) > (Y) ? : (X) : (Y))
using namespace std;

const int N=100001;

int n,m;

int val(int tree, char c, string & labels, vector<vector<int>> & children, vector<unordered_map<char,int>> & vals){
	if(vals[tree].count(c) > 0) return vals[tree][c];
	int count = 0;
	if (labels[tree] == c){
		count ++;
	}
	for (int & child : children[tree]){
		count += val(child, c, labels, children, vals);
	}
	vals[tree][c] = count;
	return count;
}
vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
	//vector<vector<int>> children(n, vector<int>());
	vector<int> parent (n, -1);
	vector<int> ans (n, 0); 
	vector<int> level (n, -1);
	vector<vector<int>> level_list (n);
	level[0] = 0;
	level_list[0].push_back(0);
	int leaf_level = 0;
	int done_count = 0;
	//vector<unordered_map<char,int>> vals (n,unordered_map<char,int>());
	bool finished = false;
	while(!finished){
		finished = true;
		for (auto & edge: edges){
			if(level[edge[0]] != -1 && level[edge[1]] != -1) continue;
			if(level[edge[0]] == -1 && level[edge[1]] == -1){
				finished = false;
				continue;
			}
			if(level[edge[0]] == -1){
				level[edge[0]] = level[edge[1]] +1;
				if(leaf_level < level[edge[0]]) leaf_level = level[edge[0]];
				level_list[level[edge[0]]].push_back(edge[0]);
				parent[edge[0]] = edge[1];
			} else if(level[edge[1]] == -1){
				level[edge[1]] = level[edge[0]] +1;
				if(leaf_level < level[edge[1]]) leaf_level = level[edge[1]];
				level_list[level[edge[1]]].push_back(edge[1]);
				parent[edge[1]] = edge[0];
			}
		}
	}
	/*
	for (auto & edge: edges){
		int par = edge[0];
		int child = edge[1];
		if(level[edge[0]] > level[edge[1]]){
			par = edge[1];
			child = edge[0];
		}
		//children[par].push_back(child);
		parent[child] = par;
	}*/
	for(int i = leaf_level; i > -1 ; i--){
		for(int j = 0; j < level_list[i].size(); j++){
			int cur = level_list[i][j];
			if (ans[cur] > 0) continue;
			char c = labels[cur];
			int to_add = 0;
			while(cur != -1){
				if (labels[cur] == c){
					if (ans[cur] == 0){
						to_add ++;
						ans[cur] = to_add;
					}else{
						ans[cur] += to_add;
					}
				}
				cur = parent[cur];
			}
		}
	}
	return ans;
}
int main(void) {
	int n = 4;
	vector<vector<int>> edges {{0,2},{0,3},{1,2}};
	string labels = "aeed";
	vector<int> ans = countSubTrees(n,edges,labels);
	for(auto i : ans){
		cout << i << ", ";
	}
}