#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N=100001;


int main(void) {
    int t,n;
    n = 0;
    int mat[100][100];
    scanf("%d", &t);
    for (int num  =1 ; num<=t; num++){
        scanf("%d", &n);
        for (int row=0; row < n; row ++){
            for (int col=0; col <n; col ++){
                int temp = -1;
                scanf("%d", &temp);
                mat[row][col] =temp;
            }
        }
        int trace = 0;
        int rowcnt = 0;
        int colcnt = 0;
        for (int i =0; i<n; i++){
            trace += mat[i][i];
            for (int j = 0; j<n; j++){
                int row_hold = mat[i][j];
                bool broke = false;
                for (int k =0; k< j; k++){
                    if (row_hold == mat[i][k]){
                        rowcnt ++;
                        broke = true;
                        break;
                    }
                }
                if(broke) break;
            } 
            for (int j = 0; j<n; j++){
                int col_hold = mat[j][i];
                bool broke = false;
                for (int k =0; k< j; k++){
                    if (col_hold == mat[k][i]){
                        colcnt ++;
                        broke = true;
                        break;
                    }
                }
                if(broke) break;
            }
        }
        printf("Case #%d: %d %d %d\n", num, trace, rowcnt, colcnt);
    }
}
