// Chapter1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <cassert>

#define NDEBUG 1

char* ArrayAllac(int n)
{
	assert(n > 0);
	cout << "operate!" << endl;
	return new char[n];
}

template <typename T, typename U>
int bit_copy(T& a, U& b)
{
	static_assert(sizeof(b) == sizeof(a), "wrong parm");
	memcpy(&a, &b, sizeof(b));
	return 0;
}

struct C
{
	C(int i) : c(i) {};
	int c;
};

struct B
{
	int a{ 1 };
	int b = 1;
	char p = 'e';
	//static const char c = 'e';
	C c{ 2 };

	int getC()
	{
		return c.c;
	}
};

int main()
{
    //std::cout << "Hello World!\n"; 
    //std::cout << __func__ << endl	;

	//char* p = ArrayAllac(-1);

	int a = 0x2468;
	int b;
	bit_copy(a, b);

	B newB;
	cout << newB.getC() << endl;
}

