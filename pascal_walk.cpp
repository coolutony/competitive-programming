#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;
struct sample{
    int ind;
};
void dec2int(int n, int* bin){
    int i =0;
    while(n > 0){
        bin[i] = n%2;
        n/=2;
        i++;
    }
}
int pow(int b, int e){
    int ret = 1;
    for (int i=0; i<e; i++){
        ret *= b;
    }
    return ret;
}
void walk(vector<pair<int,int>> & path, int n, int* bin){
    int i = 0;
    int r = i+1;
    int sum  = 0;
    int start = 1; //(r,1) or (r,r)
    while(bin[i]!=-1){
        path.push_back(make_pair(r,start));
        if (bin[i] == 1){
            if (start == 1){
                for (int j=2; j<=r; j++){
                    path.push_back(make_pair(r,j));
                }
                start = r;
            }else if (start == r){
                for (int j=r-1; j>=1; j--){
                    path.push_back(make_pair(r,j));
                }
                start = 1;
            }
            sum += pow(2,i);
        }else{
            sum ++;
        }
        if (start == r) start ++; 
        i++;
        r++;
    }
    while(sum < n){
        path.push_back(make_pair(r,start));
        if (start == r) start ++; 
        r++;
        sum ++;
    }
}
vector<pair<int, int>> path (int n){
    vector<pair<int,int>> path;
    int level = (int)log2(n);
    int bin[40];
    for (int i=0; i<40; i++){
        bin[i] = -1;
    }
    dec2int(n-level, bin); 
    walk(path,n,bin);
    return path;
}
string solve(int n){
    vector<pair<int, int>> ans = path(n);
    string ansstr ="";
    for (auto &pos : ans){
        char line[20];
        sprintf(line, "\n%d %d", pos.first, pos.second);
        ansstr += line;
    }
    return ansstr;
}
int main(void) {
    int t,n;
    scanf("%d", &t);
    for (int test_case=1; test_case<=t; test_case++){
        scanf("%d", &n);
        cout << "Case #" << test_case << ": " << solve(n) << "\n";
    }
}
