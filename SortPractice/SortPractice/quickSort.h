#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

//挖坑法：分割区间
//	用临时变量来记录基准值，开始遍历区间
//	比基准值大的放在后面，比基准值小的，放在前面
template <class T>
int part(vector<T>& v, int left, int right) {
	int pivot = v[right];
	int begin = left, end = right;
	while (begin < end) {
		//先走begin
		while (begin < end && v[begin] <= pivot) {
			++begin;
		}
		v[end] = v[begin];
		//再走end
		while (begin < end && v[end] >= pivot) {
			--end;
		}
		v[begin] = v[end];
	}
	v[begin] = pivot;
	return begin;
}


template <class T>
void quickSort(vector<T>& v, int size) {
	cout << "quickSort : " << endl;
	stack<T> s;
	int left = 0, right = size - 1;
	s.push(right);
	s.push(left);
	while (!s.empty()) {
		left = s.top();
		s.pop();
		right = s.top();
		s.pop();
		if (right - left > 0) {
			int mid = part(v, left, right);
			//右侧区间
			s.push(right);
			s.push(mid + 1);
			//左侧区间
			s.push(mid - 1);
			s.push(left);
		}
	}
}
