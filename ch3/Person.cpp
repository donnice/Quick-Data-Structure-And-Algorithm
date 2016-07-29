// page 87
#include <iostream>
#include <string>

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
		cout << "Last name:" << lastName;
		cout << ", First name:" << firstName;
		cout << ", Age:" << age << endl;
	}

	string getLast(){return lastName;}
};
