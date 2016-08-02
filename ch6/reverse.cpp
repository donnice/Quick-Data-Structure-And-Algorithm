#include <iostream>
#include <string>
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

class Reverser
{
private:
	string input;
	string output;

public:
	Reverser(string in):input(in){}

	string doRev()
	{
		int stackSize = input.length();		// get max stack size
		StackX theStack(stackSize);			// make stack

		for(int j = 0; j < input.length(); j++)
		{
			char ch = input[j];
			theStack.push(ch);
		}
		output = "";
		while(!theStack.isEmpty())
		{
			char ch = theStack.pop();
			output += ch;
		}

		return output;
	}
};

int main()
{
	string output;
	string input = "ABCDEFG";
	
	Reverser theReverser(input);
	output = theReverser.doRev();

	cout << output << endl;

	return 0;
}
