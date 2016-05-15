#include <stdio.h>
#include <math.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <map>
using namespace std;
#define N 1000000
#define width 6
int len, product[N] = { 0 };

void multiply(int a[], int n){
	int carry = 0, i;
	for (i = 0; i < len; i++){
		int tmp = a[i] * n + carry;
		a[i] = tmp % 10;
		carry = tmp / 10;
	}
	while (carry){
		a[i++] = carry % 10;
		carry /= 10;
	}
	len = i;
}
int main(){
	int n;
	char input[width];
	while (scanf("%s %d", input, &n) != EOF){
		int l = 0, number = 0;
		for (int i = 0; i < width; i++){
			if (input[i] == '.')
				l = (width - i - 1) * n;
			else
				number = number * 10 + input[i] - 48;
		}

		product[0] = 1;
		len = 1;

		for (int i = 0; i < n; i++)
			multiply(product, number);

		if (len <= l){
			cout << '.';
			for (int i = 0; i < l - len; i++)
				cout << '0';
			int j = 0;
			while (!product[j]) 
				j++;
			
			for (int i = len - 1; i >= j; i--)
				cout << product[i];
		}
		else{
			int j = 0;
			while (!product[j] && j < l)
				j++;
			for (int i = len - 1; i >= j; i--){
				if (i + 1 == l)
					cout << '.';
				cout << product[i];
			}
		}
		cout << endl;
	}


	return 0;
}