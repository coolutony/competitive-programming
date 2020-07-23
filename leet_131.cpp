#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))
#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))

using namespace std;

const int N=100001;


unordered_map<string, vector<vector<string>>> cache;
bool isPal(string & s){
	int i = 0;
	int j = s.size()-1;
	while(i<j){
		if(s[i]!=s[j]) return false;
		i++;
		j--;
	}
	return true;
}
vector<vector<string>> part(string & s){
	if (cache.count(s) > 0) return cache[s];
	vector<vector<string>> ans;
	for (int i  = 1; i<= s.size(); i++){
		string subs = s.substr(0,i);
		string rmain = s.substr(i);
		if (isPal(subs)){ //If to slow, change to s, start, end
			for(auto & posib : part(rmain)){
				posib.insert(posib.begin(), subs);
				ans.push_back(posib);
			}
		}
	}
	if (ans.size() == 0) ans.push_back(vector<string>());
	cache[s] = ans;
	return ans;

}
vector<vector<string>> partition(string s){
	if (s == "") return vector<vector<string>> ();
	return part(s);
}
void print_vec(vector<vector<string>> & ans){
	cout << "start\n";
	for(auto & p: ans){
		for (auto & s : p){
			cout << s << ", ";
		}
		cout << "\n";
	}
}
int main(void) {
	string s = "aab";
	vector<vector<string>> ans = partition("aab");
	cout << ans.size();
	print_vec(ans);
}