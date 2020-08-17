// 问题描述：
//  输入一个正整数数组，把数组里所有数字拼接起来排成一个数，
//  打印能拼接出的所有数字中最小的一个。
//  例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。

// 思路：
//  将数组按照数字a、b
//      a + b < b + a 的方式进行排序
//  排好序后直接组织成字符串
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        string ret;
        if(numbers.size() == 0){
            return ret;
        }
        sort(numbers.begin(), numbers.end(), cmp);
        for(int i = 0;i < numbers.size();++i){
            ret += to_string(numbers[i]);
        }
        return ret;
    }
    static bool cmp(int a, int b){
        string A = to_string(a) + to_string(b);
        string B = to_string(b) + to_string(a);
        return A < B;
    }
};

int main(){
    vector<int> v = {3, 4, 12, 321};
    Solution s;
    cout << s.PrintMinNumber(v) << endl;
    return 0;
}