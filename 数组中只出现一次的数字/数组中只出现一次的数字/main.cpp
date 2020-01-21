#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
	void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
		unordered_map<int, int> k;
		int ret = 1;
		for (auto& e : data) {
			k[e]++;
		}
		for (auto& e : data) {
			if (k[e] == 1 && ret == 1) {
				*num1 = e;
				++ret;
			}
			else if (k[e] == 1 && ret == 2) {
				*num2 = e;
				return;
			}
		}
	}
};


int main() {
	system("pause");
	return 0;
}