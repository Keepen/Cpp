//问题描述：
//  将一个32位整数各位数字反转
//  越界以后返回0；

#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:

    long stoi(string s){
        long ret = 0;
        if(s.size() == 0){
            return 0;
        }

        auto it = s.end() - 1;
        long i = 1;
        while(it != s.begin()){
            ret += i * (*it - '0');
            i *= 10;
            --it;
        }
        ret += i * (*it - '0');
        if(ret > INT_MAX){
            return 0;
        }
        return ret;
    }

    int reverse(int x) {

        string s;
        bool flag = false;
        if(x < 0){
            flag = true;
        }
        long n = abs(x);
        if(x < INT_MIN){
            return 0;
        }
        while(n){
            s += n % 10 + '0';
            n /= 10;
        }
        long ret = stoi(s);
        if(flag){
            return -ret;
        }
        return ret;
    }

};
int main(){
    return 0;
}