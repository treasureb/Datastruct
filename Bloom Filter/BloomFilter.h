#pragma once

#include"BitMap.h"
using namespace std;


template<class K>
size_t BKDRHash(const K *str)
{
	register size_t hash = 0;
	while (size_t ch = (size_t)*str++)
	{
		hash = hash * 131 + ch;   // Ҳ���Գ���31��131��1313��13131��131313..  
		// ����˵���˷��ֽ�Ϊλ���㼰�Ӽ����������Ч�ʣ��罫��ʽ���Ϊ��hash = hash << 7 + hash << 1 + hash + ch;  
		// ����ʵ��Intelƽ̨�ϣ�CPU�ڲ��Զ��ߵĴ���Ч�ʶ��ǲ��ģ�  
		// �ҷֱ������100�ڴε������������㣬���ֶ���ʱ�������Ϊ0�������Debug�棬�ֽ��λ�����ĺ�ʱ��Ҫ��1/3����  
		// ��ARM����RISCϵͳ��û�в��Թ�������ARM�ڲ�ʹ��Booth's Algorithm��ģ��32λ�����˷����㣬����Ч��������йأ�  
		// ������8-31λ��Ϊ1��0ʱ����Ҫ1��ʱ������  
		// ������16-31λ��Ϊ1��0ʱ����Ҫ2��ʱ������  
		// ������24-31λ��Ϊ1��0ʱ����Ҫ3��ʱ������  
		// ������Ҫ4��ʱ������  
		// ��ˣ���Ȼ��û��ʵ�ʲ��ԣ���������Ȼ��Ϊ����Ч���ϲ�𲻴�          
	}
	return hash;
}

template<class K>
size_t SDBMHash(const K *str)
{
	register size_t hash = 0;
	while (size_t ch = (size_t)*str++)
	{
		hash = 65599 * hash + ch;
		//hash = (size_t)ch + (hash << 6) + (hash << 16) - hash;  
	}
	return hash;
}

template<class K>
size_t RSHash(const K *str)
{
	register size_t hash = 0;
	size_t magic = 63689;
	while (size_t ch = (size_t)*str++)
	{
		hash = hash * magic + ch;
		magic *= 378551;
	}
	return hash;
}


template<class K>
size_t APHash(const K *str)
{
	register size_t hash = 0;
	size_t ch;
	for (long i = 0; ch = (size_t)*str++; i++)
	{
		if ((i & 1) == 0)
		{
			hash ^= ((hash << 7) ^ ch ^ (hash >> 3));
		}
		else
		{
			hash ^= (~((hash << 11) ^ ch ^ (hash >> 5)));
		}
	}
	return hash;
}

template<class K>
size_t JSHash(const K *str)
{
	if (!*str)        // �����ɱ�����ӣ��Ա�֤���ַ������ع�ϣֵ0  
		return 0;
	register size_t hash = 1315423911;
	while (size_t ch = (size_t)*str++)
	{
		hash ^= ((hash << 5) + ch + (hash >> 2));
	}
	return hash;
}

template<class K>
struct __HashFunc1
{
	size_t operator()(const K& key)
	{
		return BKDRHash(key.c_str());
	}
};

template <class K>
struct __HashFunc2
{
	size_t operator()(const K& key)
	{
		return SDBMHash(key.c_str());
	}
};

template <class K>
struct __HashFunc3
{
	size_t operator()(const K& key)
	{
		return RSHash(key.c_str());
	}
};

template <class K>
struct __HashFunc4
{
	size_t operator()(const K& key)
	{
		return APHash(key.c_str());
	}
};

template <class K>
struct __HashFunc5
{
	size_t operator()(const K& key)
	{
		return JSHash(key.c_str());
	}
};

template<class K = string, 
class HashFunc1 = __HashFunc1<K>,
class HashFunc2 = __HashFunc2<K>,
class HashFunc3 = __HashFunc3<K>,
class HashFunc4 = __HashFunc4<K>,
class HashFunc5 = __HashFunc5<K>>

class BloomFilter
{
public:
	BloomFilter()
	:_bm(-1)
	{}

	//��������Ӧ��λ������Ϊ1
	void Set(const K& key)
	{
		size_t index1 = HashFunc1()(key);
		size_t index2 = HashFunc2()(key);
		size_t index3 = HashFunc3()(key);
		size_t index4 = HashFunc4()(key);
		size_t index5 = HashFunc5()(key);

		_bm.Set(index1);
		_bm.Set(index2);
		_bm.Set(index3);
		_bm.Set(index4);
		_bm.Set(index5);
	}

	//��¡��֧��ɾ�������������������ü���
	void UnSet(const K& key)
	{}

	bool Test(const K& key)
	{
		size_t index1 = HashFunc1()(key);
		if (_bm.Test(index1) == 0)
			return false;
		size_t index2 = HashFunc1()(key);
		if (_bm.Test(index2) == 0)
			return false;
		size_t index3 = HashFunc1()(key);
		if (_bm.Test(index3) == 0)
			return false;
		size_t index4 = HashFunc1()(key);
		if (_bm.Test(index4) == 0)
			return false;
		size_t index5 = HashFunc1()(key);
		if (_bm.Test(index5) == 0)
			return false;
	}
private:
	BitMap _bm;
};

void TestBloomFilter()
{
	BloomFilter<> bm;

	bm.Set("http ://passport.csdn.net/account/login?from=http%3a%2f%2fwrite.blog.csdn.net%2fpostlist");
	bm.Set("http ://passport.csdn.net/account/login?from=http%3a%2f%2fwrite.blog.csdn.net%2fist");
	bm.Set("http ://passport.csdn.net/account/login?from=http%3a%2f%2fwrlog.csdn.net%2fpostlist");
	bm.Set("http ://passport.csdn.net/account/login?from=http%3arite.blog.csdn.net%2fpostlist");
	bm.Set("http ://passport.csdn.net/account/login?from%2f%2fwrite.blog.csdn.net%2fpostlist");


	cout<<bm.Test("http ://passport.csdn.net/account/login?from=http%3a%2f%2fwrlog.csdn.net%2fpostlist")<<endl;
}