#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#define MIN(X,Y) ((X) < (Y) ? : (X) : (Y))
#define MAX(X,Y) ((X) > (Y) ? : (X) : (Y))
using namespace std;

const int N=100001;

int n,m;
bool reachingPoints(int sx, int sy, int tx, int ty) {
	int x = tx;
	int y = ty;
	while(sx != x && sy != y){
		if(x == y) return false;
		if(x > y){
			x = x % y;
		}else{
			y = y % x;
		}
		if (x == 0 || y == 0) return false;
	}
	if(x==y) return sx==sy;
	if(sx == x){
		if (x > y) return false;
		if (sx > sy) return false;
		if (sy > y) return false;
		return (y-sy)%x==0;
	}
	else{
		if (y > x) return false;
		if (sy > sx) return false;
		if (sx > x) return false;
		return (x-sx)%y==0;
	}
}
int main(void) {
	cout << reachingPoints(1,1,1,1);
}