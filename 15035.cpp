#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N=100001;

int n,t;

int main(void) {
	vector<int> settings;
	int setting;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &setting);
		settings.push_back(setting);
	}
	scanf("%d", &t);
	int min = t;
	int best_setting = -1;
	for (int i = 0; i< n ; i++){
		if (min > t % settings[i]){
			min = t % settings[i];
			best_setting = settings[i];
			if (min == 0){
				break;
			}
		}
	}
	cout << best_setting;
}
