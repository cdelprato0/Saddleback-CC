#include <iostream>
#include "template7.h"

using namespace std;

int main()
{
	stackType<int> stack(50);
	int poppedInt;
	stack.push(23);
	stack.push(45);
	stack.push(38);

    stack.pop(poppedInt);
    stack.pop(poppedInt);
    stack.pop(poppedInt);


	stackType<float> floatStack;      // floatStack is object of class Stack<float>
	float poppedFloat;
    floatStack.push(1111.1);      // push 3 floats, pop 3 floats
    floatStack.push(2222.2);
    floatStack.push(3333.3);
    floatStack.pop(poppedFloat);
    floatStack.pop(poppedFloat);
    floatStack.pop(poppedFloat);

    stackType<long> longStack;       // longStack is object of class Stack<long>
	long poppedLong;
    longStack.push(123123123L);  // push 3 longs, pop 3 longs
    longStack.push(234234234L);
    longStack.push(345345345L);
    longStack.pop(poppedLong);
    longStack.pop(poppedLong);
    longStack.pop(poppedLong);
}
