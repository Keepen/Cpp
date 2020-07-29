//问题描述：
//  有 n 个硬币排成一条线。两个参赛者轮流从右边依次拿走 1 或 2 个硬币，
//  直到没有硬币为止。拿到最后一枚硬币的人获胜。
//  请判定 先手玩家 必胜还是必败?
//  若必胜, 返回 true, 否则返回 false.

//思路：
//  从最后一个棋子开始 -- 剩了一个 / 2个棋子 -- 获胜
//  剩了3个棋子 -- 必败
//  f[i] = (!f[i - 1] || !f[i - 2])

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    bool firstWillWin(int n) {
        // write your code here
        vector<bool> ret(n+1, true);
        ret[0] = false;
        ret[1] = true;
        for(int i = 2;i < n + 1;++i){
            ret[i] = (!ret[i - 1] || !ret[i - 2]);
        }
        return ret[n];
    }
};

int main(){
    return 0;
}