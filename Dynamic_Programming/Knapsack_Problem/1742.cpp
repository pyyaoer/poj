#include <stdio.h>
#include <string.h>
#include <memory.h>

int cnt;
int pr[100005];
int ar[100005];
int cr[100005];
int br[100005];

int main(void){
	int n, m;
	while(scanf("%d%d", &n, &m) != EOF){
		if (n == 0 && m == 0)
			break;
		int sum = 0;
		memset(pr, 0, sizeof(pr));
		for (int i = 0; i < n; ++i){
			scanf("%d", &ar[i]);
		}
		for (int i = 0; i < n; ++i){
			scanf("%d", &cr[i]);
			sum += ar[i] * cr[i];
		}
		pr[0] = 1;
		m = (m > sum) ? sum : m;
		for (int i = 0; i < n; ++i){
			memset(br, 0, sizeof(br));
			for (int j = ar[i]; j <= m; ++j){
				if (pr[j] == 0 && pr[j-ar[i]] > 0 && br[j-ar[i]] < cr[i]){
					pr[j] = 1;
					br[j] = br[j-ar[i]] + 1;
				}
			}
		}
		int res = 0;
		for (int i = 1; i <= m; ++i){
			res += (pr[i] > 0) ? 1 : 0;
		}
		printf("%d\n", res);
	}
}