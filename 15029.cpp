#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

const int N=100001;
string balls[21]; 
int n,m;

int main(void) {
	map <string, int> bscores = {{"red", 1}, {"yellow", 2}, {"green", 3}, {"brown", 4}, {"blue", 5}, {"pink", 6}, {"black", 7}};
	scanf("%d", &n);
	int not_red = 0;	
	int reds = 0;
	int scores = 0;
	int max_score = 0;
	int temp_score;
	string ball;
	for (int i = 0; i<n; i++){
		cin >> ball;
		if (ball != "red") not_red = 1;
		else reds ++;
		temp_score = bscores[ball];
		scores += temp_score;
		max_score = temp_score > max_score ? temp_score : max_score;
	}
	if (!not_red){
		cout << 1;
	}
	else{
		int score = max_score * reds + scores;
		cout << score;
	}


}
