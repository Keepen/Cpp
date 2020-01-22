#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
	int GetNumberOfK(vector<int> data, int k) {
		int ret = 0;
		for (auto& e : data) {
			if (e == k) {
				++ret;
			}
		}
		return ret;
	}
	//方法2:	//直接调用count函数
	/*int GetNumberOfK(vector<int> data, int k) {
		return count(data.begin(), data.end(), k);
	}*/

};

int main() {

	system("pause");
	return 0;
}