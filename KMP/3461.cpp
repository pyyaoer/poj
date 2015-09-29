#include <stdio.h>
#include <string.h>
#include <memory.h>

int plen, olen;
int next[10005];
char pat[10005];
char ori[1000005];

void gen_next(){
	next[0] = next[1] = 0;
	for (int i = 1; i < plen; ++i){
		int p = next[i];
		while(p && pat[i] != pat[p])
			p = next[p];
		next[i+1] = (pat[i] == pat[p]) ? p + 1: 0;
	}
}

int cnt_pat(){
	int p = 0;
	int cnt = 0;
	for (int i = 0; i < olen; ++i){
		while(p && ori[i] != pat[p])
			p = next[p];
		if (ori[i] == pat[p])
			p++;
		if (p == plen)
			cnt ++;
	}
	return cnt;
}

int main(void){
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%s", pat);
		plen = strlen(pat);
		scanf("%s", ori);
		olen = strlen(ori);
		gen_next();
		printf("%d\n", cnt_pat());
	}
}