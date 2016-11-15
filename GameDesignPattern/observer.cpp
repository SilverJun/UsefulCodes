#include <iostream>
#include <list>

class Observer {
public:
	virtual void OnNotify() = 0;
};

class Subject {
	std::list<Observer*> _observers;
public:
	void addObserver(Observer* observer)
	{
		_observers.push_back(observer);
	}
	void removeObserver(Observer* observer)
	{
		_observers.remove(observer);
	}

	void Notify()
	{
		for (auto& itor = _observers.begin(); itor != _observers.end(); itor++)
			(*itor)->OnNotify();
	}
};
