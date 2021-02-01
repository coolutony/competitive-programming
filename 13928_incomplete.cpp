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
string minimum(string & a, string & b){
	//TODO: return smaller string
	for (int i=0; i<m;i++){
		if(a[i]>b[i]) return b;
		if(a[i]<b[i]) return a;
	}
	return a;
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
	n = 5;
	m = 5;
	int k = 5;
	string s1 = "00000";
	string s2 = "00000";
	minimize(s2,s1, 2);
	cout << s2 << "\n";
	s1 = "34000";
	s2 = "12000";
	minimize(s2,s1, 2);
	cout << s2 << "\n";
	m = 10;
	s1 = "9812345067";
	s2 = "1298765432";
	k = 2;
	cout << "s1: " << s1 << " s2: " << s2 << " k: " << k << " ";
	minimize(s2,s1, k);
	cout << "output: " << s2 << "\n";
	m = 10;
	s1 = "9812345067";
	s2 = "1298765432";
	k = 3;
	cout << "s1: " << s1 << " s2: " << s2 << " k: " << k << " ";
	minimize(s2,s1, k);
	cout << "output: " << s2 << "\n";
	m = 10;
	s1 = "9812345067";
	s2 = "1298765432";
	k = 4;
	cout << "s1: " << s1 << " s2: " << s2 << " k: " << k << " ";
	minimize(s2,s1, k);
	cout << "output: " << s2 << "\n";
	m = 10;
	s1 = "8999995067";
	s2 = "9899995432";
	k = 4;
	cout << "s1: " << s1 << " s2: " << s2 << " k: " << k << " ";
	minimize(s2,s1, k);
	cout << "output: " << s2 << "\n";
	m = 10;
	s1 = "8877549870";
	s2 = "7885549870";
	k = 2;
	cout << "s1: " << s1 << " s2: " << s2 << " k: " << k << " ";
	minimize(s2,s1, k);
	cout << "output: " << s2 << "\n";
	m = 10;
	s1 = "8877549870";
	s2 = "7885549870";
	k = 3;
	cout << "s1: " << s1 << " s2: " << s2 << " k: " << k << " ";
	minimize(s2,s1, k);
	cout << "output: " << s2 << "\n";
	m = 4;
	s1 = "9989";
	s2 = "9995";
	k = 1;
	cout << "s1: " << s1 << " s2: " << s2 << " k: " << k << " ";
	minimize(s2,s1, k);
	cout << "output: " << s2 << "\n";
	m = 4;
	s1 = "1234";
	s2 = "1111";
	k = 0;
	cout << "s1: " << s1 << " s2: " << s2 << " k: " << k << " ";
	minimize(s2,s1, k);
	cout << "output: " << s2 << "\n";
}