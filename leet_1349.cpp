#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))
#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))
using namespace std;

const int N=100001;

void print_seat(string & seats, int n, int m){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout<< seats[i*n + j] << ",";
        }
        cout << "\n";
    }
}
int max_seat(string & cur, unordered_map<string, int> & max_of, int n, int m){
    if (max_of.count(cur) > 0) return max_of[cur];
    int count = 0;  
    string to_pass = cur;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (to_pass[i*m + j] == '#') continue;
            to_pass[i*m + j] = '#';
            count  = MAX(count, max_seat(to_pass, max_of, n, m));
            if(j+1 < m){
                if (to_pass[i*m + j + 1] == '.') to_pass[i*m + j +1] = '#';
                if (i + 1 < n){
                    if (to_pass[(i+1)*m + j + 1] == '.') to_pass[(i+1)*m + j +1] = '#';
                }
            }
            if(i + 1 < n && j - 1 > -1){
                if (to_pass[(i+1)*m + j - 1] == '.') to_pass[(i+1)*m + j - 1] = '#';
            }
            count  = MAX(count, max_seat(to_pass, max_of, n, m) + 1);
        }
    }
    max_of[cur] = count;
    return count;
}
int maxStudents(vector<vector<char>>& seats) {
    int n = seats.size();
    int m = seats[0].size();
    string s_seats = "";
    for(int i = 0; i < seats.size(); i++){
        for (int j = 0; j < seats[0].size(); j++){
            s_seats.push_back(seats[i][j]);
        }
    }
    unordered_map<string, int> max_of;
    return max_seat(s_seats,max_of,n,m);
}
int main(void) {
	vector<vector<char>> seats {{'#','.','.','.','#'},{'.','#','.','.','#'},{'.','#','#','.','.'},{'.','.','#','#','#'}};
    string s_seats = "";
    for(int i = 0; i < seats.size(); i++){
        for (int j = 0; j < seats[0].size(); j++){
            s_seats.push_back(seats[i][j]);
        }
    }
    print_seat(s_seats,4,5);
	cout << maxStudents(seats);
}
