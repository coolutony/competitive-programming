#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>
using namespace std;

struct Job {
    int ind=0;
    int start=0;
    int end=0;
    bool operator < (const Job& str) const
    {
        if (start == str.start) return (end < str.end);
        return (start < str.start);
    }
};
bool available (Job const & job, vector <pair <int, int> > const & schedule){
    for (int i =0; i<schedule.size() ; i++){
        pair <int, int>  otherjob = schedule[i];
        if ( !(job.start >= otherjob.second || job.end <= otherjob.first) ) return false;
    }
    return true;
 
}
string solve (vector<Job> & jobs){
    //cout << "\nDEBUG\n";
    vector<pair <int, int> > assigned_0; // 0 Cameron 1 Jamie
    vector<pair <int, int> > assigned_1; // 0 Cameron 1 Jamie
    int assignment[1000];
    sort(jobs.begin(), jobs.end());
    /*for (int i =0; i< jobs.size();i++){
        printf("%d %d\n", jobs[i].start, jobs[i].end);
    }*/
    for (int i =0; i<jobs.size(); i++){
        Job job = jobs[i];
        if (available(job,assigned_0)){
            assigned_0.push_back(make_pair(job.start,job.end));
            assignment[job.ind] = 0;
            //printf("assigned at: %d, C\n",job->ind);
        } else if (available(job,assigned_1)){
            assigned_1.push_back(make_pair(job.start,job.end));
            assignment[job.ind] = 1;
            //printf("assigned at: %d, J\n",job->ind);
        }else{
            return "IMPOSSIBLE";
        }
    }
    string answer = "";
    for (int i =0; i<jobs.size(); i++){
        if (assignment[i] == 0) {answer.push_back('C');}
        else{ answer.push_back('J');}
    } 
    //cout << "DEBUGEND\n";
    return answer;
}
    
int main(void) {
    int t,n;
    scanf("%d", &t);
    for(int test=1; test<=t; test++){
        scanf("%d", &n);
        vector<Job> jobs;
        for (int i=0;i<n;i++){
            int start =0;
            int end =0;
            scanf("%d %d", &start, &end);
            Job job;
            job.ind = i;
            job.start = start;
            job.end = end;
            jobs.push_back(job);
        }
        printf("Case #%d: ", test);
        cout << solve(jobs) << "\n";
    }
}
