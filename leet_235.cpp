#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))
#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	TreeNode* cur = root;
	while(cur != p && cur != q){
		if (p -> val < cur -> val && q -> val < cur -> val){
			cur = cur -> left;
		}else if(p -> val > cur -> val && q -> val > cur -> val){
			cur = cur -> right;
		}else{
			break;
		}
	}
	return cur;
}
int main(void) {
	int n,m;
	scanf("%d%d", &n, &m);

}