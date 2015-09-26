#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int r,c;
int cnt = 0;
int arr[105][105];
int flg[105][105];
int vst[105][105];

int solve(int i, int j){
    if (i < 0 || i >= r || j < 0 || j >= c)
        return -1;
    if (vst[i][j] != 0)
        return flg[i][j];
    int mx = 0, tmp = 0;
    if (arr[i][j] > arr[i][j-1]){
        tmp = solve(i, j-1) + 1;
        mx = (tmp > mx) ? tmp : mx;
    }
    if (arr[i][j] > arr[i][j+1]){
        tmp = solve(i, j+1) + 1;
        mx = (tmp > mx) ? tmp : mx;
    }
    if (arr[i][j] > arr[i-1][j]){
        tmp = solve(i-1, j) + 1;
        mx = (tmp > mx) ? tmp : mx;
    }
    if (arr[i][j] > arr[i+1][j]){
        tmp = solve(i+1, j) + 1;
        mx = (tmp > mx) ? tmp : mx;
    }
    vst[i][j] = 1;
    flg[i][j] = mx;
    cnt = (cnt > mx) ? cnt : mx;
    return mx;
}

int main(void){
    scanf("%d%d", &r, &c);
    for (int i = 0; i < r; ++i){
        for (int j = 0; j < c; ++j){
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 0; i < r; ++i){
        for (int j = 0; j < c; ++j){
            if (flg[i][j] == 0){
                solve(i, j);
            }
        }
    }
    printf("%d\n", cnt+1);
    return 0;
}