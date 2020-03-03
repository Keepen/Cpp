#include <iostream>
#include <string>
using namespace std;
const int gap = 366 + 365 * 3;
//const int a[4] = { 366,365,365,365 };
const int week[7] = { 6,7,1,2,3,4,5 };

//�ж��Ƿ�������
bool isLeap(int year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

//2000-01-01 Sat
//01�µĽ��� -- ����·�½� -- ����������һ
int Jan(int day) {
	int tmp = day;
	int count = 1;
	int ret = 2;
	while (week[tmp] != 1) {
		tmp = (tmp + 1) % 7;
		++count;
	}
	while (ret--) {
		count += 7;
	}
	return count;
}

//02�µĽ��� -- ����������һ
int Feb(int day) {
	int tmp = day;
	int count = 1;
	int ret = 2;
	while (week[tmp] != 1) {
		tmp = (tmp + 1) % 7;
		++count;
	}
	while (ret--) {
		count += 7;
	}
	return count;
}

//05�µ����һ������һ
int May(int day) {
	int tmp = day;
	int count = 1;
	while (week[tmp] != 1) {
		tmp = (tmp + 1) % 7;
		++count;
	}
	while (count + 7 <= 31) {
		count += 7;
	}
	return count;
}

//09�µĵ�һ������һ
int Sept(int day) {
	int tmp = day;
	int count = 1;
	while (week[tmp] != 1) {
		tmp = (tmp + 1) % 7;
		++count;
	}
	return count;
}

//11�µĵ��ĸ�������
int Nov(int day) {
	int tmp = day;
	int count = 1;
	int ret = 3;
	//��������������
	while (week[tmp] != 4) {
		tmp = (tmp + 1) % 7;
		++count;
	}
	while (ret--) {
		count += 7;
	}
	return count;
}

void solu() {
	int year;
	while (cin >> year) {
		int tmp_year = 2000;
		int day = 0;	//��ʾ����01-01��Sat��ĵڼ���;
		while (tmp_year != year) {
			if (isLeap(tmp_year)) {
				day += 366;
			}
			else {
				day += 365;
			}
			tmp_year++;
		}
		day %= 7;
		cout << year << "-01-01" << endl;
		cout << year << "-01-" << Jan(day) << endl;
		day = (day + 31) % 7;
		cout << year << "-02-" << Feb(day) << endl;
		if (isLeap(year)) {
			day = (day + 29) % 7;
		}
		else {
			day = (day + 28) % 7;
		}
		day = (day + 31 + 30) % 7;
		cout << year << "-05-" << May(day) << endl;
		cout << year << "-07-04" << endl;
		day = (day + 31 + 30 + 31 + 31) % 7;
		cout << year << "-09-";
		if (Sept(day) < 10) {
			cout << "0";
		}
		cout << Sept(day) << endl;
		day = (day + 30 + 31) % 7;
		cout << year << "-11-" << Nov(day) << endl;
		day = (day + 30) % 7;
		cout << year << "-12-25" << endl << endl;

	}
}

int main() {
	solu();
	return 0;
}