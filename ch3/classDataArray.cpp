// classDataArray.cpp, page 88
// data items as class objects
#include <iostream>
#include <string>
#include <vector>
#include "Person.cpp"

using namespace std;

class classDataArray
{
private:
	vector<Person*> v;
	int nElems;
public:
	classDataArray(int max):nElems(0){v.resize(max);}

	~classDataArray()
	{
		for(int j = 0; j < nElems; j++)
			delete v[j];
	}
	
	Person* find(string searchName)
	{
		int j;
		for(j = 0; j < nElems; j++)
			if(v[j]->getLast() == searchName)
				break;
		if(j == nElems)
			return NULL;
		else
			return v[j];
	}

	void insert(string last, string first, int age)
	{
		v[nElems] = new Person(last, first, age);
		nElems++;
	}

	bool remove(string searchName)
	{
		int j;
		for(j=0; j<nElems; j++)
			if(v[j]->getLast() == searchName)
				break;
		if(j==nElems)
			return false;
		else
		{
			delete v[j];
			for(int k=j; k <nElems; k++)
				v[k] = v[k+1];
			nElems--;
			return true;
		}
	}	// end of remove

	void displayA()
	{
		for(int j=0; j<nElems; j++)
			v[j]->displayPerson();
	}
};

int main()
{
	Person("Shujie","CHEN",24);
	return 0;
}
