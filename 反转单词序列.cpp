// 问题描述：
//  “student. a am I”。后来才意识到，
//  这家伙原来把句子单词的顺序翻转了，正确的句子应该是“I am a student.”

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string ReverseSentence(string str) {
        string ret;
        int j = str.size();
        int len = 0;
        for(int i = str.size() - 1;i >= 0;--i){
            if(str[i] == ' '){
                ret += str.substr(i + 1, len);
                ret += ' ';
                len = 0;
            }
            else if(i == 0){
                ret += str.substr(i, len + 1);
            }
            else{
                ++len;
            }
        }
        return ret;
    }
};

int main(){
    string str = "student. a am I";
    Solution s;
    cout << s.ReverseSentence(str) << endl;
    return 0;
}