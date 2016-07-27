// page 68
#include <iostream>
#include <vector>
using namespace std;

class HighArray
{
private:
	vector<double> v;
	int nElems;
public:
	HighArray(){ nElems = 0; }

	HighArray(int max)
	{
		nElems = 0;
		v.resize(max);					// size the vector
	}

	bool find(double searchKey)
	{
		int j;
		for(j = 0; j < nElems; j++)
			if(v[j] == searchKey)
				return true;

		return false;
	}

	void insert(double value)
	{
		v[nElems] = value;
		nElems++;
	}

	bool remove(double value)
	{
		int j;
		for(j = 0; j < nElems; j++)
			if(value == v[j])
				break;
		if(j == nElems)
			return false;
		else
		{
			for(int k = j; k<nElems; k++)
				v[k] = v[k+1];
			nElems--;
			return true;
		}
	}

	void display()
	{
		for(int j = 0; j < nElems; j++)
			cout << v[j] << " ";
		cout << endl;
	}
};

int main()
{
	int a = 10;
	{
		int a = 20;
		cout << a << endl;
	}
	cout << a << endl;
	return 0;
}
