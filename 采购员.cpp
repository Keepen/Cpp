//问题描述：
//  给定mon元，有若干物品，每个物品都有自己的价格和价值
//  求最多可以用给定的钱买到的物品价值是多少

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int mon;
    while(cin >> mon){
        int n;
        vector<pair<int, int>> v;
        vector<int> f(mon + 1, 0);
        while(n--){
            int a, b;
            cin >> a >> b;
            v.push_back(make_pair(a, b));
        }
        for(int i = 1;i <= mon;++i){
            for(int j = 0;j < n;++j){
                f[i] = max(f[i], f[i - v[j].first] + v[j].second);
            }
        }
        cout << f[mon] << endl;
    }
    return 0;
}