#include <stdio.h>
#include <string.h>
#include <memory.h>

int tl = 0;
int pr[1005];

int main(void){
	int n;
	int bl = 0;
	while(scanf("%d", &n) != EOF){
		if (n == 0)
			break;
		if (!bl){
			bl = 1;
		}
		else{
			printf("\n");
		}
		while(true){
			tl = 0;
			int sm = 1;
			int fst;
			int bll = 0;
			for (int i = 0; i < n; ++i){
				scanf("%d", &fst);
				if (i == 0 && fst == 0){
					bll = -1;
					break;
				}
				if (sm > fst){
					if (tl > 0 && pr[tl-1] == fst){
						tl--;
					}
					else{
						bll = 1;
					}
				}
				else{
					while (sm <= fst){
						pr[tl] = sm;
						sm++;tl++;
					}
					tl --;
				}
			}
			if (bll == 1)
				printf("No\n");
			else if (bll == 0)
				printf("Yes\n");
			else
				break;
		}
	}
}