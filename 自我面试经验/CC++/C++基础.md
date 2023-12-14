### 初始化列表

必须在初始化列表中初始化的三个成员变量

```C++ 
class A
{
public:
	A(int a1=0,int b)
		:a(a1)
		,b(b)
		,c(30)
	{}

private:
	int& a;
	const int b;
	B c;
};
class B
{
	int c;
public:
	B(int c)//提供带参数构造函数之后,B类编译器不会再有默认的构造函数生成
		:c(c)
	{}
};
```



#### 内联函数

> 1. 内联函数比普通函数多了关键字**inline**
>
> 2. 内联函数避免了函数调用的**开销**；普通函数有调用的开销
>
> 3. 普通函数在被调用的时候，需要**寻址（函数入口地址）**；内联函数不需要寻址。
>
> 4. 内联函数有一定的限制，内联函数体要求**代码简单**，不能包含复杂的结构控制语句；普通函数没有这个要求

在使用内联函数时，应注意如下几点：

1. 在内联函数内不允许用循环语句和开关语句。

如果内联函数有这些语句，则编译将该函数视同普通函数那样产生函数调用代码,递归函数是不能被用来做内联函数的。内联函数只适合于只有1～5行的小函数。对一个含有许多语句的大函数，函数调用和返回的开销相对来说微不足道，所以也没有必要用内联函数实现。

2. 内联函数的定义必须出现在内联函数第一次被调用之前。

#### 指针常量 常量指针

```C++
//const* 是常量指针，*const 是指针常量
int const *a; //a指针所指向的内存里的值不变，即（*a）不变
int *const a; //a指针所指向的内存地址不变，即a不变

1. const int a; //指的是a是一个常量，不允许修改。
2. const int a; //a指针所指向的内存里的值不变，即（a）不变
3. int const *a; //同const int *a;----常量的指针
4. int *const a; //a指针所指向的内存地址不变，即a不变-----指针常量,指针是一个常量,指向不可更改
5. const int const a; //都不变，即（a）不变，a也不变
```

#### const define的区别

const用于定义常量；而defifine用于定义宏，而宏也可以用于定义常量。都用于常量定义时，它们的区别有：

1. const生效于编译的阶段；defifine生效于预处理阶段。

2. const定义的常量，在C语言中是存储在内存中、需要额外的内存空间的；defifine定义的常量，运行时是直接的操作数，并不会存放在内存中。

3. const定义的常量是带类型的；defifine定义的常量不带类型。因此define定义的常量不利于类型检查。

#### new malloc区别

1. new是操作符，而malloc是函数。

2. new在调用的时候先分配内存，在调用构造函数，释放的时候调用析构函数；而malloc没有构造函数和析构函数。

3. malloc需要给定申请内存的大小，返回的指针需要强转；new会调用构造函数，不用指定内存的大小，返回指针不用强转。

4. new可以被重载；malloc不行

5. new分配内存更直接和安全

6. new发生错误抛出异常，malloc返回null

- malloc底层实现

当开辟的空间小于 128K 时，调用 brk（）函数；当开辟的空间大于 128K 时，调用mmap（）。

malloc采用的是**内存池**的管理方式，以减少内存碎片。先申请大块内存作为堆区，然后将堆区分为多个内存块。当用户申请内存时，直接从堆区分配一块合适的空闲快。

采用隐式链表将所有空闲块，每一个空闲块记录了一个未分配的、连续的内存地址。

* new底层实现：

关键字new在调用构造函数的时候实际上进行了如下的几个步骤：

1. 创建一个新的对象

2. 将构造函数的作用域赋值给这个新的对象（因此this指向了这个新的对象）

3. 执行构造函数中的代码（为这个新对象添加属性）

4. 返回新对象

#### 函数指针和类函数指针声明

```C++
#include<iostream>
using namespace std;

class Caculate
{
public:
	int Add(int x, int y)
	{
		return x + y;
	}
	int Sub(int x, int y)
	{
		return x - y;
	}
};
int main2()
{
	//声明类成员函数指针
	int (Caculate:: * Opt)(int, int);
	Caculate cal;
	int opcode = 0;
	cin >> opcode;
	if (opcode == 1)
		Opt = &(Caculate::Add);
	else
		Opt = &(Caculate::Sub);
	int a = 0, b = 0;
	cin >> a >> b;
	//Opt是成员函数指针,*Opt就是成员函数,使用类对象来调用成员函数
	int c = (cal.*Opt)(a, b);
	int res = (cal.*Opt)(a, b);
	cout << res << endl;
	return 0;
}


int Add(int x, int y)
{
	return x + y;
}
int Sub(int x, int y)
{
	return x - y;
}
//在 C/C++ 中，函数名表示函数的地址。当您在代码中使用函数名时，编译器它将自动转换为指向函数的指针，即函数指针。
int (*GetOperation(int opt))(int, int)
{
	if (opt == 1)
		return Add;
	else
		return Sub;
}
int main1()
{
	int opcode = 0;
	cin >> opcode;
	int a = 0, b = 0;
	cin >> a >> b;
	//返回函数指针
	int (*op)(int, int) = GetOperation(opcode);
	//用函数指针调用
	int res = op(a,b);
	cout << res << endl;
	return 0;
}
```

#### 静态变量 全局变量 局部变量的区别

##### 作用域

- 全局变量：全局作用域，可以通过extern作用于其他非定义的源文件。
- 局部变量：局部作用域，比如函数的参数，函数内的局部变量等等。
- 静态局部变量 ：局部作用域，只被初始化一次，直到程序结束。
- 静态全局变量 ：全局作用域+文件作用域，所以无法在其他文件中使用。

##### 存储位置

除了局部变量在栈上外，其他都在静态存储区。因为静态变量都在静态存储区，所以下次调用函数的时候还是能取到原来的值

##### 生命周期

局部变量在栈上，出了作用域就回收内存；而全局变量、静态全局变量、静态局部变量都在静态存储区，直到程序结束才会回收内存。

#### nullptr调用成员函数可以吗？为什么？

原因：因为在**编译时对象**就绑定了**函数地址**，和指针空不空没关系。pAn->breathe();编译的时候，函数的地址就和指针pAn绑定了；调用breath(*this), this就等于pAn。由于函数中没有需要解引用this的地方，所以函数运行不会出错，但是若用到this，因为this=nullptr，运行出错.

```C++
#include<iostream>
using namespace std;
class A
{
public:
	void print()
	{
		cout << "A::print()" << endl;
	}
};
int main()
{
	A* ptr=nullptr;
	ptr->print();//A::print()
	return 0;
}
```

