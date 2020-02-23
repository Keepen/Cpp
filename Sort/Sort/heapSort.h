#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;




template <class T>
void adjustDown(vector<T>& v, int pos, int size) {
	int left = pos * 2 + 1, right = pos * 2 + 2;
	while (1) {
		//走到了叶子节点
		if (pos >= size || left > size - 1) {
			break;
		}
		int min = left;
		//判断有无右孩子
		if (right < size && v[right] < v[min]) {
			min = right;
		}
		swap(v[min], v[pos]);
		pos = min;
		left = pos * 2 + 1;
		right = pos * 2 + 2;
	}
}

template <class T>
void createHeap(vector<T>& v, int size) {
	for (int i = 0; i < size; ++i) {
		adjustDown(v, i, size);
	}
}


template <class T>
void heapSort(vector<T>& v, int size) {
	cout << "heapSort：" << endl;
	vector<T> newV;
	int tmp = size;
	for (int i = 0; i < size; ++i) {
		createHeap(v, tmp);
		for (auto& e : v) {
			cout << e << " ";
		}
		cout << endl;
		newV.push_back(v[0]);
		swap(v[0], v[--tmp]);
		v.pop_back();
	}
	swap(newV, v);
}
