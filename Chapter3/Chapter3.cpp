// Chapter3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

// #include "pch.h"
#include <iostream>
using namespace std;
struct  A
{
	A(int)
	{
		cout << "con A" << endl;
	}
};

struct B
{
	B(int)
	{
		cout << "con B" << endl;
	}
};

struct C : virtual A
{
	using A::A;

};

/*3.3 右值引用***************************************************/
class HasPtrMem {
public:
	HasPtrMem() :d(new int(0)) { cout << "construct invoke!" << endl; }
	HasPtrMem( HasPtrMem& h) :d(new int(*h.d)) { cout << "copy construct invoke!" << endl; }
	~HasPtrMem() { delete d; }
	int *d = NULL;
};

struct Copyable
{
public:
	Copyable() {
		p = new int(1);
		cout << "default con invoke!" << endl;
	};

	Copyable(const Copyable& ref) {
		p = new int();
		*p = *ref.p;
		cout << "copy con invoke!" << endl;
	};

	Copyable(Copyable&& s)
	{
		p = s.p;
		s.p = nullptr;
		cout << "move con invoke!!" << endl;
	}

	~Copyable() {
		delete p;
		cout << "destrcut invoke!" << endl;
	}

	int getPValue() { return *p; }
	int * p;
private:
	
};

Copyable ReturnValue()
{
	return Copyable();
}

void AcceptVal(Copyable ){}
void AcceptRef(const Copyable& ){}
void AcceptRvalueRef(Copyable&& s)
{
	Copyable news = std::move(s);
}

int main()
{
    //std::cout << "Hello World!\n"; 
	
	//3.3 右值引用
	//HasPtrMem a;
	//HasPtrMem b(a);

	//cout << "a.d =" << a.d << endl;
	//cout << "b.d =" << b.d << endl;

	// AcceptRvalueRef(ReturnValue());
	Copyable A;
	cout << hex << A.p << endl;
	Copyable B(A);
	cout << hex << B.p << endl;
	Copyable C(std::move(A));
	cout << hex << C.p << endl;

	// AcceptVal(ReturnValue());


	return 0;
}

