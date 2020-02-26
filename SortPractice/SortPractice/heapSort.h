#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Ĭ�������� -- �������
//�ѵ����ϵ���
template <class T>
void shiftUp(vector<T>& v, int pos, int size) {
	int parent = (pos - 1) / 2;
	int left = parent * 2 + 1;
	int right = parent * 2 + 2;
	int count = 0;
	while (1) {
		//�����ڵ㣬��������
		if (parent < 0) {
			if (++count > 1) {
				return;
			}
		}
		int max = parent;
		if (left <size && v[left] > v[parent]) {
			max = left;
		}
		if (right < size &&v[right] > v[max]) {
			max = right;
		}
		//���������ˣ�ֱ���˳�
		if (max == parent) {
			return;
		}
		swap(v[max], v[parent]);
		parent = (parent - 1) / 2;
		left = parent * 2 + 1;
		right = parent * 2 + 2;
	}
}

template <class T>
void createHeap(vector<T>& v, int size) {
	for (int i = size - 1; i >= 0; --i) {
		shiftUp(v, i, size);
	}
}


template <class T>
void heapSort(vector<T>& v, int size) {
	cout << "heapSort:" << endl;
	int tmp = size;
	for (int i = 0; i < size - 1; ++i) {
		createHeap(v, tmp);
		swap(v[0], v[tmp - 1]);
		--tmp;
	}
}
