#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))
#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))
using namespace std;

const int N=100001;

int n,m;

vector<string> findRestaurant1(vector<string>& list1, vector<string>& list2) {
	vector<string> ans;
	for(int sum = 0; sum < list1.size() + list2.size() - 1; sum++){
		if (sum < list2.size()){
			for (int i = 0; i <= sum && i <list1.size(); i++){
				int j = sum - i;
				if(list1[i] == list2[j]) ans.push_back(list1[i]); 
			}
		}else{
			for(int i = sum-list2.size()+1; i <= sum && i < list1.size(); i++){
				int j = sum - i;
				if(list1[i] == list2[j]) ans.push_back(list1[i]); 
			}
		}
		if(ans.size() > 0) return ans;

	}
	return ans;
}

vector<string> findRestaurant2(vector<string>& list1, vector<string>& list2) {
	vector<string> ans;
	map<string, int> dict;
	for(int i =0; i<list1.size(); i++){
		dict[list1[i]] = i;
	}
	int min = INT32_MAX;
 	for (int j = 0; j < list2.size(); j++){
		if (dict.count(list2[j]) > 0) min = MIN(min, j + dict[list2[j]]);
	}
	if(min == INT32_MAX) return ans;
	for(int i = MAX(0,min-int(list2.size())+1); i <= min && i < list1.size(); i++){
		int j = min -i;
		if(list1[i] == list2[j]) ans.push_back(list1[i]); 
	}
	return ans;

}

int main(void) {
	vector<string> list1 = {"Shogun","Tapioca Express","Burger King","KFC"};
	vector<string> list2 = {"KFC","Shogun","Burger King"};
	vector<string> ans = findRestaurant2(list1,list2);
	cout << "start\n";
	for(auto s: ans){
		cout << s << "\n";
	}
	cout << "fin\n";
}