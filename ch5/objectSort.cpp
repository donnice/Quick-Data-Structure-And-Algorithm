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

};
