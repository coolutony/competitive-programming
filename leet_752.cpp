#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))
#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))
using namespace std;
string addone(string & s, int i){
	string ret = s;
	if(ret[i] == '9') ret[i] = '0';
	else ret[i] += 1;
	return ret;
}
string subone(string & s, int i){
	string ret = s;
	if(ret[i] == '0') ret[i] = '9';
	else ret[i] -= 1;
	return ret;
}
int openLock(vector<string>& deadends, string target) {
	if (target == "0000") return 0;
	queue<string> next;
	unordered_map<string,int> dist;
	dist[target] = 0;
	next.push(target);
	for(auto & s : deadends){
		dist[s] = -1;
	}
	while(!next.empty()){
		string next_s = next.front();
		next.pop();
		for (int i = 0; i< 4; i++){
			string neigh = addone(next_s,i);
			if (dist.count(neigh) == 0){
				dist[neigh] = dist[next_s] + 1;
				if(neigh == "0000") return dist[neigh];
				next.push(neigh);
			}
			neigh = subone(next_s,i);
			if (dist.count(neigh) == 0){
				dist[neigh] = dist[next_s] + 1;
				if(neigh == "0000") return dist[neigh];
				next.push(neigh);
			}
		}
	}
	return -1;	
}
int main(void) {
	vector<string> deadends = {"0201","0101","0102","1212","2002"};
	string target = "0202";
	cout << openLock(deadends, target);
}