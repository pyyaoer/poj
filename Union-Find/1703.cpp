#include <stdio.h>
#include <memory.h>

int m, n;
int par[100005];
int var[100005];

int f_p(int i){
	if (par[i] == i)
		return i;
	int pr = par[i];
	par[i] = f_p(pr);
	var[i] = (var[i] + var[pr]) % 2;
	return par[i];
}

int c_k(int a, int b){
	int root_a = f_p(a);
	int root_b = f_p(b);
	if (root_a != root_b)
		return 0;
	return (var[a] == var[b]) ? 1 : 2;
}

void u_s(int a, int b, int v){
	int root_a = f_p(a);
	int root_b = f_p(b);
	if (root_a == root_b)
		return;
	if (root_a < root_b){
		par[root_b] = root_a;
		var[root_b] = (var[a] + var[b] + v) % 2;
	}
	else{
		par[root_a] = root_b;
		var[root_a] = (var[a] + var[b] + v) % 2;
	}
}

int main(void){
	int t;
	scanf("%d", &t);
	const char* ans[3] = {"Not sure yet.", "In the same gang.", "In different gangs."};
	while(t--){
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i){
			par[i] = i;
			var[i] = 0;
		}
		for (int i = 0; i < m; ++i){
			char ch[3];
			int a, b;
			scanf("%s%d%d", ch, &a, &b);
			if (ch[0] == 'A'){
				printf("%s\n", ans[c_k(a, b)]);
			}
			else{
				u_s(a, b, 1);
			}
		}
	}
}