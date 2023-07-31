#include<iostream>
#include<vector>
using namespace std;
//�۲���ģʽ��Observer Pattern������Ҫ������ʵ�ֶ���֮���һ�Զ�������ϵ����һ�������״̬�����仯ʱ�������������Ķ��󶼻�õ�֪ͨ���Զ����¡�
//
//��Ҫ�������£�
//
//1. ����۲��ߺͱ��۲��ߣ��۲���ģʽ���۲��ߺͱ��۲��߽��ʹ����֮��Ĺ�ϵ��ɢ��
//	 �۲��߲���Ҫ֪�����۲��ߵľ���ϸ�ڣ�ֻ��Ҫ��ע���۲��ߵ�״̬�仯��
//
//2. ֧�ֹ㲥֪ͨ�������۲��ߵ�״̬�����ı�ʱ������Ҫ�ֶ�֪ͨÿ���۲��ߣ������ɱ��۲����Զ�֪ͨ����ע��Ĺ۲��ߡ�
//   ��������ʵ��һ��֪ͨ������۲���ͬʱ��Ӧ��Ч���������ڹ㲥֪ͨ��
//
//3. ʵ���¼������۲���ģʽ��������ʵ���¼�����ͷ��� - ����ģ�͡���ĳ���¼�����ʱ�����۲��߿��Գ䵱�¼��ķ����ߣ�
//   ���۲��߿�����Ϊ�����ߣ�ͨ��ע�ᶩ�Ĺ�ϵ�������¼�֪ͨ��������Ӧ��
//
//4. �༶�������۲���ģʽ����֧�ֶ༶��������һ���۲��ߵ�״̬�ı�Ҳ���ܴ��������۲��ߵ�״̬�ı䣬
//   �Ӷ�ʵ��һϵ�д�������Ӧ��
//
//�ܵ���˵���۲���ģʽ������������һ�ַǳ����õ����ģʽ�����ٽ�������ϡ���ά���Ϳ���չ����ơ�
//ͨ��ʹ�ù۲���ģʽ�����ǿ��Ը��õش������֮���������ϵ���Ӷ�ʹ���������������ά����
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
	//����Ϊ���麯��
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
	int getState() const override /*������д*/
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


