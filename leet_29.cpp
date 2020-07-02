#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#define MIN(X,Y) ((X) < (Y) ? : (X) : (Y))
#define MAX(X,Y) ((X) > (Y) ? : (X) : (Y))
using namespace std;

const int N=100001;

int n,m;
bool find(string word, int x, int y, vector<vector<char>>& board){
	if(word.size() == 0) return true;
	if(x >= board.size() || x < 0 || y >= board[0].size() || y < 0){
		return false;
	}
	if(board[x][y] != word[0]) return false;
	char temp = board[x][y];
	board[x][y] = '-';
	if(find(word.substr(1), x+1, y, board) ||
		find(word.substr(1), x, y+1, board) ||
		find(word.substr(1), x-1, y, board) ||
		find(word.substr(1), x, y-1, board) ) return true;
	board[x][y] = temp;
	return false;
}
bool exist(vector<vector<char>>& board, string word) {
	for (int x = 0; x < board.size(); x++){
		for (int y = 0; y < board[0].size(); y++){
			if(find(word,x,y,board)) return true;
		}
	}	
	return false;
}
int main(void) {
	scanf("%d%d", &n, &m);
}