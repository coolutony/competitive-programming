#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#define MIN(X,Y) ((X) < (Y) ? : (X) : (Y))
#define MAX(X,Y) ((X) > (Y) ? : (X) : (Y))
using namespace std;

const int N=100001;

int n,m;
int numWaterBottles(int numBottles, int numExchange) {
	int count = 0;
	int rem = 0;
	while(numBottles > 0){
		count += numBottles;
		int empty = (numBottles+rem);
		numBottles = empty/numExchange;
		rem = empty%numExchange;
	}
	return count;
}
int main(void) {
	cout << numWaterBottles(15,8);
}