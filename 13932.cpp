#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

const int N=100001;

int s[31];
int n,m;

int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%d", &s[i]);	
	}
	int* max_students_c = max_element(s+1 ,s+1+n);
	int max_room = distance(s, max_students_c);
	int max_students = s[max_room];
	int sum = 0;
	sum = accumulate(s+1, s+1+n, sum);
	if (sum - max_students < max_students){
		cout << "impossible";
		return 0;
	}
	cout << max_room << " ";
	for (int i =1; i<=n;i++){
		if (i != max_room) cout << i << " ";
	}
}
