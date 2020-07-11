#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#define MIN(X,Y) ((X) < (Y) ? : (X) : (Y))
#define MAX(X,Y) ((X) > (Y) ? : (X) : (Y))
using namespace std;

const int N=100001;

int getp(int n, vector<int> & p){
	if (p[n] != -1) return p[n];
	int pn_3 = getp(n-3, p);
	int pn_2 = getp(n-2, p);
	int pn_1 = getp(n-1, p);
	p[n] = pn_3 + pn_2 + pn_1;
	return p[n];
}
int getf(int n, vector<int> & f, vector<int> & p){
	if (f[n] != -1) return f[n];
	int pn_3 = getp(n-3, p);
	int fn_3 = getf(n-3, f, p);
	int pn_2 = getp(n-2, p);
	int fn_2 = getf(n-2, f, p);
	int pn_1 = getp(n-1, p);
	int fn_1 = getf(n-1, f, p);
	f[n] = pn_3 + fn_3 + pn_2 + fn_2 + pn_1 + fn_1;
	return f[n];
}
/*
void s_getf(int n, vector<vector<string>> & f, vector<vector<string>> & p){
	if(f[n].size()!= 0) return f[n];
	vector<string> pn_3 = s_getp(n-3,p);
	vector<string> fn_3 = s_getf(n-3, f, p);
	vector<string> pn_1 = s_getp(n-1,p);
	vector<string> fn_1 = s_getf(n-1, f, p);
	vector<string> ans;
	for (auto & s: pn_3){
		ans.push_back("AP" + s);
		ans.push_back("AL" + s);
		ans.push_back("LA" + s);
		ans.push_back("PA" + s);
	}
	for (auto & s: fn_3){
		ans.push_back("AP" + s);
		ans.push_back("AL" + s);
		ans.push_back("LA" + s);
		ans.push_back("PA" + s);
}
*/
int checkRecord(int n) {
	vector<int> f(n + 1, -1);
	f[0] = 1;
	f[1] = 3;
	f[2] = 8;
	vector<int> p(n, -1);
	p[0] = 1;
	p[1] = 2;
	p[2] = 4;
	return getf(n,f,p);
}
int main(void) {
	cout << checkRecord(5);
}