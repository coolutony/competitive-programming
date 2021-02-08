#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

const int N=100001;

//vector<vector<int>> count_c;
unordered_map<long int,double> prob_c;

double prob(int dice, int pips){
	if (dice >=1000) return 0;
	if (pips > dice * 6 || pips < dice) return 0;
	long int dp = (long int) dice * 10000000 + pips;
	if (prob_c.count(dp) > 0) return prob_c[dp];
	double ret = 0;
	//for (size_t p = dice/2; p<=pips && p <= 3*dice; p++){
	for (size_t p = dice/2; p<=pips ; p++){
		//cout << p << "\n";
		ret += prob(dice/2,p) * prob(dice-dice/2,pips-p);
	}
	prob_c[dp] = ret;
	return ret;
}

int main(void) {
	int t;
	int n,k;
	scanf("%d", &t);
	prob_c[10000001]=1.0/6;
	prob_c[10000002]=1.0/6;
	prob_c[10000003]=1.0/6;
	prob_c[10000004]=1.0/6;
	prob_c[10000005]=1.0/6;
	prob_c[10000006]=1.0/6;
	/*
	for (int m = 800; m <= 800; m++){
		for(int p = m; p<= 6*m; p++){
			if((int)(prob(m,p)*100) > 0){
				cout << "m,p: " << m << ", " << p << ": "<< (int) (prob(m,p) * 100) << "\n";
			}
		}
	}*/
	for (int test_i = 0; test_i<t; test_i++){
		scanf("%d", &n);
		scanf("%d", &k);
		cout << (int) (prob(n,k) * 100) <<"\n"; 
	}
}
