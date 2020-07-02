#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#define MIN(X,Y) ((X) < (Y) ? : (X) : (Y))
#define MAX(X,Y) ((X) > (Y) ? : (X) : (Y))
using namespace std;

const int N=100001;

int n,m;
vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
	vector<int> ps;
	ps.push_back(0);
	vector<bool> ans;
	for (const char & c: s){
		ps.push_back(ps.back() ^ ( 1<< (c-'a') ));
	}
	for (const auto & q : queries){
		int odd = __builtin_popcount(ps[q[0]] ^ ps[q[1]+1]);
		ans.push_back(odd/2<=q[2]);
	}
	return ans;
}
int main(void) {
}
