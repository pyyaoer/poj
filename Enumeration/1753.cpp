#include <stdio.h>
#include <string.h>

bool barr[6][6];
bool warr[6][6];
int min = 16;

void flip(bool arr[6][6], int i, int j){
	arr[i][j] = !arr[i][j];
	arr[i][j+1] = !arr[i][j+1];
	arr[i+1][j] = !arr[i+1][j];
	arr[i][j-1] = !arr[i][j-1];
	arr[i-1][j] = !arr[i-1][j];
}

int check(bool arr[6][6], bool ps[4], int l){
	if (l == 5)
		return ((ps[0])||(ps[1])||(ps[2])||(ps[3])) ? 0 : 1;
	int cnt = 0;
	for (int i = 0; i < 4; ++i){
		if(ps[i]){
			flip(arr, i+1,l);
			cnt++;
		}
	}
	bool pp[4];
	for(int i = 0; i < 4; ++i)
		pp[i] = !arr[i+1][l];
	int d = check(arr, pp,l+1);
	for (int i = 0; i < 4; ++i){
		if(ps[i])flip(arr, i+1,l);
	}
	return (d > 0) ? (((d/2 + cnt) * 2) | 1) : 0;
}

int main(void){
	char str[5];
	for (int i = 1; i <= 4; ++i){
		scanf("%s", str);
		for (int j = 1; j <= 4; ++j){
			barr[i][j] = (str[j-1] == 'b');
			warr[i][j] = (str[j-1] != 'b');
		}
	}
	for (int i = 0; i < 16; ++i){
		bool ps[] = {!!(i&1),!!(i&2),!!(i&4),!!(i&8)};
		if (int d = check(barr, ps, 1)){
			min = (min < d / 2) ? min : d / 2;
		}
		if (int d = check(warr, ps, 1)){
			min = (min < d / 2) ? min : d / 2;
		}
	}
	if (min == 16)
		printf("Impossible\n");
	else
		printf("%d\n", min);
}