#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;

int n;
int num[105][105] = {{0}};
queue<int> q;

int main(void){
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i){
		int tmp;
		int j = 0;
		while(scanf("%d", &tmp)){
			if (tmp == 0)
				break;
			num[i][++j] = tmp;
			num[tmp][0]++;
		}
	}
	for (int i = 1; i <= n; ++i){
		if (num[i][0] == 0)
			q.push(i);
	}
	while(!q.empty()){
		int emp = q.front();
		q.pop();
		int edx = 1;
		int chd = 0;
		while((chd = num[emp][edx]) != 0){
			num[chd][0]--;
			if (num[chd][0] == 0)
				q.push(chd);
			edx++;
		}
		printf("%d", emp);
		if (--n){
			printf(" ");
		}
	}
}