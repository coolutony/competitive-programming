#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#define MIN(X,Y) ((X) < (Y) ? : (X) : (Y))
#define MAX(X,Y) ((X) > (Y) ? : (X) : (Y))
using namespace std;

const int N=100001;

int n,m;

string reversewords(string s){
	stack<char> st ;
	string ans;
	bool put_space = false;
	for (int i = s.size()-1; i >= 0; i--){
		char c = s[i];
		if (c==' '){
			while(!st.empty()){
				ans.push_back(st.top());
				st.pop();
				put_space = true;
			}
			if(put_space){
				ans.push_back(' ');
				put_space = false;
			}
		}else{
			st.push(c);
		}
	}
	while(!st.empty()){
		ans.push_back(st.top());
		st.pop();
	}
	while(ans[ans.size()-1] = ' '){
		ans.pop_back();
	}
	return ans;
}
int main(void) {
	scanf("%d%d", &n, &m);
}