#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))
#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))
using namespace std;

const int N=100001;

int n,m;
int minDominoRotations(vector<int>& A, vector<int>& B) {
	int min = -1;
	int first = A[0];
	int second = B[0];
	int top_first = 1;
	int top_second = 0;
	if(A[0] == B[0]){
		top_first = 0;
		second = -1;
	}
	int i = 1;
	for(i = 1; i < A.size(); i++){
		if(A[i] == first && B[i] == second){
			top_first ++;
		}else if(A[i] == second && B[i] == first){
			top_second++;
		}else {
			break;
		}
	}
	if(i == A.size()){
		return MIN(top_first,top_second);
	}
	int top_not;
	int bot_not;
	int num;
	//1,3 case and 2,4 case can be united with using ||
	if(A[i] == first){
		num = first;
		bot_not = top_first;
		top_not = top_second;
		if(B[i] != first) bot_not ++;
	}else if (A[i] == second){
		num = second;
		bot_not = top_second;
		top_not = top_first;
		if(B[i] != second) bot_not ++;
	}else if (B[i] == first){
		num = first;
		bot_not = top_first;
		top_not = top_second;
		if(A[i] != first) top_not ++;
	}else if (B[i] == second){
		num = second;
		bot_not = top_second;
		top_not = top_first;
		if(A[i] != second) top_not ++;
	}else {return -1;}
	i++;
	while(i<A.size()){
		if(A[i] != num && B[i] != num) return -1;
		if(A[i] != num) top_not ++;
		if(B[i] != num) bot_not ++;
		i++;
	}
	return MIN(top_not, bot_not);
}
int main(void) {
	scanf("%d%d", &n, &m);
}