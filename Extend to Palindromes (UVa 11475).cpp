#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;
#define MAX 100010



void KMP(char *ori) {
	int nxt[MAX];
	char rev[MAX];
	int len = strlen(ori);
	strcpy(rev, ori);
	reverse(rev, rev + len);
	nxt[1] = 0;
	int j1 = 0, j2 = 0;
	for (int i = 2; i < (len+1); i++) {
		while (j1 && rev[j1] != rev[i - 1]) {
			j1 = nxt[j1];
		}
		if (rev[j1] == rev[i - 1])
			j1++;
		nxt[i] = j1;
	}
	for (int i = 0; i < len; i++) {
		while (j2 && ori[i] != rev[j2]) {
			j2 = nxt[j2];
		}
		if (rev[j2] == ori[i])
			j2++;
	}
	printf("%s%s\n", ori, rev + j2);

}
int main() {
	char tmp[MAX];
	while (scanf("%s", tmp) != EOF) {
		KMP(tmp);
	}
	return 0;
}