#include "hello.h"
#include "stdafx.h"
#include <iostream>

using namespace std;


namespace test {
	class MyClass {
	public:
		MyClass(int i) {
			times = i;
		}
		~MyClass() {

		}
		void printHellos() {
			for (int i = 0; i < times; i++) {
				cout << "hello" << endl;
			}
		}

	private:
		int times;
	};
}