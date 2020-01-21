#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int N=100001;
char s[1000];
vector<int> trace;
int n,m;
int l;
int main(void) {
	cin >> s;
	l = strlen(s); 
	char min = '{'; //bigger than all alphabet characters 
	for (int i = 0; i<l; i++){
		min  = s[i];
		int mini = i;
		for(int j = i+1; j<l; j++){
			if (min > s[j]){
				min = s[j];
				mini = j;
			}
		}
		if (mini != i){
			trace.push_back(mini);
			trace.push_back(i); 
		}
		s[mini] = s[i];

	}
	for (auto it = trace.rbegin(); it != trace.rend(); it ++){
		int first = *it + 1;
		//cout << *it + 1 << " ";
		it ++;
		int second = *it +1;
		//cout << *it + 1 << "\n";
		cout << second << " " << first << "\n";
	}


}
