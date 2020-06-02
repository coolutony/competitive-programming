#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <float.h>
using namespace std;

const int N=100001;

int n,m;

double stdv_of(vector<int> const & num, int start, int end){
	double average = 0;
	for(int i = start; i <= end; i++){
		average += num[i];
	}
	average /= end - start + 1;
	double disp = 0;
	for(int i = start; i <= end; i++){
		disp += (num[i] - average) * (num[i] - average);
	}
	disp /= end - start + 1;
	return sqrt(disp);
}
int main(void) {
	vector<int> num;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++){
		int temp = 0;
		scanf("%d", &temp);
		num.push_back(temp);
	}
	double min = DBL_MAX;
	for (int i = 0; i < n; i++){
		for (int j = i + m - 1; j < n; j++){
			double stdv = stdv_of(num, i, j);
			min = min < stdv ? min : stdv;
		}
	}
	printf("%.11f", min);
}