#include <iostream>
#include <string.h>
#include <stdio.h>
#include <memory.h>
using namespace std;

int main(void){
	int t;
	cin >> t;
	while(t--){
		long long k;
		long long i = 0;
		long long d = 1;
		int dd = 0;
		int kk = 1;
		cin >> k;
		while (k > 0){
			i++;
			if (i == d * 10){
				d *= 10;
				kk ++;
			}
			dd += kk;
			k -= dd;
		}
		k += dd;
		i = 0;dd = 1;kk = 1;d=1;
		while (k > 0){
			i++;
			if (i == d * 10){
				d *= 10;
				dd ++;
			}
			k -= dd;
		}
		char str[15] = {0};
		sprintf(str, "%lld", i);
		cout << str[k+dd-1] << endl;
	}
}