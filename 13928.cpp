#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N=100001;

int n,m;
vector<vector<string>> order_c;
vector<vector<int>> back_track;
// "-" not cached yet
// "-1" impossible
vector<string> num;
void minimize(string & target, string const & cmpr, int count){
	string new_target = target;
	int i = 0;
	while (count > 0 && i < m){
		if (target[i] != cmpr[i]){
			new_target[i] = cmpr[i];
			count--;
		}
		i ++;
	}
	if (i==m){
		target = new_target;
		return;
	}
	while(target[i] == cmpr[i] && i < m){
		i ++;
	}
	if (i==m){
		target = new_target;
		return;
	}
	if (target[i] > cmpr[i]){
		target = new_target;
		return;
	}
	i--;
	while(target[i] == cmpr[i] && i >= 0) i--;
	if (i < 0){
		target = "-1";
		return;
	}
	while(cmpr[i] == '9' && i >= 0){
		if(target[i] != '9'){
			count++;
			new_target[i] = target[i]; //revert
		}
		i--;
	}
	if (i < 0){
		target = "-1";
		return;
	}
	if (target[i] != cmpr[i]) count ++;
	new_target[i] = cmpr[i] + 1;
	if (target[i] != cmpr[i] + 1) count --;
	i++;
	while(count > 0 && i < m){
		if (target[i] != '0'){
			new_target[i] = '0';
			count --;
		}
		i++;
	}
	target = new_target;
	return;
}
string order(int ind, int k){
	if(order_c[ind][k] != "-") return order_c[ind][k];
	string ret = num[ind];
	if (ind == 0){
		int count = k;
		for (int i = 0; i < m; i++){
			if (count == 0) break;
			if (ret[i] != '0'){
				ret[i] = '0';
				count --;
			}
		}
		order_c[ind][k] = ret;
		return ret;
	}
	string min = "?"; // ? > 9 in ascii
	for (int j = 0; j <= k; j++){
		ret = num[ind];
		string prev = order_c[ind-1][k-j];
		if (prev == "-"){
			prev = order(ind-1, k-j);
		}
		if (prev == "-1"){
			continue;
		}
		minimize(ret, prev, j);
		if (ret == "-1") continue;
		if (ret < min){
			min = ret;
			back_track[ind][k] = k-j;
		}
	}
	if (min == "?"){
		order_c[ind][k] = "-1";
		return "-1";
	}
	order_c[ind][k] = min;
	return min;
}
int main(void) {
	cin >> n;
	cin >> m;
	if(n == 0 || m==0) return 0;
	for (int i=0;i<n;i++){
		string temp;
		cin >> temp; 
		num.push_back(temp);
	}
	order_c = vector<vector<string>>(n,vector<string>(m*n,"-"));
	back_track = vector<vector<int>>(n,vector<int>(m*n,-1));
	vector<string> ans;
	vector<int> k_val;
	int k = 0;
	while(order(n-1,k)=="-1") k++;

	int ind = n-1;
	while(ind>=0){
		ans.push_back(order(ind,k));
		k_val.push_back(k);
		k = back_track[ind][k];
		ind --;
	}
	for (int i = ans.size()-1; i>-1; i--){
		cout << ans[i] <<"\n";
	}
}