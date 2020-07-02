#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#define MIN(X,Y) ((X) < (Y) ? : (X) : (Y))
#define MAX(X,Y) ((X) > (Y) ? : (X) : (Y))
using namespace std;

const int N=100001;

int n,m;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
TreeNode* trimLeft(TreeNode * root, int L){
	while(root != nullptr && root -> val < L){
		root = root -> right;
	}
	if(root == nullptr) return root;
	TreeNode * prev = root;
	TreeNode * cur = root -> left;
	while(cur != nullptr){
		if (cur -> val >= L){
			prev = cur;
			cur = cur -> left;
		} else{
			prev -> left = cur -> right;
			cur = cur -> right;
		}
	}
	return root;
}
TreeNode* trimRight(TreeNode * root, int R){
	while(root != nullptr && root -> val > R){
		root = root -> left;
	}
	if(root == nullptr) return root;
	TreeNode * prev = root;
	TreeNode * cur = root -> right;
	while(cur != nullptr){
		if (cur -> val <= R){
			prev = cur;
			cur = cur -> right;
		} else{
			prev -> right = cur -> left;
			cur = cur -> left;
		}
	}
	return root;
}
TreeNode* trimBST(TreeNode* root, int L, int R) {
	root = trimLeft(root,L);
	root = trimRight(root,R);
	return root;
}
int main(void) {
	scanf("%d%d", &n, &m);
}