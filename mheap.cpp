#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
template <class Key, class Val>
struct mheap{
    //heap with element of smallest value at the top
    map<Key, Val> keyval;
    int size = 0;
    vector<Key> container;
    map<Key, int> position;
    Key pop(){
        Key popped = container[0]; // Here an error would occur if user tries to pop an empty heap
        //cout << "\nPop:" << popped << "\n"; //DEBUG
        position.erase(container[0]);
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
        Val oldval = keyval[element];
        keyval[element] = newval;
        if (oldval > newval){
            heapify_up(position[element]);
        }else if (oldval < newval) {
            heapify_down(position[element]);
        }
    }
};
/*
int main (void){
    //example input
    int adj_mat[5][5] = {{0, 1, -1, 3, -1},
                        {1, 0, 3, 4, 7},
                        {-1, 3, 0, 4, 1},
                        {3, 4, 4, 0 ,2},
                        {-1, 7, 1, 2, 0}};
    //acutal implementation
    int final_dist[5] = {0, -1, -1 ,-1 ,-1};
    int current_dist[5] = {0, -1, -1, -1, -1};                     
}
*/