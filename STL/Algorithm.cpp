//
//File	- Algorithm.cpp
//Date	- 2016/11/14
//Desc	- STL Algorithm header Practice
//
//Created By SilverJun.
//

#include <iostream>
#include <algorithm>

#include <vector>
#include <string>

class MyClass
{
	std::string name;

public:
	MyClass(std::string name) : name(name) {}

	void DoSomething()
	{
		std::cout << "do something : " << name << std::endl;
	}
};

int main()
{
	std::vector<MyClass*> myClasses;
	myClasses.push_back(new MyClass("HoIK"));
	myClasses.push_back(new MyClass("Jwah"));
	myClasses.push_back(new MyClass("AnioneKing"));

	//use for_each like this
	std::for_each(myClasses.begin(), myClasses.end(), [](MyClass* object) {
		object->DoSomething();
	});

	//same as this
	for (auto itor = myClasses.begin(); itor != myClasses.end(); itor++)
	{
		(*itor)->DoSomething();
	}

	return 0;
}
