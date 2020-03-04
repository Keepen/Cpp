// write your code here cpp
#include <iostream>
#include <math.h>
using namespace std;

//淘宝网店：素数月每天只有1块钱，其他2块
//	给出起始日期和终末日期，求挣了多少钱
//	先年，再月



const int m[13] = { 0, 62, 28, 31, 60, 31, 60, 31, 62, 60, 62, 30, 62 };
const int mon[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

bool isLeap(int year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool isSim(int num) {
	if (num == 1)
		return false;
	if (num < 4)
		return true;
	for (int i = 2; i <= pow(num, 0.5); ++i) {
		if (num % i == 0)
			return false;
	}
	return true;
}

void solu() {
	int max = 0;
	for (int i = 0; i < 13; ++i) {
		max += m[i];
	}
	int start_year, start_month, start_day;
	int end_year, end_month, end_day;
	while (cin >> start_year >> start_month >> start_day >> end_year >> end_month >> end_day) {
		int ret = 0;
		int year = end_year - start_year, day = start_day;
		for (int i = start_year + 1; i < end_year; ++i) {
			ret += max;
			if (isLeap(i))
				ret += 1;
		}
		if (year > 0) {
			for (int i = start_month + 1; i <= 12; ++i) {
				ret += m[i];
				if (isLeap(start_year) && i == 2) {
					ret += 1;
				}
			}
			for (int i = 1; i < end_month; ++i) {
				ret += m[i];
				if (isLeap(end_year) && i == 2) {
					ret += 1;
				}
			}
			int gap = mon[start_month] - start_day + 1;
			int gap2 = end_day;
			if (isSim(start_month))
				ret += gap;
			else
				ret += gap * 2;
			if (isSim(end_month))
				ret += gap2;
			else
				ret += gap2 * 2;
		}
		else {
			int months = end_month - start_month;
			for (int i = start_month + 1; i < end_month; ++i) {
				ret += m[i];
				if (isLeap(start_year))
					ret += 1;
			}
			if (months > 0) {
				int gap = mon[start_month] - start_day + 1;
				int gap2 = end_day;
				if (isSim(start_month))
					ret += gap;
				else
					ret += gap * 2;
				if (isSim(end_month))
					ret += gap2 * 2;
				else
					ret += gap2;
			}
			else {
				int gap = end_day - start_day + 1;
				if (isSim(start_month))
					ret += gap;
				else
					ret += gap * 2;
			}
		}
		cout << ret << endl;
	}
}


int main() {
	solu();
	return 0;
}

