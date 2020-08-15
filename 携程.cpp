// 问题描述：
//  有长度 a 和 b 两种长度的砖，从中选取 K 块，返回所有可能拼出的长度
//  并按照升序排列
//  注意：砖块的数目没有限制

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int a, b, k;
    while(cin >> a >> b >> k){
        vector<int> ret;
        for(int i = 0;i <= k;++i){
            int j = k - i;
            int tmp = i * a + j * b;
            ret.push_back(tmp);
        }
        sort(ret.begin(), ret.end());
        vector<int> res;
        res.push_back(ret[0]);
        for(int i = 1;i < ret.size();++i){
            if(ret[i] != res[res.size() - 1]){
                res.push_back(ret[i]);
            }
        }
        for(const int& v : res){
            cout << v << " ";
        }
        cout << endl;
    }
    return 0;
}