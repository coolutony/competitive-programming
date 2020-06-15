#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <utility> 
#include <string>
#include <set>
#define MIN(X,Y) ((X) < (Y) ? : (X) : (Y))
#define MAX(X,Y) ((X) > (Y) ? : (X) : (Y))
using namespace std;
struct cPoint {
    int ind;
    int x;
    int y;
    int size = 0; 
    cPoint * lead = NULL;
    cPoint(int i, int x_point, int y_point){
        ind = i;
        x = x_point;
        y = y_point;
        lead = NULL;
        size = 1;
    }
    
};
struct obj {
    bool isEdge = false; //If fase, is query
    cPoint* first;
    cPoint* second;
    int health;
    int ind;
    obj(bool isedge, cPoint* f, cPoint* s, int h, int i){
        isEdge = isedge;
        first = f;
        second = s;
        health = h;
        ind = i;
    }
};
bool x_cmp(cPoint* a, cPoint* b){
    return a->x< b->x;
}
bool y_cmp(cPoint* a, cPoint* b){
    return a->y < b->y;
}
bool h_cmp(obj a, obj b){
    if (a.health == b.health){
        return a.isEdge;
    }
    return a.health < b.health;
}
int iabs(int i){
    if (i>0) return i;
    return -i;
}
cPoint* find(cPoint *c){
    if (c-> lead == NULL) return c;
    cPoint * leader = find(c->lead);
    c -> lead = leader;
    return leader;
}
void unite(cPoint *a, cPoint *b){
    if (a==b) return;
    if( a-> size > b->size){
        b-> lead = a;
        a -> size += b -> size;
    }else{
        a -> lead = b;
        b -> size += a -> size;
    }
}
int main (void){
    int n, q;
    scanf("%d %d", &n, &q);
    vector<cPoint *> check_point;
    for (int i =0; i < n; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        cPoint* temp = new cPoint(i,x,y);
        check_point.push_back(temp);
    }
    vector<obj> objects;
    for (int i =0; i< q; i++){
        int a,b, health;
        scanf("%d %d %d", &a, &b, &health);
        a--;
        b--;
        objects.push_back(obj(false, check_point[a],check_point[b],health,i));
    }
    vector<cPoint *> x_sorted(check_point);
    vector<cPoint *> y_sorted(check_point);
    sort(x_sorted.begin(), x_sorted.end(), x_cmp);
    sort(y_sorted.begin(), y_sorted.end(), y_cmp);
    for(int i =0; i< n - 1; i++){
        objects.push_back(obj(true, x_sorted[i], x_sorted[i+1], iabs(x_sorted[i]->x - x_sorted[i+1]->x), i));
        objects.push_back(obj(true, y_sorted[i], y_sorted[i+1], iabs(y_sorted[i]->y - y_sorted[i+1]->y), i));
    }
    sort(objects.begin(), objects.end(), h_cmp);
    vector<bool> query(q,false);
    for(int i =0; i<objects.size(); i++){        
        if(objects[i].isEdge){
            unite(find(objects[i].first), find(objects[i].second));//TODO
        }else{
            query[objects[i].ind] = find(objects[i].first) == find(objects[i].second);//TODO
        }
    }
    for (int i = 0; i<query.size(); i++){
        if(query[i]){cout << "YES\n";}
        else {cout << "NO\n";}
    }
}