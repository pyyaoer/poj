#include <iostream>
#include <stack>
#include <vector>
#include <string.h>
using namespace std;

#define MAXN 50005

vector<int> G[MAXN];
stack<int> S;
int pre[MAXN];
int most_pre[MAXN];
int sccno[MAXN];
int visit[MAXN];
int clk = 0;
int scc = 0;
int lst = 0;
int cnt = 0;
int res = 0;
int n, m;

int ppcow[MAXN];

void dfs(int u){
	S.push(u);
	pre[u] = most_pre[u] = ++clk;

	for (int i = 0; i < G[u].size(); i ++){
		int v = G[u][i];
		if (!pre[v]){
			dfs(v);
			most_pre[u] = most_pre[u] < most_pre[v] ? most_pre[u] : most_pre[v];
		}
		else if (!sccno[v]){
			most_pre[u] = most_pre[u] < pre[v] ? most_pre[u] : pre[v];
		}
	}

	if (most_pre[u] == pre[u]){
		++scc;
		res = 0;
		for (;;){
			int x = S.top();
			S.pop();
			sccno[x] = scc;
			res ++;
			if (x == u)
				break;
		}
	}

	lst = u;
}

void tarjan(){
	memset(pre, 0, sizeof(pre));
	memset(most_pre, 0, sizeof(most_pre));
	memset(sccno, 0, sizeof(sccno));
	clk = scc = 0;
	for (int i = 0; i < n; i++){
		if (!pre[i]){
			dfs(i);
		}
	}
}

void dfs2(int u){
	visit[u] = 1;
	cnt ++;
	for (int i = 0; i < G[u].size(); i ++){
		int v = G[u][i];
		if (!visit[v])
			dfs2(v);
	}
}

void input(){
	int ta, tb;
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		cin >> ta >> tb;
		G[tb-1].push_back(ta-1);
	}
}

void solve(){
	tarjan();
	cnt = 0;
	memset(visit, 0, sizeof(visit));
	dfs2(lst);
	res = (cnt == n) ? res : 0;
}

int main(void){
	input();
	solve();
	cout << res << endl;
}
