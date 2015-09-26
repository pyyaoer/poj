#include <stdio.h>
#include <string.h>

char str[1000005];
int next[1000005];

int gen_next(){
	int len = strlen(str);
	next[0] = 0;
	next[1] = 0;
	for (int i = 1; i < len; ++i){
		int p = next[i];
		while(p && str[i] != str[p])
			p = next[p];
		next[i+1] = (str[i] == str[p]) ? (p+1) : 0;
	}
	if (len % (len - next[len]) == 0)
		return len / (len - next[len]);
	else
		return 1;
}

int main(void){
	while(scanf("%s", str) != EOF){
		if (strcmp(str, ".") == 0){
			break;
		}
		printf("%d\n", gen_next());
		memset(str, sizeof(str), 0);
	}
}