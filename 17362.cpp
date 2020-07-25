#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))
#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))
using namespace std;


int main(void) {
	int n;
	scanf("%d", &n);
	int small =  (n-1) % 8;
	if(small == 0 )cout << 1;
	else if(small == 1 || small == 7) cout <<2;
	else if(small == 2 || small == 6) cout<< 3;
	else if(small == 3 || small == 5) cout << 4;
	else if(small == 4) cout<< 5;
}