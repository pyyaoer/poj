#include <iostream>
#include <string.h>
#include <memory.h>
using namespace std;

int main(void){
	char str[260];
	while(cin.getline(str, 256)){
		if (strcmp(str, "#") == 0)
			break;
		int len = strlen(str);
		int cnt = 0;
		for (int i = 0; i < len; ++i){
			if (str[i] != ' ')
				cnt += (str[i] - 'A' + 1) * (i+1);
		}
		cout << cnt << endl;
	}
}