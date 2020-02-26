#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <class T>
void bubbleSort(vector<T>& v, int size) {
	cout << "bubbleSort:" << endl;
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size - i - 1; ++j) {
			if (v[j] > v[j + 1]) {
				swap(v[j], v[j + 1]);
			}
		}
	}
}
