// ConsoleApplication1.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
using namespace test;
int main()
{
	MyClass* my = new MyClass(4);
	my->printHellos();
	my->~MyClass();
    return 0;
}

