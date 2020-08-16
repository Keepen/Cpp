// 问题描述：
//   将一个字符串的全排列按字典序输出

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> ret;
        if(str.size() == 0){
            return ret;
        }
        permutation(str, 0, str.size(), ret);
        return ret;
    }
    void permutation(string str, int index, int len, vector<string>& ret) {
        if (index == len - 1) {
            ret.push_back(str);
            return;
        }
        for (int i = index; i < len; ++i) {
            if (i != index && str[i] == str[index]) {
                continue;
            }
            swap(str[i], str[index]);
            permutation(str, index + 1, str.size(), ret);
        }
    }
};

int main(){
    string s = "aabc";
    vector<string> ret;
    Solution so;
    ret = so.Permutation(s);
    for(auto & s: ret){
        cout << s << endl;
    }
    cout << ret.size() << endl;
    return 0;
}