#include <iostream>
#include <vector>
using namespace std;

//24点游戏算法：
//穷举



double add(double a, double b) {
	return a + b;
}
double min(double a, double b) {
	return a - b;
}
double mul(double a, double b) {
	return a * b;
}
double div(double a, double b) {
	if (b == 0) {
		return -10000;
	}
	return a / b;
}

bool get24Pointabcd(double a, double b, double c, double d) {
	double(*choice[4])(double, double) = { add, min, mul, div };
	double sum = 0;
	for (int i = 0; i < 4; ++i) {
		sum = choice[i](a, b);
		if (sum - -10000 < 0.0001) {
			continue;
		}
		double tmp1 = sum;
		for (int j = 0; j < 4; ++j) {
			tmp1 = choice[j](tmp1, c);
			if (tmp1 - -10000 < 0.0001) {
				continue;
			}
			double tmp2 = tmp1;
			for (int k = 0; k < 4; ++k) {
				tmp2 = choice[k](tmp2, d);
				if (tmp2 == 24) {
					return true;
				}
				tmp2 = tmp1;
			}
			tmp1 = sum;
		}
	}
	return false;
}



bool get24Pointab_cd(double a, double b, double c, double d) {
	double(*choice[4])(double, double) = { add, min, mul, div };
	double sum = 0;
	double sum2 = 0;
	for (int i = 0; i < 4; ++i) {
		sum = choice[i](a, b);
		if (sum - -10000 < 0.0001) {
			continue;
		}
		for (int j = 0; j < 4; ++j) {
			sum2 = choice[j](c, d);
			if (sum2 - -10000 < 0.0001) {
				continue;
			}
			for (int k = 0; k < 4; ++k) {
				if ((choice[k](sum, sum2)) == 24) {
					return true;
				}
			}
		}
	}
	return false;
}



bool get24Pointa_bc_d(double a, double b, double c, double d) {
	double(*choice[4])(double, double) = { add, min, mul, div };
	double sum = 0;
	double sum2 = 0;
	for (int i = 0; i < 4; ++i) {
		sum2 = choice[i](b, c);
		if (sum2 - -10000 < 0.0001) {
			continue;
		}
		for (int j = 0; j < 4; ++j) {
			sum = choice[j](a, sum2);
			if (sum - -10000 < 0.0001) {
				continue;
			}
			double tmp1 = sum;
			for (int k = 0; k < 4; ++k) {
				tmp1 = choice[k](tmp1, d);
				if (tmp1 == 24) {
					return true;
				}
				tmp1 = sum;
			}
		}
	}
	return false;
}


bool get24Pointa_bcd(double a, double b, double c, double d) {
	double(*choice[4])(double, double) = { add, min, mul, div };
	double sum = 0;
	double sum2 = 0;
	for (int i = 0; i < 4; ++i) {
		sum2 = choice[i](b, c);
		if (sum2 - -10000 < 0.0001) {
			continue;
		}
		double tmp = sum2;
		for (int j = 0; j < 4; ++j) {
			tmp = choice[j](tmp, d);
			if (tmp - -10000 < 0.0001) {
				continue;
			}
			for (int k = 0; k < 4; ++k) {
				sum = choice[k](a, tmp);
				if (sum == 24) {
					return true;
				}
				sum = tmp;
			}
			tmp = sum2;
		}
	}
	return false;
}


void test(double a, double b, double c, double d) {
	vector<double> num;
	num.resize(4);
		num[0] = a; num[1] = b; num[2] = c; num[3] = d;
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				for (int k = 0; k < 4; ++k) {
					for (int m = 0; m < 4; ++m) {
						if (i == j || i == k || i == m || j == k || j == m || k == m) {
							continue;
						}
						if (get24Pointabcd(num[i], num[j], num[k], num[m]) ||
							get24Pointab_cd(num[i], num[j], num[k], num[m]) ||
							get24Pointa_bc_d(num[i], num[j], num[k], num[m]) ||
							get24Pointa_bcd(num[i], num[j], num[k], num[m])
							) {
							cout << "true" << endl;
							return;
						}
					}
				}
			}
		}
		cout << "false" << endl;
		return;
}


int main() {
	double a, b, c, d;
	while (cin >> a >> b >> c >> d) {
		test(a, b, c, d);
	}
	return 0;
}
