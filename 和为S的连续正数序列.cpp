// 问题描述：
//  小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。
//  但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。
//  没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。
//  输出所有和为S的连续正数序列。序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序

//思路：穷举
//  从1开始穷举到和的一半


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> ret;
        int left = 1, right = 1;
        int tmp = 0;
        while(left <= sum / 2){
            if(tmp < sum){
                tmp += right;
                ++right;
            }
            else if(tmp > sum){
                tmp -= left;
                ++left;
            }
            else{
                vector<int> ans;
                for(int i = left;i < right;++i){
                    ans.push_back(i);
                }
                ret.push_back(ans);
                tmp -= left;
                ++left;
            }
        }
        return ret;
    }
};

int main(){
    int sum = 100;
    Solution s;
    vector<vector<int>> v = s.FindContinuousSequence(sum);
    for(int i = 0;i < v.size();++i){
        for(int j = 0;j < v[i].size();++j){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}