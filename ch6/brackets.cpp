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

class BracketChecker
{
private:
	string input;

public:
	BracketChecker(string in):input(in){}

	void check()
	{
		int stackSize = input.length();
		StackX theStack(stackSize);
		bool isError = false;

		for(int j = 0; j < input.length(); j++)
		{
			char ch = input[j];
			switch(ch)
			{
				case '{':
				case '[':
				case '(':
					theStack.push(ch);
					break;

				case '}':
				case ']':
				case ')':
					if(!theStack.isEmpty())
					{	
						char chx = theStack.pop();
						if((ch == '}' && chx!='}') ||
						   (ch == ']' && chx!=']') ||
						   (ch == ')' && chx!='('))
						   {
								isError = true;
								cout << "Mismatched delimeter: "
								<< ch << " at " << j << endl;
						   }
					}
					else
					{
						isError = true;
						cout << "Misplaced delimiter:"
						<< ch << " at " << j << endl;
					}
					break;
				default:
					break;
			}
		}
		if(!theStack.isEmpty())
		{
			cout << "Missing right delimter" << endl;
		}
		else if(!isError)
		{
			cout << "OK" << endl;
		}
	}
};

int main()
{
	return 0;
}
