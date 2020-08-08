//问题描述：
//  将一个字符串后尾插若干字符使其变成回文串

//eg：
//  noon   ---   noon
//  noo    ---   noon
//  hello  ---   olleh

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isCycle(string& s){
    int size = s.size();
    if(size <= 1){
        return true;
    }
    int i = 0, j = size- 1;
    while(i < j){
        if(s[i] != s[j])
            return false;
        ++i;
        --j;
    }
    return true;
}

int Len(string& s){
    int size = s.size();
    if(size <= 1){
        return size;
    }
    int len = 2;
    int max_len = 1;
    while(len <= size){
        string tmp(s.begin() + size - len, s.end());
        if(isCycle(tmp) && max_len < tmp.size()){
            max_len = tmp.size();
        }
        ++len;
    }
    return max_len;
}

int main(){
    string s;
    while(cin >> s){
        string ret(s);
        if(isCycle(s)){
            cout << s << endl;
            continue;
        }
        int len = Len(s);
        if(len == 1){
            string tmp(s.begin(), s.end() - 1);
            reverse(tmp.begin(), tmp.end());
            ret += tmp;
            cout << ret << endl;
        }
        else{
            string tmp(s.begin(), s.end() - len);
            reverse(tmp.begin(), tmp.end());
            ret += tmp;
            cout << ret << endl;
        }

    }
    return 0;
}
