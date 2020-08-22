#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))
#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* oddEvenList(ListNode* head) {
	if (head == nullptr) return head;
	ListNode* fpoint = head;
	ListNode* shead = head->next;
	if(shead == nullptr) return head;
	ListNode* spoint = head -> next;
	while(spoint -> next != nullptr){
		fpoint -> next = spoint -> next;
		fpoint = fpoint -> next;
		if(fpoint -> next ==  nullptr) break;
		spoint -> next = fpoint -> next;
		spoint = spoint -> next;
	}
	fpoint -> next = shead;
	return head;
}
int main(void) {
	int n,m;
	scanf("%d%d", &n, &m);
}