#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//建小堆：排升序
void shiftDown(vector<int>& v, int pos, int size) {
	int left = pos * 2 + 1;
	int right = pos * 2 + 2;
	while (1) {
		//到叶子节点就结束
		if (left >= size) {
			return;
		}		
		if (right >= size && v[left] >= v[pos]) {
			return;
		}
		if (right < size && v[pos] <= v[left] && v[pos] <= v[right]) {
			return;
		}
		int min = left;
		if (right < size && v[right] < v[left]) {
			min = right;
		}
		swap(v[min], v[pos]);
		pos = min;
		left = pos * 2 + 1;
		right = pos * 2 + 2;
	}
}

//建堆
void createHeap(vector<int>& v, int size) {
	for (int i = 0; i < size; ++i) {
		shiftDown(v, i, size);
	}
}


void show(vector<int>& v){
	for (auto& e : v) {
		cout << e << " ";
	}
	cout << endl;
}



void test() {
	vector<int> v = { 3,6,5,4,7,8,9,10,11 };
	int size = v.size();
	cout << size << endl;
	show(v);
	createHeap(v, size);
	//shiftDown(v, 1, size);
	show(v);
}

int main() {
	test();
	return 0;
}