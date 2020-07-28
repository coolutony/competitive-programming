#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))
#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))
using namespace std;

const int N=100001;

int n,m;
vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
	vector<int> ans;      
	if (tomatoSlices % 2 == 1) return ans;
	int x = (tomatoSlices - 2 * cheeseSlices)/2;
	int y = cheeseSlices - x;
	if (x < 0 || y < 0) return ans;
	ans.push_back(x);
	ans.push_back(y);
	return ans;
}
int main(void) {
	scanf("%d%d", &n, &m);
}