#include <iostream>
#include <string>
#include <unordered_map>
#include <stack>
using namespace std;

bool IsValidExp(string s) {
	// write code here
	stack<char> left;
	auto it = s.begin();
	char c = '0';
	unordered_map<char, int> m;
	while (it != s.end()) {
		if (*it == '(' || *it == '[' || *it == '{') {
			if ((*it == '[' && m['('] > 0) || (*it == '{' && (m['('] > 0 || m['['] > 0)))
				return false;
			left.push(*it);
			++m[*it];
		}
		else if (*it == ')') {
			if (left.empty())
				return false;
			c = left.top();
			left.pop();
			--m[c];
			if (c != '(')
				return false;
		}
		else if (*it == ']') {
			if (left.empty())
				return false;
			c = left.top();
			left.pop();
			--m[c];
			if (c != '[')
				return false;
		}
		else if (*it == '}') {
			if (left.empty())
				return false;
			c = left.top();
			--m[c];
			left.pop();
			if (c != '{')
				return false;
		}
		else
			return false;
		++it;
		//cout << c << "  ";
	}
	bool res = left.empty();
	return res;
}

int main() {
	string s = "()[]{}";
	bool ret = IsValidExp(s);
	cout << ret << endl;
	return 0;
}