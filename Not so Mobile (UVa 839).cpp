#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
using namespace std;

int check(int wl, int dl, int wr, int dr) {
	int l = 0, r = 0;
	if (wl != 0 && wr != 0) {
		if (wl*dl == wr*dr) {
			return wl + wr;
		}
		else {
			return 0;
		}
	}
	if (wl == 0) {
		int _wl = 0, _dl = 0, _wr = 0, _dr = 0;
		scanf("%d %d %d %d", &_wl, &_dl, &_wr, &_dr);
		l = check(_wl, _dl, _wr, _dr);
	}
	else {
		l = wl;
	}
	if (wr == 0) {
		int _wl = 0, _dl = 0, _wr = 0, _dr = 0;
		scanf("%d %d %d %d", &_wl, &_dl, &_wr, &_dr);
		r = check(_wl, _dl, _wr, _dr);
	}
	else {
		r = wr;
	}
	if (l != 0 && r != 0 && l*dl == r*dr)
		return l + r;
	else
		return 0;

}


int main() {
	bool isFirstTime = true;
	int tot;
	string tmp;
	cin >> tot;
	getline(cin, tmp);
	getline(cin, tmp);
	for (int i = 0; i<tot; i++) {
		string term;
		string input;
		int wl = 0, dl = 0, wr = 0, dr = 0;
		scanf("%d %d %d %d", &wl, &dl, &wr, &dr);
		if (check(wl, dl, wr, dr) == 0) {
			if(isFirstTime){
				isFirstTime = false;
				cout << "NO" << endl;	
			}else{
				cout << endl<< "NO" << endl;
			}
			
		}
		else {
			if(isFirstTime){
				isFirstTime = false;
				cout << "YES" << endl;	
			}else{
				cout << endl<< "YES" << endl;
			}
		}
	}
	return 0;
}