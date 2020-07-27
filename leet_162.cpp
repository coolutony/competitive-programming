#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))
#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))
using namespace std;

const int N=100001;

int val(int n, vector<int> & nums){
	if (n == -1 || n == nums.size()) return INT32_MIN;
	else return nums[n];
};
int findPeakElement(vector<int> & nums){
	int start = 0;
	int end = nums.size()-1;
	int mid = (start+end+1)/2;
	while(!(val(mid-1,nums) <= val(mid,nums) && val(mid,nums) >= val(mid + 1,nums))){
		if(val(mid+1,nums) > val (mid,nums)){
			start = mid;
		}else{
			end = mid-1;
		}
		mid = (start+end+1)/2;
	}
	return mid;
}
int main(void) {
	vector<int> nums = {1,2,3,4};
	cout << findPeakElement(nums);
}