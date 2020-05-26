#pragma once
//#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS 1
#include <boost/multiprecision/cpp_int.hpp>
//#include <boost/multiprecision/random.hpp>
//#include <boost/random/random_device.hpp>
#include <boost/random.hpp>
#include <boost/multiprecision/miller_rabin.hpp>
#define NUMBER 256	//加密文件每次处理256B的数据

//typedef unsigned long DataType;
typedef boost::multiprecision::int1024_t DataType;

namespace brdm = boost::random;
//存放密钥
struct Key {
	DataType _ekey;	//加密
	DataType _dkey;	//解密
	DataType _pkey;	//公共部分
};

//1.产生素数p、q
//2.求n = qp
//3.求f（n）
//4.求e	1 < e < f(n) && e 和 f(n)互质，随机选择
//5.求d：e * d % f(n) == 1
//	(e,n)  (d,n)

class RSA {
public:
	RSA();
	//加密文件
	void ecrept(const char* filename, const char* fileout);
	void dcrept(const char* filename, const char* fileout);

	//加密
	DataType ecrept(DataType data, DataType ekey, DataType pkey);
	//解密
	DataType decrept(DataType data, DataType dkey, DataType pkey);
	//获取素数
	DataType getPrime();
	//判断是否是素数
	bool isPrime(DataType data);	
	bool isPrimeBigInt(DataType data);
	//获取n值
	DataType getPkey(DataType prime1, DataType prime2);
	//获取欧拉函数值
	DataType getOrla(DataType prime1, DataType prime2);
	//获取e值 -- 公钥
	DataType getEkey(DataType orla);
	//获取d值 -- 密钥
	DataType getDkey(DataType ekey, DataType orla);
	//获取最大公约数
	DataType getGcd(DataType data1, DataType data2);
	//产生所有的key
	void getKeys();
	//向外部提供接口，获取公钥、私钥、n
	Key getallKey();
	
private:
	Key _key;

};
