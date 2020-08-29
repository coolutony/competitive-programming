#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))
#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
bool isCompleteTree(TreeNode * root){
	queue <TreeNode *> q;
	queue <TreeNode *> next_q;
	bool flag = false;
	next_q.push(root);
	while(!next_q.empty()){
		q = next_q;
		next_q = queue<TreeNode *>();
		while(!q.empty()){
			TreeNode * next = q.front();
			q.pop();
			if(next -> left == nullptr){
				flag = true;
			}else{
				if(flag) return false;
				next_q.push(next->left);
			}
			if(next -> right == nullptr){
				flag = true;
			}else{
				if(flag) return false;
				next_q.push(next->right);
			}
		}
	}
	return true;
}
int main(void) {
	int n,m;
	scanf("%d%d", &n, &m);
}