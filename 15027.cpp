#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N=100001;

int n,m;
vector<int> h,r,s;
int main(void) {
	scanf("%d", &n);
	int max_h = -1;
	int h_temp, r_temp, s_temp;
	for (int i = 0 ; i < n ; i++){
		scanf("%d", &h_temp);
		scanf("%d", &r_temp);
		scanf("%d", &s_temp);
		max_h = max(max_h,h_temp);
		h.push_back(h_temp);
		r.push_back(r_temp);
		s.push_back(s_temp);
	}
	int q, i;
	for (q = 0; q < 1825 * max_h; q++){
		for (i = 0; i<n; i++){
			if (r[i]<s[i]){
				if (!(q%h[i] <= r[i] || s[i] <= q%h[i])){
					break;
				}
			} else{
				if (!(s[i] <= q%h[i] && q%h[i] <= r[i])){
					break;
				}
			}
		}
		if (i==n){
			printf("%d", q);
			break;
		}
	}
	if (q == 1825 * max_h){
		cout << "impossible";
	}
}
