#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <iostream>
#include <sstream>
using namespace std;

set<string> myDict;
int main(){
	string line, word;
	while(cin>>line){
		for(int i=0;i<line.length();i++){
			if(isalpha(line[i]))
				line[i] = tolower(line[i]);
			else
				line[i] = ' ';	
		}
		stringstream ss(line);
		while(ss>>word)
			myDict.insert(word);
		
	}
		
	for (set<string>::const_iterator iter = myDict.begin(); iter != myDict.end(); ++iter) {
		cout << *iter <<endl;
	}

}