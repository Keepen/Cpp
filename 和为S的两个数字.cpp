// 问题描述：
//  输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，
//  如果有多对数字的和等于S，输出两个数的乘积最小的。
//  对应每个测试案例，输出两个数，小的先输出。

//思路：
//  暴力搜索即可

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    static bool cmp(pair<int, int> a, pair<int, int> b){
        return a.first * a.second < b.first * b.second;
    }
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> a;
        if(array.size() == 0){
            return a;
        }
        vector<pair<int, int>> ret;
        for(int i = 0;i < array.size() - 1;++i){
            int tmp = array[i];
            for(int j = i + 1;j < array.size();++j){
                if(tmp + array[j] == sum){
                    ret.push_back(make_pair(array[i], array[j]));
                }
            }
        }
        sort(ret.begin(), ret.end(), cmp);
        if(ret.size() > 0){
            a.push_back(ret[0].first);
            a.push_back(ret[0].second);
        }
        return a;
    }
};

int main(){
    
    return 0;
}