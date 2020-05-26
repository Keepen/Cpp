#include <time.h>
#include <iostream>
#include <math.h>
#include <fstream>
#include <algorithm>
#include "rsa.h"
using namespace std;


RSA::RSA() {
	getKeys();
	cout << "ekey : " << _key._ekey << endl;
	cout << "dkey : " << _key._dkey << endl;
	cout << "pkey : " << _key._pkey << endl;
}

void RSA::ecrept(const char* filename, const char* fileout) {
	//���ն����ƽ��ļ���
	std::ifstream fin(filename, std::ifstream::binary);
	std::ofstream fout(fileout, std::ofstream::binary);
	if (!fin.is_open()) {
		perror("file open error!\n");
		return;
	}
	char* buffer = new char[NUMBER];
	DataType* bufferOut = new DataType[NUMBER];
	while (!fin.eof()) {
		fin.read(buffer, NUMBER);
		//���һ�ζ�ȡ���ֽ���Ŀ�Ƕ���
		int curNum = fin.gcount();
		for (int i = 0; i < curNum; ++i) {
			bufferOut[i] = ecrept((DataType)buffer[i], _key._ekey, _key._pkey);
		}
		fout.write((char*)bufferOut, curNum * sizeof(DataType));
	}  

	delete[]  bufferOut;
	delete[] buffer;
	fin.close();
	fout.close();
} 

void RSA::dcrept(const char* filename, const char* fileout) {
	std::ifstream fin(filename, std::ifstream::binary);
	std::ofstream fout(fileout, std::ofstream::binary);
	if (!fin.is_open()) {
		perror("file open failed\n");
		return;
	}
	DataType* buffer = new DataType[NUMBER];

	char* bufferOut = new char[NUMBER];
	while (!fin.eof()) {
		fin.read((char*)buffer, NUMBER * sizeof(DataType));
		int num = fin.gcount();
		num /= sizeof(DataType);
		for (int i = 0; i < num; ++i) {
			bufferOut[i] = (char)decrept(buffer[i], _key._dkey, _key._pkey);
		}
		fout.write(bufferOut, num);
	}
	delete[] buffer;
	delete[] bufferOut;

	fout.close();
	fin.close();
}
Key RSA::getallKey() {
	//getKeys();
	return _key;
}

//�õ���Կ
void RSA::getKeys() {
	DataType prime1 = getPrime();
	DataType prime2 = getPrime();
	while (prime1 == prime2) {
		prime2 = getPrime();
	}
	cout << prime1 << "  " << prime2 << endl;
	DataType orla = getOrla(prime1, prime2);
	_key._pkey = getPkey(prime1, prime2);
	_key._ekey = getEkey(orla);
	_key._dkey = getDkey(_key._ekey, orla);
}

//����
DataType RSA::ecrept(DataType data, DataType ekey, DataType pkey) {
	//�������
	//i: 0 ~ ���һλ
	DataType Ai = data;
	DataType msgE = 1;
	// data ^ ekey % pkey
	while (ekey) {
		if (ekey & 1) {
			msgE = (msgE * Ai) % pkey;
		}
		ekey >>= 1;
		Ai = (Ai * Ai) % pkey;
	}
	return msgE;
}
//����
DataType RSA::decrept(DataType data, DataType dkey, DataType pkey) {
	return ecrept(data, dkey, pkey);
}
//��ȡ����
DataType RSA::getPrime() {
	cout << "get prime:" << endl;
	srand((unsigned int)time(NULL));	//�������������
	brdm::mt19937 gen(time(0));
	brdm::uniform_int_distribution<DataType> dist(0, DataType(1) << 256);
	DataType prime;
	while (1) {
		prime = rand() % 100 + 2;
		prime = dist(gen);
		if (isPrime(prime)) {
			return prime;
		}
	}
}
//�ж��Ƿ�������
bool RSA::isPrime(DataType data) {
	cout << "is prime" << endl;
	if (data <= 1) {
		return false;
	}
	if (data == 2) {
		return true;
	}
	for (DataType i = 2; i <= sqrt(data); ++i) {
		if (data % i == 0) {
			return false;
		}
	}
	return true;
}

bool RSA::isPrimeBigInt(DataType data) {
	brdm::mt11213b gen(time(nullptr));
	if (miller_rabin_test(data, 25, gen)) {
		if (miller_rabin_test((data - 1) / 2, 25, gen)) {
			return true;
		}
	}
	return false;
}

//��ȡnֵ
DataType RSA::getPkey(DataType prime1, DataType prime2) {
	return prime1 * prime2;
}
//��ȡŷ������ֵ
DataType RSA::getOrla(DataType prime1, DataType prime2) {
	return (prime1 - 1) * (prime2 - 1);
}
//��ȡeֵ -- ��Կ
DataType RSA::getEkey(DataType orla) {
	//srand((unsigned int)time(NULL));	//�������������
	brdm::mt19937 gen(time(nullptr));
	brdm::uniform_int_distribution<DataType> dist(2, orla);
	DataType ekey;
	while (true) {
		//ekey = rand() % orla;
		ekey = dist(gen);
		if (ekey > 1 && getGcd(ekey, orla) == 1) {
			return ekey;
		}
	}
}
//��ȡdֵ -- ��Կ
//e * d % f(n) == 1;
DataType RSA::getDkey(DataType ekey, DataType orla) {
	DataType dkey = orla / ekey;	//���������̿�ʼ����
	while (true) {
		if ((dkey * ekey) % orla == 1) {
			return dkey;
		}
		++dkey;
	}
}
//��ȡ���Լ��
//	��ת�������
//		a��b --> b, a % b --> a%b, a%b%(a%b)
DataType RSA::getGcd(DataType data1, DataType data2) {
	DataType res;
	while (res = data1 % data2) {
		data1 = data2;
		data2 = res;
	}
	return data2;
}




