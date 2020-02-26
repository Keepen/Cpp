#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//合并两个有序数组
//	1.分割成两个小数组
//	2.进行合并


template <class T>
void merge(vector<T>& v, int left, int mid, int right) {
	vector<T> l(v.begin() + left, v.begin() + mid + 1);
	vector<T> r(v.begin() + mid + 1, v.begin() + right + 1);
	int i = 0, j = 0, k = left;
	while (i < l.size() && j < r.size()) {
		if (l[i] < r[j]) {
			v[k++] = l[i++];
		}
		else {
			v[k++] = r[j++];
		}
	}
	if (i >= l.size()) {
		while (j < r.size()) {
			v[k++] = r[j++];
		}
	}
	if (j >= r.size()) {
		while (i < l.size()) {
			v[k++] = l[i++];
		}
	}
}

//递归
template <class T>
void _merge_sort(vector<T>& v, int left, int right) {
	if (left >= right) {
		return;
	}
	else {
		int mid = (left + right) / 2;
		_merge_sort(v, left, mid);
		_merge_sort(v, mid + 1, right);
		merge(v, left, mid, right);
	}
}

template <class T>
void mergeSort(vector<T>& v, int size) {
	cout << "mergeSort : " << endl;
	//_merge_sort(v, 0, size - 1);


	//非递归版本
	if (size < 2) {
		return;
	}
	int sz = 1;	//每次归并的组内的数字步幅

	while (sz <= size) {
		int begin = 0, mid = 0, end = 0;
		while (end < size - 1) {
			mid = begin + sz - 1;
			end = mid + sz;
			if (end >= size) {
				end = size - 1;
			}
			if (mid >= size) {
				mid = (begin + end) / 2;
			}
			merge(v, begin, mid, end);
			begin = end + 1;
		}
		sz *= 2;
	}

}
