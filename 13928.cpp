#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N=100001;

int n,m;
vector<vector<string>> order_c;
// "-" not cached yet
// "-1" impossible
vector<string> num;
void minimize(string & target, string const & cmpr, int count){
	int i = 0;
	while(cmpr[i] == '9' && i < m){
		if(target[i] != '9'){
			target[i] = 9;
			count --;
			if (count < 0){
				target = "-1";
				return;
			}
		}
		i++;
	}
	if (count == 0){
		if (cmpr[i] > target[i]){
			target = "-1";
			return;
		}
	}
	while(count > 1 && i < m){
		if (cmpr[i] != target[i]){
			target[i] = cmpr[i];
			count --;
		}
		i++;
	}
	while(cmpr[i] == target[i] && i < m){
		i++;
	}
	while(count > 0){
		int save = i;
		i++;
		while(cmpr[i] == target[i] && i < m){
			i++;
		}
		if(i==m){
			target[save] = cmpr[save];
			return;
		}
		if(cmpr[i] > target[i]){
			if(target[save] != cmpr[save] +1){
				target[save] = cmpr[save] + 1;
				count --;
				save ++;
				while(count > 0 && save < m){
					if(target[save] != 0){
						target[save] ='0';
						count --;
					}
					save++;
				}
				if(save == m) return;
			}
		}else if(cmpr[i] < target [i]){
			if(target[save] != cmpr[save]){
				target[save] = cmpr[save];
				count --;
			}
		}else {
			cout << "\n Something is wrong\n";
		}
	}
	//TODO: how to minimize target (but still bigger than cmpr) with the left counts?
}
string minimum(string a, string b){
	//TODO: return smaller string
}
string order(int ind, int k){
	string ret = num[ind];
	if (ind == 0){
		for (int i = 0; i < m; i++){
			if (k == 0) break;
			if (ret[i] != '0'){
				ret[i] = '0';
				k --;
			}
		}
		order_c[ind][k] = ret;
		return ret;
	}
	string min = "?"; // ? > 9 in ascii
	for (int j = 0; j <= k; j++){
		string prev = order_c[ind-1][k-j];
		if (prev == "-"){
			prev = order(ind-1, k-j);
		}
		if (prev == "-1"){
			continue;
		}
		minimize(ret, prev, j);
		if (ret == "-1") continue;
		min = minimum(min, ret);
	}
	if (min == "?"){
		order_c[ind][k] = "-1";
		return "-1";
	}
	order_c[ind][k] == ret;
	return ret;
}
int main(void) {
	scanf("%d%d", &n, &m);
	n = 5;
	string s1 = "00000";
	string s2 = "00000";
	minimize(s2,s1, 2);
	cout << s2;
}