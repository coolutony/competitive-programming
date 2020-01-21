#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N=100001;

int x,y,n;
float h[100];


int main(void) {
	scanf("%d%d", &x, &y);
	scanf("%d", &n);
	double divider  = y;
	int l,u;
	double f;
	for (int i = 0; i<n; i++){
		scanf("%d%d%lf", &l, &u, &f);
		divider += (u-l)*(f-1);
	}
	double ans = x/divider;
	printf("%3.8f",ans);
}
