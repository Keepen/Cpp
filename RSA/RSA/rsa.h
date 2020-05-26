#pragma once
//#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS 1
#include <boost/multiprecision/cpp_int.hpp>
//#include <boost/multiprecision/random.hpp>
//#include <boost/random/random_device.hpp>
#include <boost/random.hpp>
#include <boost/multiprecision/miller_rabin.hpp>
#define NUMBER 256	//�����ļ�ÿ�δ���256B������

//typedef unsigned long DataType;
typedef boost::multiprecision::int1024_t DataType;

namespace brdm = boost::random;
//�����Կ
struct Key {
	DataType _ekey;	//����
	DataType _dkey;	//����
	DataType _pkey;	//��������
};

//1.��������p��q
//2.��n = qp
//3.��f��n��
//4.��e	1 < e < f(n) && e �� f(n)���ʣ����ѡ��
//5.��d��e * d % f(n) == 1
//	(e,n)  (d,n)

class RSA {
public:
	RSA();
	//�����ļ�
	void ecrept(const char* filename, const char* fileout);
	void dcrept(const char* filename, const char* fileout);

	//����
	DataType ecrept(DataType data, DataType ekey, DataType pkey);
	//����
	DataType decrept(DataType data, DataType dkey, DataType pkey);
	//��ȡ����
	DataType getPrime();
	//�ж��Ƿ�������
	bool isPrime(DataType data);	
	bool isPrimeBigInt(DataType data);
	//��ȡnֵ
	DataType getPkey(DataType prime1, DataType prime2);
	//��ȡŷ������ֵ
	DataType getOrla(DataType prime1, DataType prime2);
	//��ȡeֵ -- ��Կ
	DataType getEkey(DataType orla);
	//��ȡdֵ -- ��Կ
	DataType getDkey(DataType ekey, DataType orla);
	//��ȡ���Լ��
	DataType getGcd(DataType data1, DataType data2);
	//�������е�key
	void getKeys();
	//���ⲿ�ṩ�ӿڣ���ȡ��Կ��˽Կ��n
	Key getallKey();
	
private:
	Key _key;

};
