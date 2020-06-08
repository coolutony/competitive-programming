#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
using namespace std;

const int N=100001;
int n,m;

bool is_int (string s){
    for (char a : s){
        if (!(a=='0' || a=='1'|| a=='2'|| a=='3'|| a=='4'|| a=='5'|| a=='6'|| a=='7'|| a=='8'|| a=='9')){
            return false;
        }
    }
    return true;
}
struct Var {
    string name = "";
    string short_name ="";
    int size = 1;
    Var * leader = NULL;
    bool has_int = false;
    Var(string s){
        name =s;
        short_name = s;
        size = 1;
        leader = NULL;
        has_int = is_int(s);
    }
};
void print_ineq(pair<Var*, Var*> const & ineq){
    cout << ineq.first->short_name << "!=" << ineq.second->short_name;
}
void unite(Var* a, Var * b){
    if (a == b) return;
    if (a -> size > b -> size){
        b -> leader = a;
        a -> size += b -> size;
    } else{
        a -> leader = b;
        b -> size += a -> size;
    }
    a -> short_name = (a -> short_name).size() < (b -> short_name).size() ? a -> short_name : b -> short_name;
    b -> short_name = a -> short_name;
    if(a->has_int) b->has_int = true;
    else if(b->has_int) a->has_int = true;
}
Var * find(Var *a){
    if( a-> leader == NULL) return a;
    Var * lead = find(a->leader);
    a -> leader = lead;
    a -> short_name = lead -> short_name;
    return lead;
}
void parse(string & input, map<string,Var*> & elements, vector<pair<Var *, Var *>> & ineqs){
    int i = 0;
    int eqsign = input.find("==", i);
    int neqsign = input.find("!=", i);
    int end = input.find("&", i);
    while(end != -1){
        // parse s[i:end] and put it in to appropriate
        if(eqsign != -1 && eqsign < end){
            string lh = input.substr(i,eqsign-i);
            string rh = input.substr(eqsign+2,end-eqsign-2);
            if(elements.count(lh) == 0){
                elements[lh] = new Var(lh);
            }
            if(elements.count(rh) == 0){
                elements[rh] = new Var(rh);
            }
            unite(find(elements[lh]),find(elements[rh]));
            i = end +2;
            eqsign = input.find("==", i);
        }
        if(neqsign != -1 && neqsign < end){
            string lh = input.substr(i,neqsign-i);
            string rh = input.substr(neqsign+2,end-neqsign-2);
            if(elements.count(lh) == 0){
                elements[lh] = new Var(lh);
            }
            if(elements.count(rh) == 0){
                elements[rh] = new Var(rh);
            }
            ineqs.push_back(make_pair(elements[lh],elements[rh]));
            i = end +2;
            neqsign = input.find("!=", i);
        }
        //
        end = input.find("&", i);
    }
    if(eqsign != -1){
        string lh = input.substr(i,eqsign-i);
        string rh = input.substr(eqsign+2,input.size()-eqsign-2);
        if(elements.count(lh) == 0){
            elements[lh] = new Var(lh);
        }
        if(elements.count(rh) == 0){
            elements[rh] = new Var(rh);
        }
        unite(elements[lh],elements[rh]);
    }
    if(neqsign != -1){
        string lh = input.substr(i,neqsign-i);
        string rh = input.substr(neqsign+2,input.size()-neqsign-2);
        if(elements.count(lh) == 0){
            elements[lh] = new Var(lh);
        }
        if(elements.count(rh) == 0){
            elements[rh] = new Var(rh);
        }
        ineqs.push_back(make_pair(elements[lh],elements[rh]));
    }
}
set<string> reduce_ineqs(vector<pair<Var *, Var *>> ineqs){
    set<string> new_ineqs; 
    for(auto ineq: ineqs){
        string a = ineq.first->short_name;
        string b = ineq.second->short_name;
        if (a == b){
            new_ineqs = {"WRONG"};
            return new_ineqs;
        }
        if(ineq.first -> has_int && ineq.second -> has_int) continue;
        string eq;
        if (a>b){
            eq = a + "!=" + b;
        }else{
            eq = b + "!=" + a;
        }
        new_ineqs.insert(eq);
    }
    return new_ineqs;
}
int main(void) {
    vector<pair<Var*,Var*>> ineqs;
    string input;
    map <string,Var*> elements;
    bool notfirst = false;
    cin >> input;
    parse(input, elements, ineqs);
    for (auto pi : elements){
        Var* element = pi.second;
        find(pi.second);
        if (element -> short_name != element -> name){
            if(is_int(element -> short_name) && is_int(element->name) ){
                cout << "x!=x";
                return 0;
            }
            if(notfirst){
                cout << "&&";
            }
            cout << element -> name << "==" << element -> short_name; 
            notfirst = true;
        }
    }
    set<string> ineqs_to_print = reduce_ineqs(ineqs);
    if (ineqs_to_print.count("WRONG")){
        cout << "x!=x";
        return 0;
    }
    if (ineqs.size() > 0){
        set<string> ineqs_to_print = reduce_ineqs(ineqs);
        for (string const & s : ineqs_to_print){
            if(notfirst) cout << "&&";
            cout << s;
            notfirst = true;
        }
    }
    if(!notfirst) cout << "x==x";
}