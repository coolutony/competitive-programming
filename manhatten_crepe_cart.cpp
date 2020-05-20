#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N=100001;

int n,m;
int targeted(int height, vector< pair <int, bool> > const & people){
    int count = 0;
    for (const auto &person : people){
        int y = person.first;
        bool is_up = person.second;
        if ((height > y && is_up) || (height < y && !is_up)) count ++;
    }
    return count; 
}
vector <pair <int, bool> > project (vector < pair < pair <int, int>, char> > const & people, bool is_x){
    vector <pair <int, bool> > ret;
    for (const auto &person : people){
        if(is_x){
            if (person.second == 'E' ||person.second == 'W'){
                pair <int, bool> proj_per;
                if (person.second == 'E')
                    proj_per = make_pair(person.first.first, true);
                else if (person.second == 'W')
                    proj_per = make_pair(person.first.first, false);
                ret.push_back(proj_per);
            }
        } else{
            if (person.second == 'N' ||person.second == 'S'){
                pair <int, bool> proj_per;
                if (person.second == 'N')
                    proj_per = make_pair(person.first.second, true);
                else if (person.second == 'S')
                    proj_per = make_pair(person.first.second, false);
                ret.push_back(proj_per);
            }
        }
    }
    return ret;

}
pair <int, int> solve (vector < pair < pair <int, int>, char> > const & people, int Q){
    int x_tc_max = 0;
    int x_max = 0;
    int y_tc_max = 0;
    int y_max = 0;

    //find x coord
    vector <pair <int, bool> > x_people = project(people, true);
    for (int coord = 0; coord<=Q; coord++){
        int t_count = targeted(coord, x_people);
        if (t_count > x_tc_max) {
            x_tc_max = t_count;
            x_max = coord;
        }
    }
    //find y coord
    vector <pair <int, bool> > y_people = project(people, false);
    for (int coord = 0; coord<=Q; coord++){
        int t_count = targeted(coord, y_people);
        if (t_count > y_tc_max) {
            y_tc_max = t_count;
            y_max = coord;
        }
    }
    return make_pair(x_max,y_max);

}
int main(void) {
    int t,p,q;
    scanf("%d", &t);
    for (int tcase = 1; tcase<=t; tcase++){
        scanf("%d %d", &p, &q);
        vector < pair < pair <int, int>, char > > people;
        for(int i = 0; i<p; i++){
            int x = 0;
            int y = 0;
            char c = 'a';
            scanf("%d %d %c", &x, &y, &c);
            people.push_back(make_pair(make_pair(x,y),c));
        }
        pair <int, int> ans = solve(people, q);
        printf("Case #%d: %d %d\n", tcase, ans.first, ans.second);
    }
}
