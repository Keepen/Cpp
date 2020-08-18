// 问题描述：
//  在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
//  输入一个数组,求出这个数组中的逆序对的总数P。
//  并将P对1000000007取模的结果输出。 即输出P%1000000007

// 思路：
//  1.归并排序 -- 降序排列
//  2.合并数组时进行判断，并更新结果的和 


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    const int p = 1000000007;
    long ret = 0;
    int InversePairs(vector<int> data) {
        if(data.size() == 0){
            return 0;
        }
        mergeSort(data, 0, data.size() - 1);
        return ret;
    }
    
    void mergeSort(vector<int>& v, int left, int right){
        if(left >= right){
            return;
        }
        int mid = (left + right) >> 1;
        mergeSort(v, left, mid);
        mergeSort(v, mid + 1, right);
        merge(v, left, mid, right);
    }
    void merge(vector<int>& v, int left, int mid, int right){
        vector<int> tmp;
        int begin = left;
        int sec = mid + 1;
        while(begin <= mid && sec <= right){
            if(v[begin] > v[sec]){
                tmp.push_back(v[begin++]);
                ret = (ret + right  + 1 - sec) % p;
                cout << "mid + 1 - begin : " << mid + 1 -begin << "-->ret : " << ret << endl;
            }
            else{
                tmp.push_back(v[sec++]);
            }
        }
        while(begin <= mid){
            tmp.push_back(v[begin++]);
        }
        while(sec <= right){
            tmp.push_back(v[sec++]);
        }
        for(int i = 0;i < tmp.size() ;++i){
            v[left + i] = tmp[i];
        }
    }
};

int main(){
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 0};
    Solution s;
    cout << s.InversePairs(v) << endl;
    return 0;
}