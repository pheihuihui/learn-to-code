#pragma once

class MyClass {
public:
	MyClass(int i);
	~MyClass();
	void printHellos();

private:
	int times;
};


//Note_201806100112: .h file should be put in the "header files" folder, or there would be countless problems occurring.