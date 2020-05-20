#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
string solve(int x, int y, string & dir){
    int dist = x+y;
    for (int i =0; i<dir.size(); i++){
        if(dir[i]=='N'){
            y++;
        }else if(dir[i]=='S'){
            y--; 
        }else if(dir[i]=='E'){
            x++; 
        }else if(dir[i]=='W'){
            x--;
        }
        dist = abs(x)+abs(y);
        if (i+1 >= dist) return to_string(i+1);
    }
    return "IMPOSSIBLE";
}
int main(void) {
    int t, x, y;
    string dir;
    scanf("%d", &t);
    for (int test_case=1; test_case<=t; test_case++){
        scanf("%d %d", &x, &y);
        cin >> dir; 
        cout << "Case #" << test_case << ": " << solve(x,y,dir) << "\n";
    }
}
