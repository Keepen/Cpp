#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//ѡ�����򣺱Ƚ�һ�ֺ��ٽ��н���

template <class T>
void selectSort(vector<T>& v, int size) {
	cout << "selectSort:" << endl;
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size - i; ++j) {
			int max = j;
			for (int k = 0; k < size - i; ++k) {
				if (v[max] < v[k]) {
					max = k;
				}
			}
			swap(v[max], v[size - i - 1]);
		}
	}
}
