#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <class T>
void adjustDown(vector<T>& v, int pos, int size){
    int parent = pos;
    int left = parent * 2 + 1, right = parent * 2 + 2;
    int max = left;
    while(left < size){
        if(right < size && v[right] > v[left]){
            max = right;
        }
        if(v[max] <= v[parent]){
            return;
        }
        swap(v[parent], v[max]);
        parent = max;
        left = parent * 2 + 1;
        right = parent* 2 + 2;
        max = left;
    }
}

template <class T>
void createHeap(vector<T>& v, int size){
    for(int i = size / 2;i >= 0;--i){
        adjustDown(v, i, size);
    }
}

template <class T>
void heapSort(vector<T>& v, int size){
    createHeap(v, size);
    for(int i = size - 1;i >= 1;--i){
        swap(v[0], v[i]);
        adjustDown(v, 0, i);
    }
}

void Print(vector<int>&v){
    for(auto i : v){
        cout << i << " ";
    }
    cout << endl;
}

int main(){
    vector<int> v = {3,4,5,6,2,1,9,8,20,10};
    cout << "排序前：";
    Print(v);
    heapSort(v, v.size());
    cout << "排序后：";
    Print(v);
    return 0;
}