#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

char a[120];
char b[120];
int num1[30];
int num2[30];

int main(){
	int i;
	cin.getline(a,110);
	cin.getline(b,110);
	for(i = 0; a[i] != '\0'; i ++)
		num1[a[i]-'A']++;
	for(i = 0; b[i] != '\0'; i ++)
		num2[b[i]-'A']++;
	sort(num1, num1 + 26);
	sort(num2, num2 + 26);
	int fl = 0;
	for(i = 0; i < 26; i++){
		if(num1[i] != num2[i]){
			fl = 1;
		}
	}
	if(fl)
		cout << "NO" << endl;
	else
		cout << "YES" << endl;
	return 0;
}