#include <iostream>
#include <vector>
using namespace std;

class StackX
{
private:
	int maxSize;
	vector<double> stackVect;
	int top;

public:
	
	StackX(int s):maxSize(s),top(-1)
	{
	// The reserve() method only allocates memory,
	// but leaves it uninitialized. It only affects capacity()
	// It only affects capacity(), but size() will be unchanged. 
		stackVect.reserve(maxSize);		
	}
	
	void push(double j)
	{
		stackVect[++top] = j;
	}

	double pop()
	{
		return stackVect[top--];
	}

	double peek()
	{
		return stackVect[top];
	}

	bool isEmpty()
	{
		return (top == -1);
	}

	bool isFull()
	{
		return (top == maxSize - 1);
	}
};

int main()
{
	StackX theStack(10);
	theStack.push(20);
	theStack.push(40);
	theStack.push(60);
	theStack.push(80);

	while(!theStack.isEmpty())
	{
		double value = theStack.pop();
		cout << value << " ";
	}
	cout << endl;
	
	return 0;
}
