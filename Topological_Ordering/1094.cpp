#include <iostream>
#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;

#define MAXN 30

int n, m, v;
int to[MAXN];
int vis[MAXN];
int from[MAXN];
int tag[MAXN][MAXN];
int arr[MAXN][MAXN];

char rst[MAXN];

int topo(){
	memset(rst, 0, sizeof(rst));
	queue<int> q;
	int tmpto[MAXN];
	memcpy(tmpto, to, sizeof(to));
	for (int i = 0; i < n; i ++){
		if (vis[i] && !to[i])
			q.push(i);
	}
	int len = 0;
	int badbad = q.empty() ? -1 : 1;
	while(!q.empty()){
		if (q.size() != 1)
			badbad = 0;
		int p = q.front();q.pop();
		rst[len++] = (char)('A' + p);
		for (int i = 0; i < from[p]; i++){
			int toi = arr[p][i];
			if (tmpto[toi] == 0){
				return -1;
			}
			tmpto[toi]--;
			if (tmpto[toi] == 0)
				q.push(toi);
		}
	}
	if (len != v)
		return -1;
	return (v == n) ? badbad : 0;
}

int solve(){
	char buf[10];
	scanf("%d%d", &n, &m);
	if (n == 0 && m == 0)
		return 0;
	memset(to, 0, sizeof(to));
	memset(vis, 0, sizeof(vis));
	memset(from, 0, sizeof(from));
	for (int i = 0; i < MAXN; i ++){
		memset(arr[i], 0, sizeof(arr[i]));
		memset(tag[i], 0, sizeof(tag[i]));
	}
	int res = 0;
	int lst = 0;
	v = 0;
	for (int i = 1; i <= m; i ++){
		scanf("%s", buf);
		if (!res){
			int x = buf[0] - 'A';
			int y = buf[2] - 'A';
			if (!vis[x]){
				vis[x] = 1;v++;
			}
			if (!vis[y]){
				vis[y] = 1;v++;
			}
			if (!tag[x][y]){
				tag[x][y] = 1;
				arr[x][from[x]++] = y;
				to[y] ++;
			}
			res = topo();
			lst = i;
		}
	}
	switch(res){
		case 0:
			printf("Sorted sequence cannot be determined.\n");
			break;
		case 1:
			printf("Sorted sequence determined after %d relations: %s.\n", lst, rst);
			break;
		case -1:
			printf("Inconsistency found after %d relations.\n", lst);
	}
}

int main(void){
	while(solve()){}
}
