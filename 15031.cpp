#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N=5000;
int n,m;
struct Building {
	int num, capacity , rent, chosen;
};
struct Department {
	int num, students, building;
};
bool compare_rent(Building a, Building b){
	return (a.rent < b.rent);
}
bool compare_students_reverse(Department a, Department b){
	return (a.students > b.students);
}
int main(void) {
	vector<Building> vb;
	vector<Department> vd;
	scanf("%d%d", &n, &m);
	vector<Building> vchoose;
	int ans[N];
	int possible = 1;
	for (int i=0; i<n; i++){
		Department temp = Department();
		temp.num = i+1;
		scanf("%d", &(temp.students));
		vd.push_back(temp);
	}
	for (int i=0; i<m; i++){
		Building temp = Building();
		temp.num = i+1;
		scanf("%d", &(temp.capacity));
		vb.push_back(temp);
	}
	for (int i=0; i<m; i++){
		int temp;
		scanf("%d", &(temp));
		vb[i].rent = temp;
	}
	sort(vb.begin(),vb.end(), compare_rent);
	sort(vd.begin(),vd.end(), compare_students_reverse);
	for (auto d : vd){
		for (int i = 0;i<m;i++){
			if (vb[i].capacity >= d.students && !(vb[i].chosen)){
				vb[i].chosen = 1;
				ans[d.num-1] = vb[i].num;
				vchoose.push_back(vb[i]);
				break;
			}
			if (i==m-1){
				possible = 0;
			}
		}		
	}
	if (possible){	
		for (int i =0;i<n;i++){
			printf("%d ", ans[i]);
		}
	}else{
		printf("impossible");
	}
}
