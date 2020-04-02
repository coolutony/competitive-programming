#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iterator>
#include <unordered_map>
using namespace std;

const int N=100001;

int n,m;
struct Trie {
    bool is_end_of_word = false;
    unordered_map<char, Trie*> children;
};
void insert(Trie*& root, const string & str){
    Trie* temp = root;
    for (int i = 0; i< str.length(); i++){
        char c = str[i];
        if (temp->children.find(c) == temp->children.end()){
            Trie* new_trie = new Trie;
            temp->children[c] = new_trie;
        }
        temp = temp->children[c];
    }
    temp->is_end_of_word = true;
}
int cal_f (Trie*& v, int depth){
    if (v->children.size() == 0) {
        return 1;
    }
    int r = 0;
    for (const auto &keyval: v->children){
        Trie* child = keyval.second;
        r += cal_f(child, depth +1);
    }
    if (v->is_end_of_word) {
        r ++;
    }
    if (r >= 2 && depth > 0){
        r -= 2;
    }
    return r;
}

void reverse_words(vector<string>& words){
    for (auto& word: words){
        reverse(word.begin(), word.end());
    }
}
int main(void) {
    int t,n;
    scanf("%d", &t);
    for(int num = 1; num <= t; num++){
        vector<string> words;
        Trie* root = new Trie; 
        scanf("%d", &n);
        for (int i=0; i<n; i++){
            string temp="";
            cin >> temp;
            words.push_back(temp);
        }
        reverse_words(words);
        for (auto& word : words){
            insert(root, word);
        }
        int f_val = cal_f(root, 0);
        printf("Case #%d: %d\n", num, n-f_val);
    }
}
