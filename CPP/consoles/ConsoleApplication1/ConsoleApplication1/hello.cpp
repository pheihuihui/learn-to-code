#include "stdafx.h"
#include "hello.h"
#include <iostream>

using namespace std;

MyClass::MyClass(int i) {
	times = i;
}

void MyClass::printHellos() {
	for (int i = 0; i < times; i++) {
		cout << "hello" << endl;
		cout << "hello" << endl;
		cout << "hello" << endl;
		cout << "hello" << endl;
		cout << "hello" << endl;
	}
}