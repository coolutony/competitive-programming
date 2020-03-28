#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N=100001;

int n,m;

bool pairs_are_good(pair <int, int> cur, pair <int, int> dest){
    int r1 = cur.first;
    int c1 = cur.second;
    int r2 = dest.first;
    int c2 = dest.second;
    if (r1 == r2) return false;
    if (c1 == c2) return false;
    if (r1 - c1 == r2 - c2) return false;
    if (r1 + c1 == r2 + c2) return false;
    return true;
}
bool check_answer(int R, int C, vector< pair <int, int>> answer){
    printf("Check R:%d, C:%d", R, C);
    if (R+C <= 6) return true;
    bool is_there[R+1][C+1];
    for (int i = 0; i<R+1; i++){
        for (int j=0; j< C+1; j++){
            is_there[i][j] = false;
        }
    }
    //Check the size is exact (no duplicate spots)
    if (answer.size() != R * C){
        printf("\n------- Size: %d when expected : %d\n", answer.size(), R*C);
        return false;
    }
    //Mark spots visited in the answer
    for (int i=0; i < answer.size(); i++){
        is_there[answer[i].first][answer[i].second] = true;
    }
    //Check every move is valid
    for (int i =1; i < answer.size(); i++){
        if (!pairs_are_good(answer[i-1],answer[i])){
            printf("\nPair (%d,%d) to (%d, %d) WRONG\n", answer[i-1].first, answer[i-1].second , answer[i].first, answer[i].second);
            return false;
        }
    }
    //Check all spots are visited
    bool all_visited = true;
    for (int i=1; i < R+1; i++){
        for (int j=1; j< C+1; j++){
            if(!is_there[i][j]) {
                printf("\n%d %d has not been visited", i, j);
                all_visited = false;
            }
        }
    }
    if (all_visited) printf("  CORRECT");
    printf("\n");
    return all_visited;
}
vector< pair <int, int> > ans_4_4(){
    vector< pair <int, int> > ans_4_4;
    ans_4_4.push_back(make_pair(1,1));
    ans_4_4.push_back(make_pair(2,3));
    ans_4_4.push_back(make_pair(3,1));
    ans_4_4.push_back(make_pair(4,3));
    ans_4_4.push_back(make_pair(2,2));
    ans_4_4.push_back(make_pair(4,1));
    ans_4_4.push_back(make_pair(3,3));
    ans_4_4.push_back(make_pair(1,2));
    ans_4_4.push_back(make_pair(2,4));
    ans_4_4.push_back(make_pair(3,2));
    ans_4_4.push_back(make_pair(4,4));
    ans_4_4.push_back(make_pair(1,3));
    ans_4_4.push_back(make_pair(4,2));
    ans_4_4.push_back(make_pair(1,4));
    ans_4_4.push_back(make_pair(2,1));
    ans_4_4.push_back(make_pair(3,4));
    return ans_4_4;
}
vector< pair <int, int> > ans_3_4(){
    vector< pair <int, int> > ans_3_4;
    ans_3_4.push_back(make_pair(1,1));
    ans_3_4.push_back(make_pair(3,2));
    ans_3_4.push_back(make_pair(2,4));
    ans_3_4.push_back(make_pair(1,2));
    ans_3_4.push_back(make_pair(3,3));
    ans_3_4.push_back(make_pair(2,1));
    ans_3_4.push_back(make_pair(1,3));
    ans_3_4.push_back(make_pair(3,4));
    ans_3_4.push_back(make_pair(2,2));
    ans_3_4.push_back(make_pair(1,4));
    ans_3_4.push_back(make_pair(3,1));
    ans_3_4.push_back(make_pair(2,3));
    return ans_3_4;
}
vector< pair <int, int> > ans_3_5(){
    vector< pair <int, int> > ans_3_5;
    ans_3_5.push_back(make_pair(1,1));
    ans_3_5.push_back(make_pair(2,4));
    ans_3_5.push_back(make_pair(3,2));
    ans_3_5.push_back(make_pair(1,5));
    ans_3_5.push_back(make_pair(2,3));
    ans_3_5.push_back(make_pair(3,1));
    ans_3_5.push_back(make_pair(1,4));
    ans_3_5.push_back(make_pair(2,2));
    ans_3_5.push_back(make_pair(3,5));
    ans_3_5.push_back(make_pair(1,2));
    ans_3_5.push_back(make_pair(2,5));
    ans_3_5.push_back(make_pair(3,3));
    ans_3_5.push_back(make_pair(2,1));
    ans_3_5.push_back(make_pair(1,3));
    ans_3_5.push_back(make_pair(3,4));
    return ans_3_5;
}
vector< pair <int, int> > reverse(vector< pair <int, int> > input){
    vector< pair <int, int> > reversed;
    for (int i = 0; i<input.size(); i++){
        reversed.push_back(make_pair(input[i].second,input[i].first));
    }
    return reversed;
}

vector< pair <int, int> > answer_gen_2(int start, int C, int offset){
    vector< pair <int, int> > answer;
    int col = start;
    for (int i = 1; i<= C; i++){
        col = start + i -1;
        answer.push_back(make_pair(1+offset, col));
        col += 3;
        if (col > C) col -= C;
        answer.push_back(make_pair(2+offset, col));
    }
    return answer;
}
vector< pair <int, int> > answer_gen_3(int start, int C, int offset){
    vector< pair <int, int> > answer;
    if (C == 5){
        return ans_3_5();
    }
    int col = start;
    for (int i = 1; i<= C; i++){
        col = start + i -1;
        answer.push_back(make_pair(1+offset, col));
        int col_new = col + 3;
        if (col_new > C) col_new -= C;
        answer.push_back(make_pair(2+offset, col_new));
        answer.push_back(make_pair(3+offset, col));
    }
    return answer;
}
//Answer gen for R>=5
vector< pair <int, int> > answer_gen_big(int R, int C){
    vector< pair <int, int> > answer;
    vector< pair <int, int> > temp;
    int start = 1;
    int count = 0;
    if (R % 2 == 1){
        temp = answer_gen_3(1,C,0);
        answer.insert(answer.end(),temp.begin(),temp.end());
        start = 1;
        while (!pairs_are_good(answer.back(), make_pair(answer.back().first+1, start)) & start <= 5) start ++;
        if (start ==6) printf("PROBLEM!\n"); 
        R -= 3;
        count += 3;
    }
    while(R > 0){
        temp = answer_gen_2(start,C,count); 
        answer.insert(answer.end(), temp.begin(), temp.end());
        start = 1;
        while (!pairs_are_good(answer.back(), make_pair(answer.back().first+1, start)) & start <= 5) start ++;
        if (start ==6) printf("PROBLEM!\n"); 
        R -= 2;
        count +=2;
    }
    return answer;
}
vector< pair <int, int> > answer_gen(int R, int C){
    if(R == 3 & C == 4) return ans_3_4();
    if(R == 4 & C == 3) return reverse(ans_3_4());
    if(R == 4 & C == 4) return ans_4_4();
    if(C >= 5) return answer_gen_big(R, C);
    if(C <= 4 & R >= 5) return reverse(answer_gen_big(C, R));
    printf("\nCase R: %d C: %d not classified\n", R, C);
    vector< pair <int, int> > dummy;
    return dummy;
}
void write_answer(int R, int C){
    if ((R == 2 & C == 2) |
        (R == 2 & C == 3) |
        (R == 2 & C == 4) |
        (R == 3 & C == 2) |
        (R == 3 & C == 3) |
        (R == 4 & C == 2) ){
        printf("IMPOSSIBLE\n");
    }else {
        vector< pair <int, int> > ans;
        if (R == 3 & C == 4){ 
            ans = ans_3_4();
        }else if (R == 3 & C== 5){
            ans = ans_3_5();
        }else if (R == 4 & C == 4){
            ans = ans_4_4();
        }else{
            ans = answer_gen(R,C);
        }
        printf("POSSIBLE\n");
        for (int i = 0; i < ans.size(); i++){
            printf("%d %d\n", ans[i].first, ans[i].second);
        }
    }
}
void print_ans (vector <pair <int, int> > ans){
    for (int i = 0; i< ans.size(); i++){
        printf("%d %d\n", ans[i].first, ans[i].second);
    }
}
int main(void) {
	vector<int> temp;
    vector< pair <int, int> > ans;

    for (int R = 2; R <= 20; R++){
        for(int C = 2; C <= 20; C++){
           check_answer(R,C,answer_gen(R,C));
        }
    }
}

