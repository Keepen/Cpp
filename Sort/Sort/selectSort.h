#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <class T>
void selectSort(vector<T>& v, int size) {
	cout << "selectSort£º" << endl;
	int i = 0, j = 0;
	for (i = 0; i < size; ++i) {
		for (j = 0; j < size - i; j++) {
			int max = v[j];
			int m = j;
			for (int k = 0; k < size - i; ++k) {
				if (max < v[k]) {
					max = v[k];
					m = k;
				}
			}
			swap(v[m], v[size - i - 1]);
		}
	}
}

