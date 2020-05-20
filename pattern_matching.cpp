#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
struct sample{
    int ind;
};
string find_prefix(vector<string*> patterns){
    int ind = 0;
    char curletter = '*';
    string ans = "";
    while(ind <100){
        curletter = '*';
        auto it = patterns.begin();
        if (it == patterns.end()) break;
        while(it != patterns.end()){
            string* pat = *it;
            string pattern = *pat;
            if (ind >= pattern.size() || pattern[ind] == '*'){
                patterns.erase(it);
            }else{
                if (curletter == '*'){
                    curletter = pattern[ind];
                }else if(curletter != pattern[ind]){
                    ans = "*";
                    return ans;
                }
                it ++;
            }
        }
        if(curletter != '*'){
            ans.push_back(curletter);
        }
        ind ++ ;
    }
    return ans;
}
string find_suffix(vector<string*> patterns){
    int ind = 0;
    char curletter = '*';
    string ans = "";
    ans.reserve(100);
    while(ind < 100){
        curletter = '*';
        auto it = patterns.begin();
        if (it == patterns.end()) break;
        while(it != patterns.end()){
            string* pat = *it;
            string pattern = *pat;
            int new_ind = pattern.size() - 1 - ind;
            if (ind >= pattern.size() || pattern[new_ind] == '*'){
                patterns.erase(it);
            }else{
                if (curletter == '*'){
                    curletter = pattern[new_ind];
                }else if(curletter != pattern[new_ind]){
                    ans = "*";
                    return ans;
                }
                it ++;
            }
        }
        if(curletter != '*'){
            ans.insert(0,1,curletter);
        }
        ind ++;
    }
    return ans;
}
string solve(vector<string*> &patterns){
    string ans = find_prefix(patterns);
    if (ans == "*") return "*";
    string suff = find_suffix(patterns);
    if(suff == "*") return "*";
    for (auto &ppat:patterns){
        string pattern = *ppat;
        for (int i=0; i<pattern.size(); i++){
            if (pattern[i] != '*'){
                ans.push_back(pattern[i]);
            }
        }
        /*
        int  i =0;
        while(pattern[i]!= * && i < pattern.size()){
            i++;
        }
        if (i==pattern.size()){
        }else{
            i++;
            while(i < pattern.size()){
                
            }
        }*/

    }
    ans.append(suff);
    return ans;
}
int main(void) {
    int t,n;
    scanf("%d", &t);
    for (int test_case=1; test_case<=t; test_case++){
        vector<string *>patterns;
        scanf("%d", &n);
        for (int i=0;i<n;i++){
            string* temp = new string;
            cin >> *temp;
            patterns.push_back(temp);
        }
        cout << "Case #" << test_case << ": " << solve(patterns) << "\n";
    }
}
