#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#define MIN(X,Y) ((X) < (Y) ? : (X) : (Y))
#define MAX(X,Y) ((X) > (Y) ? : (X) : (Y))
using namespace std;

const int N=100001;

int n,m;
bool possible(vector<int>& stones, unordered_map<int,unordered_map<int,bool>> & visited, vector<bool> & exists, int stone, int jump){
	if(stone == *(stones.end()-1)) return true;
	if (visited.count(stone) == 0){
		visited[stone] = unordered_map<int,bool> ();
	}
	visited[stone][jump] = true;
	for(int i = -1; i < 2; i++){
		int next_jump = jump + i;
		if(next_jump < 1) continue;
		int next_stone = stone + next_jump;
		if (!exists[next_stone]) continue;
		if(visited.count(next_stone) == 0 || visited[next_stone].count(next_jump) == 0){
			if (possible(stones, visited, exists, next_stone, next_jump)) return true;
		}
	}
	return false;
}
bool canCross(vector<int>& stones) {
	if(*(stones.end()-1) > 605550) return false;
	if(stones.size() < 2) return false;
	if(stones[1] != 1) return false;
	int last_jump = 0;	 
	int this_jump = 0;
	vector<bool> exists = vector<bool> (605550, false);
	unordered_map<int, unordered_map<int,bool>> visited;
	for (int stone : stones){
		exists[stone] = true;
	}
	return possible(stones,visited, exists, 1,1);
}
int main(void) {
	vector<int> stones = {0,1,3,6,10,15,21,28,36,45,55,66};
	cout << canCross(stones);
}