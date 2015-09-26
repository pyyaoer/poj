#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int m, n;
int stu[30005];

int f_p(int a){
	if(stu[a] != a){
		stu[a] = f_p(stu[a]);
	}
	return stu[a];
}

void u_s(int a, int b){
	int pa = f_p(a);
	int pb = f_p(b);
	if (pa < pb){
		stu[pb] = pa;
	}
	else{
		stu[pa] = pb;
	}
}

int main(void){
	while(scanf("%d %d", &n, &m) != EOF){
		if (n == 0 && m == 0)
			return 0;
		for (int i = 0; i <= n; ++i){
			stu[i] = i;
		}
		for (int i = 0; i < m; i ++) {
			int cnt = 0;
			int tmp = 0;
			scanf("%d", &cnt);
			scanf("%d", &tmp);
			if (cnt == 1){
				continue;
			}
			for (int j = 0; j < cnt - 1; ++j) {
				int tt = tmp;
				scanf("%d", &tmp);
				u_s(tmp, tt);
			}
		}
		int ss = 0;
		for (int i = 0; i < n; ++i) {
			stu[i] = f_p(i);
			if (stu[i] == stu[0])
				ss ++;
		}
		printf("%d\n", ss);
	}
	return 0;
}