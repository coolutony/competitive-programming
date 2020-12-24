#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))
#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))
using namespace std;

int nthUglyNumber (int n){
	priority_queue <int, vector<int>, greater<int> >pq;
	unordered_map <int,bool> inserted;	
	pq.push(1);
	int count = 1;
	int cur;
	bool continue_flag = false;
	while(count <=n){
		cur = pq.top();
		pq.pop();
		count ++; 
		if(continue_flag) continue;
		if(cur > INT32_MAX/2) continue;
		if (inserted.count(cur*2) == 0) {
			inserted[cur*2] = true;
			pq.push(cur*2);
		}
		if(cur > INT32_MAX/3) continue;
		if (inserted.count(cur*3) == 0) {
			inserted[cur*3] = true;
			pq.push(cur*3);
		}
		if(cur > INT32_MAX/4) continue;
		if (inserted.count(cur * 4) == 0){
			inserted[cur*4] = true;
			pq.push(cur*4);
		}
		if(cur >= INT32_MAX/5) continue;
		if (inserted.count(cur*5) == 0){
			inserted[cur*5] = true;
			pq.push(cur*5);
		} 
		//if(pq.size() >= n-count+1) continue_flag = true;
	}
	return cur;
}
int main(void) {
	cout << nthUglyNumber(4);
}