
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
//	int _a;// ����
// 	void fun(){
//		cout << "class A" << endl;
//		cout << "this=" << this << endl;
//
//	}
//};
//
//class B{
//	int _a;//˽��
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
////	A a; //struct ��Ĭ�ϳ�ԱΪ���е�
////	a.fun();
////	a._a = 10;
////
////	B b; //class ��Ĭ�ϳ�ԱΪ˽�е�
////	::fun1();
////	cout << sizeof(A)<<endl;
////}
//
//
//class Student{
//public:
//	int sid;
//	char name[1024];
//	// Ĭ�Ϲ��죺ֻ�ܴ���һ����һ�㽨���һ��ȫȱʡ
//	// 1��������Ĭ������
//	// 2����ʾ������޲ι���
//	// 3��ȫȱʡ���캯��
//
//	// ֻ�е�����û�ж����κι��캯��ʱ���������Ż��Զ�����һ���޲ι��죬��������Ѿ�������һ�����캯��
//	// �������������Զ����ɣ���������û����ʽ�����޲ι���
//	//Student(){}
//	Student(int sid = 123){ // ע���ֹ���ó�ͻ
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
//		cout << "û������thisָ��,�Ͳ��ý�����" << endl;
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
//	// �˴���thisû�н�����
//	// �ײ� fun1(this)
//	(*ps).fun1(); //fun1(&(*ps)) һ���������У���Ϊû�н����ã���Ȼ��Ϊ�β�this���ݽ�ȥ
//	ps->fun1(); // ��Ȼ�˴�thisָ��Ϊ�գ�����thisû�н��н����ã�������������
//	//ps->show(); // ��ʱthisָ����һ����ָ��������쳣
//	//ps->sid = 1020;
//
//	Student d3();// ����һ�����������ǵ����޲ι���
//	Student s1(1234);
//	cout << s1.sid << endl;
//
//	Student D(3.0F);
//}
//class AA{
//public:
//	AA(int a, int b , int c){ 
//		// ���Զ��������ж����࣬������Զ������͹��죬�͵���Ĭ�Ϲ��죬���û���Զ��幹��͵���ϵͳ�����Ĭ�Ϲ��캯��
//	}
//	// ί�й��죬ͬ��֮�еĲ�ͬ����֮��ĵ���
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

// int : int ������һ���������ͣ������������������


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