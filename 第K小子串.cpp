// 问题描述：
//  输入一个字符串和一个数字，输出按字典序排列的第K小的子串


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main(){
    string s;
    int n;
    while(cin >> s >> n){
        unordered_map<string, int> m;
        int i = 1;
        int count = 0;
        int len = s.size();
        while(i <= len){
            for(int j = 0;j < len - i + 1;++j){
                cout << i << " " << j << endl;
                string tmp = s.substr(j, i);
                cout << tmp << endl;
                ++m[tmp];++count;
                if(count > n){
                   auto it = m.begin();
                    int mm = 1;
                    while(mm != count - 1){
                        ++it;
                        ++mm;
                    }
                    cout << it->second << endl;
                    m.erase(it);
                    count = n;
                }
            }
            ++i;
        }
        i = 1;
        auto it = m.begin();
        while(i != n){
            ++it;
            ++i;
        }
        cout << it->first << endl;
    }
    return 0;
}