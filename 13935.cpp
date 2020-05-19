#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

const int N=100001;

long long int findint(string a, bool rev, long long int start, long long int end){
    //base case
    if (start == end){
        return start;
    }
    //rec
    if(!rev){
        if (a[0] == '0'){
            return findint(a.substr(1), rev, start, (start+end-1)/2);
        }else if (a[0] == '1'){
            return findint(a.substr(1), !rev, (start+end+1)/2, end);
        }
    }
    else if(rev){
        if (a[0] == '0'){
            return findint(a.substr(1), rev, (start+end+1)/2, end);
        }else if (a[0] == '1'){
            return findint(a.substr(1), !rev, start, (start+end-1)/2);
        }
    }
    return -1;
}
int main(void) {
    int n;
    string a, b;
    scanf("%d", &n);
    cin >> a >> b;
    long long int length = 1;
    length = length << n;
    length --;
    long long int ind_a = findint(a, false, 0, length);
    long long int ind_b = findint(b, false, 0, length);
    long long int ans = ind_b - ind_a - 1;
    cout << ans << "\n";
}
