#include <iostream>
#include <stdio.h>
using namespace std;

int b, l, n;
double res[1005];
int w[1005];
int s[1005];

int main(void){
	while(1){
		int i, j;
		scanf("%d %d %d", &b, &l, &n);
		l *= 60;
		if (b == 0){
			break;
		}
		int current_weight = 0;
		int current_sp = 0;
		res[0] = 0;
		w[0] = s[0] = 0;
		for(i = 1; i <= n; i ++){
			scanf("%d %d", &w[i], &s[i]);
			if (i == 1){
				res[i] = (l + 0.0) / s[i];
				current_weight = w[i];
				current_sp = s[i];
				continue;
			}
			if (current_weight + w[i] <= b && s[i] >= current_sp){
				current_weight += w[i];
				res[i] = res[i-1];
			}
			else{
				res[i] = res[i-1] + (l + 0.0) / s[i];
				current_weight = w[i];
				int min_weight = w[i];
				current_sp = s[i];
				int min_sp = s[i];
				for (j = i-1; j >= 0; j--){
					if (res[i] > (res[j] + (l + 0.0) / min_sp)){
						res[i] = res[j] + (l + 0.0) / min_sp;
						current_sp = min_sp;
						current_weight = min_weight;
					}
					if (min_weight + w[j] > b)
						break;
					min_weight += w[j];
					min_sp = (min_sp <= s[j]) ? min_sp : s[j];
				}
			}
		}
		printf("%.1lf\n", res[n]);
	}
}