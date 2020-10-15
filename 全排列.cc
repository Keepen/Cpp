#include <iostream>
using namespace std;

int vis[100];

void fun(int x, int n, int* ans){
    // 得到结果就输出
    if(x > n){
        for(int i = 1;i < x;++i){
            cout << ans[i] << "  ";
        }
        cout << endl;
        return;
    }
    // 不然就继续都深度优先
    for(int i = 1;i <= n;++i){
        if(vis[i] == 0){
            vis[i] = 1;
            ans[x] = i;
            fun(x + 1, n, ans);
            vis[i] = 0;
        }
    }
}

int main(){
    int n = 3;
    int *ans = new int[n + 1];
    fun(1, n, ans);
    return 0;
}