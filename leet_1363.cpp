#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))
#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))
using namespace std;

const int N=100001;

int n,m;
string largestMultipleOfThree(vector<int>& digits) {
	sort(digits.begin(),digits.end(), greater<int>());
	int sum = 0;
	vector<int> last (3,-1);
	vector<int> second_last (3,-1);
	for(int i = 0; i < digits.size(); i++){
		sum += digits[i];
		if (digits[i] % 3 == 1) {
			second_last[1] = last[1];
			last[1] = i;
		}
		if (digits[i] % 3 == 2) {
			second_last[2] = last[2];
			last[2] = i;
		}
	}
	if (sum%3 == 0){
		if(digits[0] == 0) return "0";
		else{
			string ans = "";
			for(int i = 0; i < digits.size(); i++){
				ans.push_back('0'+digits[i]);
			}
			return ans;
		}
	}else{
		int rem = sum % 3;
		if(last[rem]!=-1){
			string ans = "";
			for(int i = 0; i < digits.size(); i++){
				if(i == last[rem]) continue;
				ans.push_back('0'+digits[i]);
			}
			if(ans[0] == '0') return "0";
			return ans;
		}
		else{
			if (second_last[3-rem] == -1) return "";
			string ans = "";
			for(int i = 0; i < digits.size(); i++){
				if(i == last[3 - rem] || i == second_last[3-rem]) continue;
				ans.push_back('0'+digits[i]);
			}
			if(ans[0] == '0') return "0";
			return ans;
		} 
	}
	
}
int main(void) {
	vector<int> digits = {8,1,9};
	cout << largestMultipleOfThree(digits);
}