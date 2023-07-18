#include<iostream>
#include<vector>
using namespace std;

class Observer;
class Subject
{
//private:
protected:
	vector<Observer*> observers;
public:
	void addObserver(Observer* obs)
	{
		observers.push_back(obs);
	}
	void removeObserver(Observer* obs)
	{
		auto it = find(observers.begin(),observers.end(),obs);
		if (it != observers.end())
			observers.erase(it);
	}
	void notifyObserver()
	{
		for (auto obs : observers)
		{
			obs->update();
		}
	}
	//设置为纯虚函数
	virtual int getState() const = 0;
};
class Observer
{
public:
	virtual void update() = 0;
};
class ConcreteSubject : public Subject
{
private:
	int _state;
public:
	void setState(int state)
	{
		_state = state;
		notifyObserver();
	}
	int getState() const override /*不让重写*/
	{
		return _state;
	}
};
class ConcreteObserver : public Observer
{
private:
	ConcreteSubject* subject;
public:
	ConcreteObserver(ConcreteSubject* sub) :subject(sub) {}
	void update()override
	{
		int state = subject->getState();
		std::cout << "Observer: Received state update. New state is " << state << std::endl;
	}
};
int main() {
	ConcreteSubject subject;

	ConcreteObserver observer1(&subject);
	ConcreteObserver observer2(&subject);

	subject.addObserver(&observer1);
	subject.addObserver(&observer2);

	subject.setState(123);

	subject.removeObserver(&observer1);

	subject.setState(456);

	return 0;
}


