

#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
using namespace std;



//1.直接使用数组
class Solutions {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        vector<int> s;
        int j = 0;
        for(int i = 0;i < pushed.size();++i){
            s.push_back(pushed[i]);
            while(s.size() && s.back() == popped[j]){
                ++j;
                s.pop_back();
            }
        }
        return s.size() == 0;
    }
};


//2.使用哈希
class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		unordered_map<int, int> key;
		for (size_t i = 0; i < pushV.size(); ++i) {
			key[pushV[i]] = i;
		}
		stack<int> s;
		int count = 0;
		for (size_t i = 0; i < popV.size(); ++i) {
			int num = key[popV[i]];		//记录当前的出栈数字在入栈序列中的下标
			if (num >= count) {
				for (int j = count; j <= num; ++j) {
					++count;
					s.push(pushV[j]); 
				}
			}
			if (popV[i] == s.top()) {
				s.pop();
			}
			else {
				return false;
			}
		}
		return true;
	}
};

int main(){
    return 0;
}