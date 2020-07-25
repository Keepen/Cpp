//问题描述：
//  在一个数组中有正整数和负数，求连续序列的最大和
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSum(vector<int>& array){
    int size = array.size();
    if(size == 0){
        return 0;
    }
    vector<int> f(size, 0);
    int ret = array[0];
    for(int i = 1;i < size;++i){
        f[i] = max(array[i], f[i - 1] + array[i]);
        if(ret < f[i]){
            ret = f[i];
        }
    }
    return ret;
}

int main(){
    return 0;
}