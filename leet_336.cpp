#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define MIN(X,Y) ((X) < (Y) ? : (X) : (Y))
#define MAX(X,Y) ((X) > (Y) ? : (X) : (Y))
using namespace std;

const int N=100001;

int n,m;
bool checkPalindrome(string s){
	for(int i = 0; i < (s.size()+1)/2; i++){
		if (s[i] != s[s.size()-1-i]) return false;
	}
	return true;
}
vector<vector<int>> palindromePairs(vector<string> words){
	vector<vector<int>> ans;
	for(int i = 0; i < words.size(); i++){
		for (int j = 0; j< words.size(); j++){
			if (i==j) continue;
			if (checkPalindrome(words[i]+words[j])){
				ans.push_back(vector<int>({i,j}));
			}
		}
	}
	return ans;
}
int main(void) {
	vector<string> words = {"abcd","dcba","lls","s","sssll"};
	vector<vector<int>> ans = palindromePairs(words);
	for(auto p : ans){
		cout << "{" << p[0] << ", " << p[1] << "}\n";
	}
}