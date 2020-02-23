#include "insertSort.h"
#include "selectSort.h"
#include "quickSort.h"
#include "mergeSort.h"
#include "bubbleSort.h"
#include "heapSort.h"
//ƒ¨»œ≈≈…˝–Ú
template <class T>
void show(vector<T>& v) {
	for (auto& e : v) {
		cout << e << " ";
	}
	cout << endl;
}


int main() {
	vector<int> v = { 3,4,5,2,1,2,9,5,6,7,8 };
	int size = v.size();
	cout << "≈≈–Ú«∞: ";
	show(v);
	//insertSort(v, size);
	//selectSort(v, size);
	//quickSort(v, size);
	//merge(v, 0, size / 2, size - 1);
	//mergeSort(v, size);
	//bubbleSort(v, size);
	heapSort(v, size);
	cout << "≈≈–Ú∫Û£∫";
	show(v);
	return 0;
}