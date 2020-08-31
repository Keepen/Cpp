#include <vector>
#include <queue>
using namespace std;

//思路：
//  一.可以直接用数组存储，排序后得到中位数

//  二.利用两个堆，一个大堆，一个小堆
//      1.优先向大堆中插入元素
//      2.如果当前要插入的元素比小堆堆顶还大，那就将小堆当前堆顶插入到大堆中
//          并且将待插入数字插入到大堆中
//      3.大堆的元素数目不能比小堆数目多2个，如果多2个，就进行调整
//          调整：将大堆堆顶插入小堆中，再将大堆堆顶弹出

class Solution {
public:
    priority_queue<int> big;
    priority_queue<int, vector<int>,  greater<int>> little;
    void Insert(int num)
    {
        big.push(num);
        if(little.size() > 0 && num > little.top()){
            big.pop();
            big.push(little.top());
            little.pop();
            little.push(num);
        }
        if(big.size() - little.size() > 1){
            little.push(big.top());
            big.pop();
        }
    }

    double GetMedian()
    { 
        double ret = 0.0;
        if(big.size() == little.size())
            ret = ((double)big.top() + (double)little.top()) / 2.0;
        else{
            ret = big.top();
        }
        return ret;
        
    }

};