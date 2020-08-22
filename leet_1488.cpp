#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))
#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))
using namespace std;
vector<int> avoidFlood(vector<int>& rains) {
	unordered_map<int,int> isfull; 
	//isfull[l] has next place to search on dry_indice for lake l
	vector<int> dry_indice;
	// dry_indice[d] is the dth possible index to dry. if -1, it is used.
	vector<bool> flag;
	//have a separate flag container. if flag = true ok. if flag =-1, point to next usable dry
	vector<int> ans;
	for (int i =0; i<rains.size();i++){
		if(rains[i] != 0){
			if(isfull.count(rains[i]) > 0){
				if(isfull[rains[i]] >= dry_indice.size()) return vector<int>();
				vector<int> temp;
				while(!flag[isfull[rains[i]]]){
					temp.push_back(isfull[rains[i]]);
					isfull[rains[i]] = dry_indice[isfull[rains[i]]];
				}
				if(temp.size() > 0){
					for(int & j : temp){
						dry_indice[j] = isfull[rains[i]];
					}
				}
				if(isfull[rains[i]] >= dry_indice.size()) return vector<int>();
				int cur_ind = isfull[rains[i]];
				ans[dry_indice[cur_ind]] = rains[i];
				flag[cur_ind] = false;
				while(cur_ind<flag.size() && !flag[cur_ind]){
					cur_ind ++;
				}
				dry_indice[isfull[rains[i]]] = cur_ind; 
			}
			isfull[rains[i]] = dry_indice.size();
			ans.push_back(-1);
		}else{ //rains[i] ==0
			dry_indice.push_back(i);
			flag.push_back(true);
			ans.push_back(0);
		}
	}
	for (int i =0; i<rains.size();i++){
		if (ans[i] == 0) ans[i] =1;
	}
	return ans;
}
int main(void) {
	vector<int> rains = {1,3,2,0,2,0,3,0,1,0,0,0};
	vector<int> ans =avoidFlood(rains);
	for(auto i : ans){
		cout << i << ", ";
	}
}