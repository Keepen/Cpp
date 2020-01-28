#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

//问题描述：大小王可以代替任意牌，共计4张，随机抽出5张牌判断能否组成顺子
//	大小王当作0

//方法一：
//	1.先进行排序
//	2.计算0的数目
//	3.根据0的数目，计算牌的间隔差是否合理
class Solution {
public:
	bool IsContinuous(vector<int> numbers) {
		if (!numbers.size()) {
			return false;
		}
		unordered_map<int, int> key;
		sort(numbers.begin(), numbers.end());
		int size = (int)numbers.size();
		for (auto& e : numbers) {
			key[e]++;
		}
		if (key[0] >= 4) {
			return true;
		}
		if (key[0] == 3) {
			if (numbers[size - 1] - numbers[size - 2] < 5 && numbers[size - 1] - numbers[size - 2] != 0) {
				return true;
			}
			return false;
		}
		if (key[0] == 2) {
			int count = 0;
			for (int i = 2; i < size - 1; ++i) {
				if (numbers[i + 1] - numbers[i] > 3) {
					return false;
				}
				else if (numbers[i + 1] - numbers[i] == 3) {
					count++;
				}
			}
			if (count > 1) {
				return false;
			}
			return true;
		}
		if (key[0] == 1) {
			int count = 0;
			for (int i = 1; i < size - 1; ++i) {
				if (numbers[i + 1] - numbers[i] > 2) {
					return false;
				}
				else if (numbers[i + 1] - numbers[i] == 2) {
					count++;
				}
			}
			if (count > 1) {
				return false;
			}
			return true;
		}
		if (key[0] == 0) {
			for (int i = 0; i < size - 1; ++i) {
				if (numbers[i] + 1 != numbers[i + 1]) {
					return false;
				}
			}
			return true;
		}
	}
};

//方法二：计算出0的数目，和需要的0的数目即可
//class Solution {
//public:
//	bool IsContinuous(vector<int> numbers) {
//		if (!numbers.size()) {
//			return false;
//		}
//		sort(numbers.begin(), numbers.end());
//		int cnt0 = 0, cntNeed = 0;
//		for (int i = 0; i < 5; i++) {
//			if (numbers[i] == 0) {
//				++cnt0;
//			}
//			else if (i + 1 < 5) {
//				if (numbers[i + 1] == numbers[i]) return false;
//				cntNeed += numbers[i + 1] - numbers[i] - 1;
//			}
//		}
//		if (cntNeed > cnt0) return false;
//		return true;
//	}
//};

int main() {
	return 0;
}