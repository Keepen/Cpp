//问题描述：
//  如果第一个非空字符为正或者负号时，则将该符号与之后面尽可能多的连续数字字符组合起来，
//  形成一个有符号整数。
// 假如第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成一个整数。
// 该字符串在有效的整数部分之后也可能会存在多余的字符，那么这些字符可以被忽略，
//  它们对函数不应该造成影响。
// 注意：假如该字符串中的第一个非空格字符不是一个有效整数字符、字符串为空或字符串仅包含空白字符时，
// 则你的函数不需要进行转换，即无法进行有效转换。

// 在任何情况下，若函数不能进行有效的转换时，请返回 0 。

// 提示：

// 本题中的空白字符只包括空格字符 ' ' 。
// 假设我们的环境只能存储 32 位大小的有符号整数，那么其数值范围为 [−231,  231 − 1]。
// 如果数值超过这个范围，请返回  INT_MAX (231 − 1) 或 INT_MIN (−231) 。


//思路：
//  1.处理空格
//  2.处理正负号
//  3.处理边界值


#include <iostream>
#include <string>
#include <climits>
using namespace std;
class Solution {
public:
    bool isDigit(char c){
        return (c >= '0' && c <= '9');
    }

    int myAtoi(string str) {
        int size = str.size();
        long res = 0;
        int i = 0;
        int flag = 1;
        while(i < size && str[i] == ' '){
            ++i;
        }
        if(str[i] == '-'){
            flag = -1;
        }
        if(str[i] == '-' || str[i] == '+'){
            ++i;
        }
        for(;i < size && isDigit(str[i]);++i){
            res = res * 10 + (str[i] - '0');
            if(res > INT_MAX && flag == -1){
                return INT_MIN;
            }
            if(res >= INT_MAX && flag == 1){
                return INT_MAX;
            }
        }
        return flag * res;
    }
};

int main(){
    string s = "   -2147483647";
    Solution so;
    cout << so.myAtoi(s) << endl;
    return 0;
}