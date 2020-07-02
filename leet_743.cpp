#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define MIN(X,Y) ((X) < (Y) ? : (X) : (Y))
#define MAX(X,Y) ((X) > (Y) ? : (X) : (Y))
using namespace std;

const int N=100001;

int n,m;

struct Heap{
	int container[100];
	int size = 0;
	int val[100]; //dist val for each node (cur_key)
	int pos[100]; // pos in heap for each node
	void swap(int pos_a, int pos_b){
		int temp = container[pos_a];
		pos[container[pos_b]] = pos_a;
		container[pos_a] = container[pos_b];
		pos[temp] = pos_b;
		container[pos_b] = temp;
	}
	void bubble_up(int position){
		if(position == 0) return;
		int parent = position/2;
		if(val[container[parent]] > val[container[position]]){
			swap(position, parent);
			bubble_up(parent);
		}
	} 
	void bubble_down(int position){
		int child_left = 2*position;
		int child_right = 2*position + 1;
		if (child_left >= size) return;
		if (child_left == size -1){
			if (container[child_left] < container[position]){
				swap(position,child_left);
			}
			return; 
		}
		int smaller_child = child_left;
		if (val[container[child_left]] > val[container[child_right]]){
			smaller_child = child_right;
		}
		if (val[container[smaller_child]] < val[container[position]]){
			swap(position, smaller_child);
			bubble_down(smaller_child);
		}
	}
	void insert(int node, int value){
		container[size] = node;
		pos[node] = size;
		val[node] = value;
		bubble_up(size);
		size ++;
	}
	int pop(){
		int to_return = container[0];
		pos[to_return] = -1;
		swap(0,size-1);
		size --;
		bubble_down(0);
		return to_return;
	}
	void change_val(int node, int new_val){
		val[node] = new_val;
		if(pos[node] == -1) return;
		bubble_up(pos[node]);
		bubble_down(pos[node]);
	}
};
int networkDelayTime(vector<vector<int>>& times, int N, int K) {
	Heap d_heap;
	K --;
	vector<vector<pair<int, int>>> adj_list(N);
	for(int i =0; i<times.size(); i++){
		adj_list[times[i][0]-1].push_back(make_pair(times[i][1]-1,times[i][2]));
	}
	d_heap.insert(K, 0);
	for(int i =0; i<N; i++){
		if(i!=K){
			d_heap.insert(i,INT32_MAX);
		}
	}
	int selected = -1;
	while(d_heap.size > 0){
		selected = d_heap.pop();
		if (d_heap.val[selected] == INT32_MAX) return -1;
		for (const pair<int,int> & pi : adj_list[selected]){
			int neigh = pi.first;
			int weight = pi.second;
			if(d_heap.val[neigh] > d_heap.val[selected] + weight){
				d_heap.change_val(neigh, d_heap.val[selected] + weight);
			}
		}
	}
	//cout <<"selected: "<< selected << "\n"; //DEBUG
	return d_heap.val[selected];

}
int main(void) {
	vector<vector<int>> times = {{2,1,1},{2,3,1},{3,4,1}};
	cout << networkDelayTime(times, 4, 2);
}