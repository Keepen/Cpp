#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
//利用数组来保存插入的字符，没插入一个字符，将对应的值进行加1操作


class Solution
{
public:
	//Insert one char from stringstream
	void Insert(char ch)
	{
		vec.push_back(ch);
		mapdata[ch]++;
	}
	//return the first appearence once char in current stringstream
	char FirstAppearingOnce()
	{
		vector<int>::iterator it;
		for (it = vec.begin(); it != vec.end(); it++)
		{
			if (mapdata[*it] == 1)
				return *it;
		}
		return '#';
	}
	unordered_map<char, int> mapdata;
	vector<int> vec;
	
};

int main() {
	system("pause");
	return 0;
}