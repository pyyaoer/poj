#include <stdio.h>
#include <memory.h>

int cash;
int n, cnt;
int dp[100005];
int vl[105];

int main(void){
	while(scanf("%d%d", &cash, &n)!= EOF){
		cnt = 0;
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < n; ++i){
			int num, val, j;
			scanf("%d%d", &num, &val);
			for (j = 1; j < num; j *= 2){
				num -= j;
				vl[cnt ++] = j * val;
			}
			if (num > 0)
				vl[cnt++] = num * val;
		}
		for (int i = 0; i < cnt; ++i){
			for (int j = cash; j >= vl[i]; --j){
				int tmp = dp[j-vl[i]] + vl[i];
				dp[j] = (dp[j] > tmp) ? dp[j] : tmp;
			}
		}
		printf("%d\n", dp[cash]);
	}
}