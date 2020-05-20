#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int add_p_at(string &s, int ind){
    if (!(s.at(ind) == '0' ||
        s.at(ind) == '1' || 
        s.at(ind) == '2' ||
        s.at(ind) == '3' ||
        s.at(ind) == '4' ||
        s.at(ind) == '5' ||
        s.at(ind) == '6' ||
        s.at(ind) == '7' ||
        s.at(ind) == '8' ||
        s.at(ind) == '9' )) return 1;
    int num = s.at(ind)-'0';
    for (int i = 0; i<num; i++){
        s.insert(ind,"(");
    }
    for (int i = 0; i<num; i++){
        s.insert(ind+num+1,")");
    }
    return 2*num + 1;
}
void expand(string &s){
    int ind = 0;
    while (ind<s.length()){
        ind += add_p_at(s,ind);
    }
}
void compress(string &s){
    for (int i = 0 ; i< s.length() - 1; i++){
        if (s[i] == ')' && s[i+1] == '(') {
			s.erase(i,2);
			i -=2;
		}
    }
}
string solve(string & s){
    expand(s);
    compress(s);
    return s;
}
int main(void) {
    int t;
    scanf("%d", &t);
    for (int i=1 ; i<=t ;i++){
        string s ="";
        cin >> s;
        cout << "Case #" << i << ": " << solve(s) << "\n";
    }
}
