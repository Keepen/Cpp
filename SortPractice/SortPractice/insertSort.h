#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//插入排序：选择数字插入有序区间


template <class T>
void insertSort(vector<T>& v, int size) {
	cout << "insertSort :" << endl;
	for (int i = 1; i < size; ++i) {
		for (int j = i; j < size; ++j) {
			int k = j;
			while (k >= 1 && v[k] < v[k - 1]) {
				swap(v[k], v[k - 1]);
				--k;
			}
		}
	}
}
