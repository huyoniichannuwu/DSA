#pragma once
#include <iostream>
#include<math.h>

using namespace std;

class element
{
private:
	int data;
	element* pointer;
public:
	element();
	element(int);
	~element();

	//Get/set method
	int getData() { return data; }
	void setData(int value) { this->data = value; }

	element* getPointer() { return pointer; }
	void setPointer(element* value) { this->pointer = value;}

	
protected:
};

