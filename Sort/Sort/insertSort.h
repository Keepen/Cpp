#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//��������
template <class T>
void insertSort(vector<T>& v, int size) {
	cout << "insertSort��" << endl;
	for (int i = 1; i < size; ++i) {
		for (int j = i - 1; j >= 0; --j) {			
			if (v[j + 1] < v[j]) {
				swap(v[j + 1], v[j]);
			}
		}
	}
}


