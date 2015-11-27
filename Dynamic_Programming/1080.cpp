#include <iostream>
#include <stdio.h>
using namespace std;

int arr[105][105];
int c1[105];
int c2[105];
int mp[5][5] = {
	{5, -1, -2, -1, -3},
	{-1, 5, -3, -2, -4},
	{-2, -3, 5, -2, -2},
	{-1, -2, -2, 5, -1},
	{-3, -4, -2, -1, 0}
};

int main(void){
	int t, i, j, k, r;
	cin >> t;
	int swt[26];
	swt[0] = 0;
	swt['C'-'A'] = 1;
	swt['G'-'A'] = 2;
	swt['T'-'A'] = 3;
	while(t--){
		int l1, l2;
		char ch;
		cin >> l1;
		for (i = 1; i <= l1; i ++){
			cin >> ch;
			c1[i] = swt[ch - 'A'];
			arr[i][0] = arr[i-1][0] + mp[c1[i]][4];
		}
		cin >> l2;
		int aa[4] = {0};
		for (i = 1; i <= l2; i ++){
			cin >> ch;
			c2[i] = swt[ch - 'A'];
			arr[0][i] = arr[0][i-1] + mp[4][c2[i]];
		}
		for (i = 1; i <= l1; i ++){
			for (j = 1; j <= l2; j ++){
				arr[i][j] = arr[i-1][j] + mp[c1[i]][4];
				if (arr[i][j] < arr[i][j-1] + mp[4][c2[j]]){
					arr[i][j] = arr[i][j-1] + mp[4][c2[j]];
				}
				if (arr[i][j] < arr[i-1][j-1] + mp[c1[i]][c2[j]]){
					arr[i][j] = arr[i-1][j-1] + mp[c1[i]][c2[j]];
				}
			}
		}
		printf("%d\n", arr[l1][l2]);
	}
}