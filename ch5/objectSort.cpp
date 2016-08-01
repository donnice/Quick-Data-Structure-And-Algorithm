#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Person
{
private:
	string lastName;
	string firstName;
	int age;

public:
	Person(string last, string first, int a):
		lastName(last),firstName(first),age(a){}
	
	void displayPerson()
	{
		cout << " Last Name: " << lastName;
		cout << ", First Name: " << firstName;
		cout << ", Age: " << age << endl;
	}

	string getLast(){return lastName;}
};

class ArrayInOb
{
private:
	vector<Person*> v;			// vector of persons
	int nElems;
public:
	ArrayInOb(int max):nElems(0)
	{
		v.resize(max);			// resize the vector
	}

	void insert(string last, string first, int age)
	{
		v[nElems] = new Person(last,first,age);
		nElems++;
	}

	void display()
	{
		for(int j=0;j<nElems;j++)
			v[j]->displayPerson();
	}

	void insertionSort()
	{
		int in,out;

		for(out=1;out<nElems;out++)
		{	
			Person* temp = v[out];
			in = out;

			while(in>0 && v[in-1]->getLast() > temp-> getLast())
			{
				v[in] = v[in-1];
				--in;
			}
		}
	}
};

int main()
{
	return 0;
}
