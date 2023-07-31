//ʵ���˶��󴴽��Ϳͻ��˴���Ľ���
//���ݴ���Ĳ���������ͬ���͵�ͼ�ζ��󡣿ͻ��˴���ͨ������ ShapeFactory::createShape() ����������ͼ�ζ���
// ������Ҫֱ��ʵ���� Circle �� Rectangle �ࡣ
//��������δ����Ӹ����ͼ������ʱ��ֻ��Ҫ�޸Ĺ����������Ҫ�޸Ŀͻ��˴��룬ʵ���˶��󴴽��Ϳͻ��˴���Ľ��
#include<iostream>
using namespace std;
class Shape
{
public:
	virtual void draw() = 0;
};
class Circle : public Shape
{
public:
	void draw() override
	{
		cout << "draw a circle" << endl;
	}
};
class Rectangle:public Shape
{
public:
	void draw() override
	{
		cout << "draw a Rectangle" << endl;
	}
};
class ShapeFactory
{
public:
	static Shape* createShape(const std::string& shapeType)
	{
		if (shapeType == "Circle")
			return new Circle();
		else if (shapeType == "Rectangle")
			return new Rectangle();
		else
			return nullptr;
	}
};
int main()
{
	Shape* circle = ShapeFactory::createShape("Circle");
	circle->draw();
	Shape* rectangle = ShapeFactory::createShape("Rectangle");
	rectangle->draw();

	return 0;
}