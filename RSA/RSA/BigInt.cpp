#include "bigint.h"

BigInt::BigInt(const std::string& num):
	_number(num){}

//ģ��ӷ�
std::string BigInt::add(std::string s1, std::string s2) {
	//λ������
	int len1 = s1.size();
	int len2 = s2.size();
	int diffNum = abs(len1 - len2);
	int longSize = len1 > len2 ? len1 : len2;
	if (len1 < len2) {
		s1.insert(0, diffNum, '0');
	}
	else if(len2 < len1) {
		s2.insert(0, diffNum, '0');
	}
	std::string ret;
	ret.resize(longSize);
	//��λ���
	int step = 0;
	for (int i = longSize - 1; i >= 0; --i) {
		ret[i] = (s1[i] - '0' + s2[i] - '0') + step;
		ret[i] += '0';
		//����
		if (ret[i] > '9') {
			ret[i] -= 10;
			step = 1;
		}
		else {
			step = 0;
		}
	}
	if (step == 1) {
		ret.insert(0, 1, '1');
	}
	return ret;
}

std::string BigInt::sub(std::string s1, std::string s2) {
	//λ������
	int len1 = s1.size();
	int len2 = s2.size();
	int diffNum = abs(len1 - len2);
	int longSize = len1 > len2 ? len1 : len2;
	if (len1 < len2) {
		s1.insert(0, diffNum, '0');
	}
	else if (len2 < len1) {
		s2.insert(0, diffNum, '0');
	}
	std::string ret;
	ret.resize(longSize);
	for (int i = longSize - 1; i >= 0; --i) {
		if (s1[i] < s2[i]) {
			s1[i] += 10;
			s1[i - 1]--;
		}
		//�������ٱ��ַ�
		ret[i] = (s1[i] - '0') - (s2[i] - '0') + '0';
	}
	while (ret.size() > 1 && ret[0] == '0') {
		ret.erase(0, 1);
	}
	return ret;
}
std::string BigInt::mul(std::string s1, std::string s2) {
	//�򻯳˷����� -- С�� * ����
	if (s2.size() > s1.size()) {
		swap(s2, s1);
	}
	std::string ret = "0";
	for (int i = s2.size() - 1; i >= 0; --i) {
		//��ȡ��ǰ������Ӧλ��ֵ
		int curDigit = s2[i] - '0';
		int step = 0;
		//��ǰλ�˻��Ľ��
		std::string temp = s1;
		for (int j = temp.size() - 1; j >= 0; --j) {
			//��λ���
			temp[j] = (temp[j] - '0')*curDigit + step;
			//���½�λֵ
			if (temp[j] > 9) {
				step = temp[j] / 10;
				temp[j] = temp[j] - step * 10;
			}
			else {
				step = 0;
			}
			//��ԭ���ַ�
			temp[j] += '0';
		}
		//����ж��Ƿ���Ҫ��λ
		if (step > 0) {
			temp.insert(0, 1, step + '0');
		}
		//�������
		temp.append(s2.size() - 1 - i, '0');
		//�ۼ�һ�γ˷��Ľ��
		ret = add(ret, temp);
	}
	return ret;
}

//����������������ʵ��
std::pair<std::string, std::string> BigInt::dev(std::string s1, std::string s2) {
	std::string ret;
	std::string rem = s1;	//����
	//����������һ������
	int diffNum = s1.size() - s2.size();
	s2.append(diffNum, '0');
	for (int i = 0; i <= diffNum; ++i) {
		//��¼����ִ�еĴ���
		char count = '0';
		while (true) {
			if(less(rem, s2)){
				break;
			}
			rem = sub(rem, s2);
			++count;
		}
		ret += count;
		//������С10��
		s2.pop_back();
	}
	//ɾ��ǰ��0
	while (ret.size() > 1 && ret[0] == '0') {
		ret.erase(0, 1);
	}
	//����<�̣�����>
	return make_pair(ret, rem);
}

bool BigInt::less(std::string& s1, std::string& s2) {
	if (s1.size() < s2.size()) {
		return true;
	}
	if (s1.size() > s2.size()) {
		return false;
	}
	//������ͬ
	return s1 < s2;
}


BigInt BigInt::operator+(BigInt& bi) {
	std::string ret = add(_number, bi._number);
	return  BigInt(ret);
}
BigInt BigInt::operator-(BigInt& bi) {
	std::string ret = sub(_number, bi._number);
	return BigInt(ret);
}
BigInt BigInt::operator*(BigInt& bi) {
	std::string ret = mul(_number, bi._number);
	return BigInt(ret);
}
BigInt BigInt::operator/(BigInt& bi) {
	std::pair<std::string, std::string> k = dev(_number, bi._number);
	return BigInt(k.first);
}
BigInt BigInt::operator%(BigInt& bi) {
	std::pair<std::string, std::string> k = dev(_number, bi._number);
	return BigInt(k.second);
}


std::ostream& operator<<(std::ostream& _cout, BigInt& bi) {
	_cout << bi._number << std::endl;
	return _cout;
}
