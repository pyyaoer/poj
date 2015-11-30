#include <iostream>
using namespace std;

int n, i;
int num[105];
int res[105][105];

int cnt(int s, int t){
	int k;
	if (t - s >= 2 && !res[s][t]){
		for (k = s + 1; k <= t - 1; k ++){
			int tmp = cnt(s, k) + cnt(k, t) + num[s] * num[k] * num[t];
			if (res[s][t] == 0 || res[s][t] > tmp)
				res[s][t] = tmp;
		}
	}
	return res[s][t];
}

int main(void){
	cin >> n;
	for (i = 1; i <= n; i ++)
		cin >> num[i];
	cnt(1, n);
	cout << res[1][n] << endl;
}