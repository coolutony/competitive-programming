#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))
#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))
using namespace std;

int n;
bool can_do(){
	priority_queue<int> trees;
	int sum = 0;
	int one_count = 0;
	for(int i = 0; i<n; i++){
		int temp;
		scanf("%d", &temp);
		sum += temp;
		if (temp == 1) one_count ++;
		else trees.push(temp);
	}
	if(sum%3 != 0) return false;
	if(one_count == 0) return true;
	while(trees.size() > 0){
		int next = trees.top();
		trees.pop();
		one_count -= next / 2 ;
		if(one_count < 0) return true;
		one_count += next % 2;
		if(one_count == 0) return true;
	}
	return false;
}
int main(void) {
	scanf("%d", &n);
	if(can_do()) printf("YES");
	else printf("NO");
}