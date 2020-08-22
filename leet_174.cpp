#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))
#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))
using namespace std;

int calculateMinimumHP(vector<vector<int>>& dungeon) {
	int m = dungeon.size();
	int n = dungeon[0].size();
	vector<vector<int>> hp (m+1, vector<int> (n+1, INT32_MAX));
	hp[m-1][n-1] = -dungeon[m-1][n-1] + 1;

	for(int s_x = m-2; s_x >= 0; s_x--){
		int x = s_x;
		int y = n-1;
		while(x<m && y>-1){
			hp[x][y] = MAX(1,MIN(hp[x+1][y], hp[x][y+1]) - dungeon[x][y]);
			x++; 
			y--;
		}
	}
	for(int s_y = n-2; s_y >= 0; s_y--){
		int x = 0;
		int y = s_y;
		while(x<m && y>-1){
			hp[x][y] = MAX(1,MIN(hp[x+1][y], hp[x][y+1]) - dungeon[x][y]);
			x++; 
			y--;
		}
	}

	return MAX(1,hp[0][0]);
}
int main(void) {
	vector<vector<int>> dungeon {{-2,-3,3},{-5,-10,1},{10,30,-5}};
	cout << calculateMinimumHP(dungeon);
}