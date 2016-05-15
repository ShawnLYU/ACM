#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#define MAXN 1000000

char input[MAXN], resultString[MAXN], *acgt = "ACGT";
int id, flag, cnt[MAXN], saving[MAXN][4], cntToBeOut;

void prepareOutput(int i, int depth = 0) {
	input[depth] = 0;
	if (depth > flag && cnt[i] > 1) {
		flag = depth;
		cntToBeOut = cnt[i];
		strcpy(resultString, input);
	}
	for (int j = 0; j < 4; j++)
		if (saving[i][j] != -1) {
			input[depth] = acgt[j];
			prepareOutput(saving[i][j], depth + 1);
		}
}
void add(int i, char *x) {
	cnt[i]++;
	if (*x) {
		int t;
		switch (*x)
		{
		case 'A':
			t = 0;
			break;
		case 'C':
			t = 1;
			break;
		case 'G':
			t = 2;
			break;
		case 'T':
			t = 3;
			break;
		default:
			break;
		}
		int &ni = saving[i][t];
		if (ni == -1) {
			ni = id;
			saving[ni][0] = -1;
			saving[ni][1] = -1;
			saving[ni][2] = -1;
			saving[ni][3] = -1;
			cnt[ni] = 0;
			id++;
		}
		add(ni, x + 1);
	}	
}

int main() {
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		flag = 0;
		cntToBeOut = 0;
		scanf("%s", input);
		int lenTmp = strlen(input);
		id = 1;
		saving[0][0] = -1;
		saving[0][1] = -1;
		saving[0][2] = -1;
		saving[0][3] = -1;
		cnt[0] = 0;
		for (int j = 0; j < lenTmp; j++)
			add(0, input + j);
		prepareOutput(0);
		if (flag <= 0) 
			printf("No repetitions found!\n");
		else
			printf("%s %d\n", resultString, cntToBeOut);
	}
}