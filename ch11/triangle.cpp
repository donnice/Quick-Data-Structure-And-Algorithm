#include <iostream>
// page 235

using namespace std;

int triangle(int);

int main()
{
//	int triangle(int);
	for(int i = 1; i < 10; i++)
	{
		int theAnswer = triangle(i);
		cout << "Triangle=" << theAnswer << endl;
	}
	return 0;
}

int triangle(int n)
{
	if(n == 1)
		return 1;
	else
		return (n + triangle(n-1));
}
