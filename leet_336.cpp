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
void get_left_candidates(string & s, unordered_map<string, int> & dict, vector<vector<int>> & ans){
	for(int i = 0; i < s.size(); i++){
		int start = 0;
		int end = i;
		bool break_flag = false;
		while(start <= end){
			if(s[start] != s[end]){
				break_flag = true;
				break;
			}
			start ++;
			end --;
		}
		if(break_flag) continue;
		string cand = s.substr(i+1);
		reverse(cand.begin(), cand.end());
		if(dict.count(cand) > 0){
			vector<int> to_add;
			to_add.push_back(dict[cand]);
			to_add.push_back(dict[s]);
			ans.push_back(to_add);
		}
	}
}
void get_right_candidates(string & s, unordered_map<string, int> & dict, vector<vector<int>> & ans){
	for(int i = 0; i < s.size(); i++){
		int start = s.size()-1;
		int end = start - i;
		bool break_flag = false;
		while(start >= end){
			if(s[start] != s[end]){
				break_flag = true;
				break;
			}
			start --;
			end ++;
		}
		if(break_flag) continue;
		string cand = s.substr(0,s.size() - i -1);
		reverse(cand.begin(), cand.end());
		if(dict.count(cand) > 0){
			vector<int> to_add;
			to_add.push_back(dict[s]);
			to_add.push_back(dict[cand]);
			ans.push_back(to_add);
		}
	}
}
vector<vector<int>> palindromePairs(vector<string> words){
	vector<vector<int>> ans;
	unordered_map<string, int> dict;
	for(int i = 0; i < words.size(); i++){
		dict[words[i]] = i;
	}
	for (string & s : words){
		if(s.size() == 0) continue;
		get_left_candidates(s, dict, ans);
		get_right_candidates(s, dict, ans);
		string rev_s= s;
		reverse(rev_s.begin(), rev_s.end());
		if(dict.count(rev_s) > 0){
			if(dict[s] == dict[rev_s]) continue;
			vector<int> to_add;
			to_add.push_back(dict[s]);
			to_add.push_back(dict[rev_s]);
			ans.push_back(to_add);
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