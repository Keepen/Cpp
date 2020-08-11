//问题描述：
//  将一个字符串通过替换字符的方式变成回文串 -- 
//  输出需要替换的字符数

#include <iostream>
#include <string>
using namespace std;

int step(string& s){
    int ret = 0;
    int i = 0, j = s.size() - 1;
    while(i < j){
        if(s[i] != s[j])
            ++ret;
    }
    return ret;
}



int main(){
    return 0;
}
