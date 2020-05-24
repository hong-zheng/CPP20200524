
//struct People{
//	int id;
//	char name[1024];
//};
//int mains(void){
//	cout << sizeof(People);
//
//	system("pause");
//	return 0;
//}
//void test(){
//	People p;
//	p.id = 1;
//}
//struct A{
//	int _a;// 公有
// 	void fun(){
//		cout << "class A" << endl;
//		cout << "this=" << this << endl;
//
//	}
//};
//
//class B{
//	int _a;//私有
//	void fun(){ /// void fun(B* const this)
//		cout << "class B" << endl;
//		cout << "this=" << this << endl;
//	}
//	void fun1();
//};
//
//void fun1(){
//	cout << "global fun1()" << endl;
//}
//void B::fun1(){
//	cout << "B::fun1()" << endl;
//}
////void testclass(){
////	A a; //struct 的默认成员为公有的
////	a.fun();
////	a._a = 10;
////
////	B b; //class 的默认成员为私有的
////	::fun1();
////	cout << sizeof(A)<<endl;
////}
//
//
//class Student{
//public:
//	int sid;
//	char name[1024];
//	// 默认构造：只能存在一个，一般建议给一个全缺省
//	// 1、编译器默认生成
//	// 2、显示定义的无参构造
//	// 3、全缺省构造函数
//
//	// 只有当类中没有定义任何构造函数时，编译器才会自动生成一个无参构造，如果类中已经定义了一个构造函数
//	// 编译器不会再自动生成，即便类中没有显式定义无参构造
//	//Student(){}
//	Student(int sid = 123){ // 注意防止调用冲突
//		this->sid = sid;
//	}
//	Student(float f){
//
//	}
//	//Student(int sid){
//	//	this->sid = sid;
//	//}
//
//	void show(){
//		cout << "student=> " << this->sid<<":"<<this->name<<endl;
//	}
//	void fun1(){
//		cout << "没有引用this指针,就不用解引用" << endl;
//	}
//};
//
//void testStudent(){
//	Student s;
//	s.sid = 102;
//	strcpy(s.name, "zhenghong");
//	//s.show();
//
//	Student* ps = &s;
//	ps->show();
//	ps = nullptr;
//
//	// 此处的this没有解引用
//	// 底层 fun1(this)
//	(*ps).fun1(); //fun1(&(*ps)) 一样可以运行，因为没有解引用，仍然作为形参this传递进去
//	ps->fun1(); // 虽然此处this指针为空，但是this没有进行解引用，程序正常运行
//	//ps->show(); // 此时this指针是一个空指针解引用异常
//	//ps->sid = 1020;
//
//	Student d3();// 声明一个函数，不是调用无参构造
//	Student s1(1234);
//	cout << s1.sid << endl;
//
//	Student D(3.0F);
//}
//class AA{
//public:
//	AA(int a, int b , int c){ 
//		// 在自定义类型中定义类，如果有自定义类型构造，就调用默认构造，如果没有自定义构造就调用系统本身的默认构造函数
//	}
//	// 委托构造，同类之中的不同构造之间的调用
//};

//class BB{
//private:
//	int _id;
//	int _num;
//	AA _aa;
//};
//
//void test(){
//	//BB b; 
//}
//int main(void){
//	//test();
//
//	int a = 10;
//	int* const pa = &a;
//	int b = 20;
//	*pa = b;
//	cout << "a=" << a << endl;
//
//	const int* paa = &a;
//	paa = &b;
//	cout << "a=" << a << endl;
//	system("pause");
//	return 0;
//}

// int : int 类型是一种内置类型，即语言自身定义的类型


#define _CRT_SECURE_NO_WARNINGS	1
#include <iostream>
#include <string.h>
using namespace std;
int main(void){
	cerr << "error" << endl;
	clog << ".log" << endl;

	(cout << "zhenghong") << "zai zhe er deng zhe ni " << endl;
	system("pause");
	return 0;
}