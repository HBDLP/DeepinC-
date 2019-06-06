#include "pch.h"
#include "extemplate.h"
//
//template <typename T>
//void  fun(T a)
//{
//	cout << a << endl;
//}
template void fun<int>(int);

void test1()
{
	fun(1);
}