#include <iostream>
#include <string>
using namespace std;

class Person {
public:
	Person(string n, int d, int m, int y);
	bool isOlderThan(Person *person);
	string getName();
	int getDay();
	int getMonth();
	int getYear();
	void toString();
private:
	string name;
	int day, month, year;
};
Person::Person(string n, int d, int m, int y) {
	name = n;
	day = d;
	month = m;
	year = y;
}
string Person::getName() {
	return name;
}
int Person::getDay() {
	return day;
}
int Person::getMonth() {
	return month;
}
int Person::getYear() {
	return year;
}
bool Person::isOlderThan(Person *person) {

	if (getYear()<person->getYear())
		return true;
	else if (getYear() == person->getYear())
		if (getMonth()<person->getMonth())
			return true;
		else if (getMonth() == person->getMonth())
			if (getDay()<person->getDay())
				return true;
			else
				return false;
		else
			return false;
	else
		return false;
}
void Person::toString() {
	cout << name << endl;
}

int main() {
	int tot = 0;
	cin >> tot;
	string name, day, month, year;
	cin >> name >> day >> month >> year;
	string old = name, young = old;
	int doo = stoi(day), mo = stoi(month), yo = stoi(year);
	int dy = doo, my = mo, yy = yo;
	Person *oldPerson = new Person(name, doo, mo, yo);
	Person *youngPerson = new Person(name, dy, my, yy);
	for (int i = 1; i<tot; i++) {
		string name_tmp, day_tmp, month_tmp, year_tmp;
		cin >> name_tmp >> day_tmp >> month_tmp >> year_tmp;
		int d = stoi(day_tmp), m = stoi(month_tmp), y = stoi(year_tmp);
		Person *tmpPerson = new Person(name_tmp, d, m, y);
		if (tmpPerson->isOlderThan(oldPerson))
			oldPerson = tmpPerson;
		else if (!tmpPerson->isOlderThan(youngPerson))
			youngPerson = tmpPerson;
	}
	youngPerson->toString();
	oldPerson->toString();


	return 0;
}