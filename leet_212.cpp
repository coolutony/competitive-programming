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
struct Trie {
	unordered_map<char, Trie *> children;
	string word = "";
	Trie(){
	}
};
void find(unordered_map <char, Trie *> children, int x, int y, vector<vector<char>> & board, vector<string> & ans){
	if (x >= board.size() || x < 0 || y < 0 || y >= board[0].size()) return;
	if (children.count(board[x][y]) == 0) return;
	Trie * child = children[board[x][y]];
	if(child -> word != ""){
		ans.push_back(child -> word);
		child -> word = "";
	}
	char temp = board[x][y];
	board[x][y] = '-';
    find(child -> children, x+1, y, board, ans); 
	find(child -> children, x, y+1, board, ans); 
	find(child -> children, x-1, y, board, ans); 
	find(child -> children, x, y-1, board, ans);
	board[x][y] = temp;
}
vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
	vector<string> ans;
	Trie * root = new Trie(); 
	//init Trie structure
	for(const string & word: words){
		Trie * pointer = root;
		for(const char & letter: word){
			if((pointer -> children).count(letter) == 0){
				pointer -> children [letter] = new Trie();
			}
			pointer = pointer -> children [letter];
		}
		pointer -> word = word;
	}
	//go through board and solve Trie
	for(int x = 0; x<board.size(); x ++){
		for(int y = 0; y<board[0].size(); y ++){
			find(root -> children, x, y, board, ans);
		}
	}
	return ans;
}
int main(void) {
	scanf("%d%d", &n, &m);
}