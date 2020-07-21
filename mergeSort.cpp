#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <class T>
void Print(vector<T>&v){
    for(auto i : v){
        cout << i << " ";
    }
    cout << endl;
}


template <class T>
void merge(vector<T>& v, int left, int mid, int right){
    vector<T> l(v.begin() + left, v.begin() + mid + 1);
    vector<T> r(v.begin() + mid + 1, v.begin() + right + 1);
    int lsize = l.size(), rsize = r.size();
    int i = 0, j = 0, k = left;
    while(i < lsize && j < rsize){
        if(l[i] <= r[j]){
            v[k++] = l[i++];
        }
        else{
            v[k++] = r[j++];
        }
    }
    while(i < lsize){
        v[k++] = l[i++];
    }
    while(j < rsize){
        v[k++] = r[j++];
    }
    //Print(v);
}


template <class T>
void mergeSortInner(vector<T>& v, int left, int right){
    if(right - left < 1){
        return;
    }
    int mid = (left + right) / 2;
    mergeSortInner(v, left, mid);
    mergeSortInner(v, mid + 1, right);
    merge(v, left, mid, right);
}

template <class T>
void mergeSort(vector<T>& v, int size){
    cout << size << endl;
    mergeSortInner(v, 0, size - 1);    
}

template <class T>
void mergeSortUnrec(vector<T>& v, int size){
    if(size < 2){
        return;
    }
    int sz = 1;
    while(sz < size){
        int begin = 0, end = 0, mid = 0;
        while(begin < size){  
            end = begin + sz;
            mid = (begin + end) / 2;          
            if(end >= size){
                end = size - 1;
            }
            if(mid >= size){
                mid = (begin + end) / 2;
            }
            merge(v, begin, mid, end);
            begin = end + 1;
        }
        sz *= 2;
    }
}


int main(){
    vector<int> v = {4, 5, 6, 9, 8, 10, 7, 12, 2, 3, 11};
    //vector<int> v = {3,4,5,6,2,1,9,8,20,10};
    cout << "排序前：";
    Print(v);
    mergeSortUnrec(v, v.size());
    cout << "排序后：";
    Print(v);
    return 0;
}
