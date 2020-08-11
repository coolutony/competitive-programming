#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))
#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))
using namespace std;

const int N=100001;

int n,m;
void swap(int & a, int & b){
	int temp = a;
	a = b;
	b = temp;
}
int gcd(int a, int b){
	if (a<b) {
		swap(a,b);
	}
	// a >= b
	while(a != 0 && b != 0){
		a = a % b;
		swap(a,b);
	}
	return a;
}
bool tens(int a){
	while(a%2 == 0) a /= 2;
	while(a%5 == 0) a /= 5;
	return a == 1;
}
string fractionToDecimal(int numerator, int denominator) {
	int g = gcd(numerator, denominator);
	numerator /= g;
	denominator /= g;
	string s;
	if (tens(denominator)){
		s = to_string(double(numerator)/double(denominator));
		if(s != "0"){
			while(s[s.size()-1] == '0'){
				s.erase(s.size()-1);
			}
			if(s[s.size()-1] == '.'){
				s.erase(s.size()-1);
			}
		}
		return s;
	}
	int ord = 1;
	int nines = 9;
}
int main(void) {
	int a,b;
	scanf("%d%d", &a, &b);
	cout << fractionToDecimal(a,b);
}