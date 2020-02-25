#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//向下调整
template <class T>
void adjustDown(vector<T>& v, int pos, int size) {
	int left = pos * 2 + 1, right = pos * 2 + 2;
	while (1) {
		//走到了叶子节点
		if (pos >= size || left >= size) {
			break;
		}
		//满足性质，退出
		if (right >= size && v[left] >= v[pos]) {
			return;
		}
		if (right < size && v[pos] <= v[left] && v[pos] <= v[right]) {
			return;
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


//向上调整
template <class T>
void adjustUp(vector<T>& v, int pos, int size) {
	int parent = (pos - 1) / 2;
	int left = parent * 2 + 1;
	int right = parent * 2 + 2;
	int count = 0;
	while (1) {
		if (parent == 0) {
			++count;
			if (count == 2) {
				return;
			}
		}
		int min = parent;
		if (left < size && v[left] < v[min]) {
			min = left;
		}
		if (right < size && v[left] >v[right]) {
			min = right;
		}
		//满足性质
		if (min == parent) {
			return;
		}
		swap(v[min], v[parent]);
		parent = (parent - 1) / 2;
		left = parent * 2 + 1;
		right = parent * 2 + 2;
	}

}

template <class T>
void showv(vector<T>& v) {
	for (auto& e : v) {
		cout << e << " ";
	}
	cout << endl;
}

template <class T>
void createHeap(vector<T>& v, int size) {
	for (int i = size - 1; i >= 0; --i) {
		adjustUp(v, i, size);
		//showv(v);
	}
}


template <class T>
void heapSort(vector<T>& v, int size) {
	cout << "heapSort：" << endl;
	vector<T> newV;
	int tmp = size;
	for (int i = 0; i < size; ++i) {
		createHeap(v, tmp);
		newV.push_back(v[0]);
		swap(v[0], v[--tmp]);
		v.pop_back();
	}
	swap(newV, v);
}
