#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int max_sum(vector<int>& v){
    int ret = v[0];
    int size = v.size();
    int maxi = v[0];    //保存当前最大连续子数组的和
    for(int i = 1;i < size;++i){
        maxi = max(v[i], v[i] + maxi);  //保存连续子数组起始位置的和
        ret = max(ret, maxi);   //保存每一阶段的结果
        cout << ret << " ";
    }
    return ret;
}


int main(){
    vector<int> v = {2, -3, 3, 2, -10, 1, 4, 6, -9, 10, 2};
    cout << max_sum(v) << endl;
    return 0;
}
