#include <iostream>
#include <vector>
using namespace std;
// page 252

class StackX
{
private:
	int maxSize;
	vector<int> stackVect;
	int top;
public:
	StackX(int s):maxSize(s),top(-1)
	{ stackVect.resize(maxSize);}

	void push(int p)
	{ stackVect[++top] = p; }

	int pop()
	{ return stackVect[top--];}

	int peek()
	{ return stackVect[top]; }

	bool isEmpty()
	{ return (top == -1); }
};

int stackTriangle(int);

int main()
{
	int theNumber = 10;
	int theAnswer;

	theAnswer = stackTriangle(theNumber);
	cout << "Triangle=" << theAnswer << endl;

	return 0;
}

int stackTriangle(int number)
{
	StackX theStack(10000);
	int answer = 0;

	while(number > 0)
	{
		theStack.push(number);
		--number;
	}

	while(!theStack.isEmpty())
	{
		int newN = theStack.pop();
		answer += newN;
	}
	return answer;
}
