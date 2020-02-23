#pragma once
#include <iostream>
#include <vector>
using namespace std;

template <class T>
void merge(vector<T>& v, int left, int mid, int right) {
	vector<T> l(v.begin() + left, v.begin() + mid);
	vector<T> r(v.begin() + mid, v.begin() + right + 1);
	int i = 0, j = 0, k = left;
	while (i < l.size() && j < r.size()) {
		if (l[i] < r[j]) {
			v[k++] = l[i++];
		}
		else {
			v[k++] = r[j++];
		}
	}
	if (i == l.size()) {
		while (j < r.size()) {
			v[k++] = r[j++];
		}
	}
	if (j == r.size()) {
		while (i < l.size()) {
			v[k++] = l[i++];
		}
	}
}


template <class T>
void _merge_Sort(vector<T>& v, int left, int right) {
	if (left >= right) {
		return;
	}
	else {
		int mid = (left + right) / 2;
		_merge_Sort(v, left, mid);
		_merge_Sort(v, mid + 1, right);
		merge(v, left, mid + 1, right);
	}
}


template <class T>
void mergeSort(vector<T>& v, int size) {
	cout << "merge_Sort£º" << endl;
	_merge_Sort(v, 0, size - 1);
}
