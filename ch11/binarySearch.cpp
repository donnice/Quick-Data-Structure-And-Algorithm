// page 247
#include <iostream>
#include <vector>
using namespace std;

class ordArray
{
private:
	vector<double> v;
	int nElems;

public:
	ordArray(int max)
	{
		v.resize(max);
		nElems = 0;
	}

	int getSize()
	{ return nElems; }

	int find(double searchKey)
	{
		return recFind(searchKey, 0, nElems-1);
	}

	int recFind(double searchKey, int lowerBound, int upperBound)
	{
		int curIn;

		curIn = (lowerBound + upperBound)/2;
		if(v[curIn] == searchKey)
			return curIn;
		else if(lowerBound > upperBound)
			return nElems;
		else
		{
			if(v[curIn] > searchKey)
				return recFind(searchKey, lowerBound, curIn -1);
			else
				return recFind(searchKey, curIn+1, upperBound);
		}
	}

	void insert(double value)
	{
		int j;
		for(j=0; j<nElems;j++)
			if(v[j]>value)
				break;
		for(int k=nElems;k>j;k--)
			v[k] = v[k-1];
		v[j] = value;
		nElems++;
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
	return 0;
}
