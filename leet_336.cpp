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
bool checkPalindrome(string a, string b){
	int i = 0;
	int j = a.size() + b.size() -1;
	while (i<j){
		char c_i = ' ';
		char c_j = ' ';
		if (i<a.size()) {c_i = a[i];}
		else {c_i = b[i-a.size()];}
		if (j<a.size()) {c_j = a[j];}
		else {c_j = b[j-a.size()];}
		if(c_i != c_j) return false;
		i ++;
		j --;
	}

	return true;
}
vector<vector<int>> palindromePairs(vector<string> words){
	vector<vector<int>> ans;
	for(int i = 0; i < words.size(); i++){
		for (int j = 0; j< words.size(); j++){
			if (i==j) continue;
			if (checkPalindrome(words[i],words[j])){
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