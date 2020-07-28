#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))
#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))
using namespace std;
int makePal(string & s, int start, int end){
	int i = start;
	int j = end; 
	int count = 0;
	while(i < j){
		if(s[i] != s[j]) count ++;
		i ++;
		j --;
	}
	return count;
}
int pPart(string & s, vector<vector<vector<int>>> & cache, int k, int start, int end, int min_count){
	if (cache[k][start][end] != -1) return cache[k][start][end];
	if (k==1) return makePal(s, start, end);
	int count = min_count;
	for(int i = start; i < end; i++){
		int temp = makePal(s, start, i);
		if(min_count <= temp) continue;
		temp += pPart(s, cache, k-1, i+1, end, s.size());
		count = MIN(count,temp);
	}
	cache[k][start][end] = count;
	return count;
}
int palindromePartition(string s, int k) {
	vector<vector<vector<int>>> cache (k+1, vector<vector<int>> (s.size(), vector<int> (s.size(), -1)));
	//cache[k][start][end] = -1 or actual val
	return pPart(s, cache ,k,0, s.size()-1, s.size());
}
int main(void) {
string s= "leetcooe";
	int k = 2;
	cout << palindromePartition(s,k);
}