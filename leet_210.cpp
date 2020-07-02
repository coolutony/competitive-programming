#include <stack>
#include <queue>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#define MIN(X,Y) ((X) < (Y) ? : (X) : (Y))
#define MAX(X,Y) ((X) > (Y) ? : (X) : (Y))
using namespace std;

const int N=100001;
struct node{
	int ind = -1;
	vector<node*> children = {};
	int precount = 0;
	node (int i){
		ind = i;
	}
};
int n,m;
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
	vector<bool> has_pre (numCourses,false);
	vector<node*> nodes;
	queue<node*> next;
	vector<int> complete;
	for(int i =0; i< numCourses; i++){
		nodes.push_back(new node(i));
	}
	for( const auto & pair: prerequisites){
		nodes[pair[0]] -> precount ++;
		nodes[pair[1]] -> children .push_back(nodes[pair[0]]);
	}
	for(node* nod : nodes){
		if (nod->precount == 0){
			nod -> precount ++; 
			next.push(nod);
		}
	}
	while(!next.empty()){
		node * next_node = next.front();
		next.pop();
		next_node -> precount --;
		if(next_node -> precount == 0){
			for (node * child : next_node -> children){
				next.push(child);
			}
			complete.push_back(next_node -> ind);
		}
	}
	if (complete.size() != numCourses){
		return vector<int>(0);
	}
	return complete;

}
int main(void) {
	vector<vector<int>> sample = { {1,0} };
	vector<int> ans = findOrder(2,sample);
	cout << "ANS\n";
	for(auto i : ans){
		cout << i << ", ";
	}
}