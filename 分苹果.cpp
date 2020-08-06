//问题描述：

// n 只奶牛坐在一排，每个奶牛拥有 ai 个苹果，现在你要在它们之间转移苹果，
// 使得最后所有奶牛拥有的苹果数都相同，每一次，你只能从一只奶牛身上拿走恰好两个苹果到另一个奶牛上，
// 问最少需要移动多少次可以平分苹果，如果方案不存在输出 -1。

//思路：
//  1.能平分 -- 每只奶牛得到的就是平均数；如果总数不能被人数整除，就是-1
//  2.每次只能移动两个，哪一个奶牛拿的不是平均数，就让次数 += |平均数 - 当前拿的数目| / 2；
//  3.因为，比平均值少的，和比平均值多的都算了一次，所以结果要 / 2；
//  4.或者直接计算其一即可



#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int apple(vector<int>& v, int sum){
    long n = v.size();
    if(sum % n != 0){
        return -1;
    }
    int res = 0;
    int aver = sum / n;
    for(int i = 0;i < n;++i){
        if(v[i] > aver){
            int tmp = abs(v[i] - aver);
            if(tmp & 1){
                return -1;
            }
            res += (tmp / 2);
        }
    }
    return res ;
}

int main(){
    int n;
    while(cin >> n){
        vector<int> v(n , 0);
        long sum = 0;
        for(int i = 0;i < n;++i){
            cin >> v[i];
            sum += v[i];
        }
        cout << apple(v, sum) << endl;
    }
    return 0;
}