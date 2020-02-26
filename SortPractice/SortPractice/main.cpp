#include "bubbleSort.h"
#include "selectSort.h"
#include "insertSort.h"
#include "heapSort.h"
#include "quickSort.h"
#include "mergeSort.h"

template <class T>
void show(vector<T>& v) {
	for (auto& e : v) {
		cout << e << " ";
	}
	cout << endl;
}

int main() {
	vector<int> v = { 4,7,9,2,1,3,4,5,8,9,4 };
	int size = v.size();
	cout << "ÅÅÐòÇ°£º" << endl;
	show(v);
	//bubbleSort(v, size);
	//selectSort(v, size);
	//insertSort(v, size);
	//heapSort(v, size);
	//quickSort(v, size);
	mergeSort(v, size);
	cout << "ÅÅÐòºó£º" << endl;
	show(v);
	return 0;
}