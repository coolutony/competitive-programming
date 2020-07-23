#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#define MIN(X,Y) ((X) < (Y) ? : (X) : (Y))
#define MAX(X,Y) ((X) > (Y) ? : (X) : (Y))
using namespace std;

const int N=100001;

int n,m;
using pi = pair<int,int>;
template <class Key, class Val>
struct mheap{
    //heap with element of smallest value at the top
    map<Key, Val> keyval;
    int size = 0;
    vector<Key> container;
    map<Key, int> position;
    Key pop(){
        Key popped = container[0]; // Here an error would occur if user tries to pop an empty heap
        //cout << '\nPop:' << popped << '\n'; //DEBUG
		position[container[0]] = -1;
        container[0] = container[size-1];
        size--;
        heapify_down(0);
        return popped;
    }
    void insert(Key element, Val value){
        size ++;
        container.push_back(element);
        position[element] = size -1;
        keyval[element] = value;
        heapify_up(size -1);
    }
    void heapify_down(int i){
        if (2*i > size-1) return;
        int j = 2*i;
        if(2*i < size-1){
            if (keyval[container[2*i+1]]<keyval[container[2*i]]){
                j = 2*i + 1;
            }
        }
        if (keyval[container[i]]>keyval[container[j]]){
            Key temp = container[i];
            container[i] = container[j];
            container[j] = temp;
            position[container[i]] = i;
            position[container[j]] = j;
            heapify_down(j);
        }
    }
    void heapify_up(int i){
        if (i==0) return;
        int j = i/2;
        if(keyval[container[i]] < keyval[container[j]]){
            Key temp = container[i];
            container[i] = container[j];
            container[j] = temp;
            position[container[i]] = i;
            position[container[j]] = j;
            heapify_up(j);
        }
    }
    void update_key(Key element, Val newval){
		if(keyval.count(element) == 0 || position[element] == -1){ 
			return;
		}
        Val oldval = keyval[element];
        keyval[element] = newval;
        if (oldval > newval){
            heapify_up(position[element]);
        }else if (oldval < newval) {
            heapify_down(position[element]);
        }
    }
};
void create_data(vector<vector<char>> & seats, vector<vector<vector<pi>>> & adj_list, mheap<pi,int> & edge_count, int & seat_count){
	vector<int> mod_x = {-1,-1,0,0,1,1};
	vector<int> mod_y = {-1,1,-1,1,-1,1};
	for(int i = 0; i < seats.size(); i++){
		for(int j = 0; j < seats[0].size(); j++){
			if (seats[i][j] == '#') continue;
			seat_count ++;
			int count = 0;
			for(int k =0; k < 6; k++){
				int x = i + mod_x[k];
				int y = j + mod_y[k];
				if(x < 0 || y < 0 || x >= seats.size() || y >= seats[0].size()) continue;
				if (seats[x][y] == '.'){
					adj_list[i][j].push_back(make_pair(x,y));
					count ++;
				}
			}
			if (count > 0) edge_count.insert(make_pair(i,j),-count);
		}
	}
}
int maxStudents(vector<vector<char>>& seats) {
	vector<vector<vector<pi>>> adj_list(seats.size(),vector<vector<pi>>(seats[0].size(), vector<pi>())); //adj_list[i][j] has its neighbors
	mheap<pi,int> edge_count;
	int seat_count = 0;
	create_data(seats,adj_list,edge_count,seat_count); //TODO
	while(edge_count.size > 0){
		pi to_del = edge_count.pop();
        cout << "to_del: " << to_del.first << ", " << to_del.second << "\n"; //DEBUG
        cout << "to_del's count: " << edge_count.keyval[to_del] << "\n"; //DEBUG
		if(edge_count.keyval[to_del] == 0) break;
		seat_count --;
		for (pi & neigh : adj_list[to_del.first][to_del.second]){
			edge_count.update_key(neigh,edge_count.keyval[neigh]+1);
		}
	}
    return seat_count;

}
int main(void) {
	vector<vector<char>> seats {{'.','.','#','.','.'},{'.','.','.','.','#'},{'.','#','#','#','.'},{'.','#','#','#','.'}};
	cout << maxStudents(seats);
}