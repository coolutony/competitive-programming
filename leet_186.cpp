#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#define MIN(X,Y) ((X) < (Y) ? : (X) : (Y))
#define MAX(X,Y) ((X) > (Y) ? : (X) : (Y))
using namespace std;

const int N=100001;

int n,m;
void reverseWords(vector<char>& s) {
	reverse(s.begin(), s.end());
	auto start = s.begin();
	auto end = start;
	while(start < s.end()){
		while(end != s.end() && * end != ' '){
			end ++;
		}
		reverse(start,end);
		start = end +1;
		end = start;
	}
}
int main(void) {
	vector<char> s = {'t','h','e',' ','s','k','y',' ','i','s',' ','b','l','u','e'};
	reverseWords(s);
	for(auto c : s){
		cout << c;
	}
}