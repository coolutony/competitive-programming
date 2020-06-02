#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N=100001;

int n,m;
int prize_17 (int p){
	if (p== 1) return 5000000;
	if ( 2 <= p && p <= 3) return 3000000;
	if ( 4 <= p && p <= 6) return 2000000;
	if ( 7 <= p && p <= 10) return 500000; 
	if ( 11 <= p && p <= 15) return 300000;
	if ( 16 <= p && p <= 21) return 100000;
	return 0;
}
int prize_18 (int p){
	if (p== 1) return 5120000;
	if ( 2 <= p && p <= 3) return 2560000;
	if ( 4 <= p && p <= 7) return 1280000;
	if ( 8 <= p && p <= 15) return 640000; 
	if ( 16 <= p && p <= 31) return 320000;
	return 0;
}
int main(void) {
	int t;
	scanf("%d", &t);
	for (int i =0 ; i< t; i++){
		scanf("%d%d", &n, &m);
		cout << prize_17(n) + prize_18(m) << "\n";
	}
}