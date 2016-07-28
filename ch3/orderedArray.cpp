// orderedArray
// page 82
// best part is insert

#include <iostream>
#include <vector>

using namespace std;

class OrdArray
{
private:
	
	vector<double> v;
	int nElems;

public:
	
	OrdArray(int max)
	{
		nElems = 0;
		v.resize(max);
	}

	int getSize(){return nElems;}

	int find(double searchKey)
	{
		int lowerBound = 0;
		int upperBound = nElems - 1;
		int curIn;
		
		while(true)
		{
			curIn = (lowerBound + upperBound)/2;
			if(v[curIn] == searchKey)
				return curIn;
			else if(lowerBound > upperBound)
				return nElems;
			else
			{
				if(v[curIn] < searchKey)
					lowerBound = curIn + 1;
				else
					upperBound = curIn - 1;
			}
		}
	}

	void insert(double value)
	{
		int j;
		for(j = 0; j < nElems; j++)
			if(v[j] > value)
				break;
		for(int k = nElems; k>j; k--)
			v[k] = v[k-1];
		v[j] = value;
		nElems++;
	}

	bool remove(double value)
	{
		int j = find(value);
		if(j==nElems)
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
		for(int j=0; j<nElems;j++)
			cout << v[j] << " ";
		cout << endl;
	}
};
