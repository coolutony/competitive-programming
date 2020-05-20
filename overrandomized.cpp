#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
struct sample{
    int ind;
};
void update(map<char, int> & large, string & q, string & r){
    int digit_q = q.size();
    int digit_r = r.size();
    for (int i = 0; i< digit_r; i++){
        if (large.count(r[i]) == 0){
            large[r[i]] = 0;
        }
    }
    if(digit_q == digit_r && q[0] != '-1'){
        if (large[r[0]] == 0){
            large[r[0]] = q[0]-'0';
        }
        else if (large[r[0]]> q[0]-'0'){
            large[r[0]] = q[0]-'0';
        }
    }
}
string solve(vector<pair<string, string>> queries){
    map <char, int> large;
    char ans_prep[11];
    for (int i = 0; i<queries.size();i++){
        string q = queries[i].first;
        string r = queries[i].second;
        update(large, q, r);
    }
    for (const auto &mypair : large){
        ans_prep[mypair.second] = mypair.first;
    }
    string ans = "";
    for (int i =0; i<10;i++){
        ans.push_back(ans_prep[i]);
    }
    return ans;
}
int main(void) {
    int t,u;
    scanf("%d", &t);
    for (int test_case=1; test_case<=t; test_case++){
        vector<pair<string, string> > queries;
        scanf("%d", &u);
        for (int i =0; i< 10000; i++){
            string s1;
            string s2;
            cin >> s1;
            cin >> s2;
            queries.push_back(make_pair(s1,s2));
        }
        cout << "Case #" << test_case << ": " << solve(queries) << "\n";
    }
}
