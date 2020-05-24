#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class A{
public:
	~A(){
		cout << "~A()"<< endl;
	}
};

//Date1 fun(){
//	Date1 d;
//	return d;
//}
void tests(){
	//Date1 d(fun()); // 两次拷贝构造，第一次是returnd,第二次d(fun())
	//Date1 d;
	//Date1 copy(d);
	//// 优化：直接调用析构函数创建copy2，匿名对象具有常性，因此形参必须是const
	//// 不优化：调用析构创建匿名对象，+拷贝
	//Date1 copy2(Date1(2020,5,23));
}
void testvolatile(){
	//const int a = 10;
	//int* pa = (int*)&a;
	//*pa = 20;
	//cout << a << endl; //10 :此处的a不是从内存去读，而是从寄存器或者缓存去读，原因是sonst，以为不会发生改变，就直接放在缓存或者寄存器
	//cout << *pa << endl; //20

	const volatile int a = 10; // 此处就表示禁止优化，只能从内存读取
	int* pa = (int*)&a;
	*pa = 20;
	cout << a << endl; // 20:
	cout << *pa << endl; //20
}


class String{
public:
	String(const char* str = "hong"){
		str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}

	// 有资源，必须显式定义拷贝构造，完成深拷贝，否则拷贝构造会出错

	~String(){
		if (_str){
			free(_str);
			_str = nullptr;
		}
	}
private:
	char* _str;
};

//void test1(){
//	String s("123");
//	String copy(s);// 编译器生成的默认拷贝构造函数
//}




class Date1{
public:
	Date1(int y = 1, int m = 1, int d = 1){
		_year = y;
		_month = m;
		_day = d;
	}
	// 拷贝构造，构造函数的一种重载形式，也是在创建对象时自动调用
	// 调用场景：用一个已经存在得对象创建一个新得对象
	// 创建新的对象和之前得对象内容相同
	// 此处如果传递Date1类型，会存在无穷的递归拷贝构造
	// 编译器默认生成的拷贝未字节拷贝，即浅拷贝，只拷贝对象模型中的内容，不拷贝资源
	//Date1(const Date1& d){
	//	_year = d._year;
	//	_month = d._month;
	//	_day = d._day;
	//}

	// 析构函数：清理资源，不是销毁对象，在对象生命周期结束时，编译器自动调用
	// 如果没有资源需要清理，可以不用显式写出析构函数，调用默认析构函数即可
	~Date1(){
		// 自动调用自定义类型的析构函数，完成自定义类型成员的资源清理工作
		cout << "~Date1()" << endl;
	}

	bool isEqual(const Date1& d){
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}
	// 运算符重载，主要是为了增强代码的可读性，使用方法和普通方法一样
	// 函数名特殊，定义和使用方式和普通函数一样
	// 返回值： operator + 需要重载的运算符(参数列表){}
	// 运算符重载函数如果是成员函数，则参数的个数比运算符需要的个数少一个
	// 编译器会传入 this 作为第一个参数
	// 底层 bool operator==(Date1* const d1 , const Date1& d)
	// this 指针始终占用运算符操作数得第一个位置
	bool operator==(const Date1& d){
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}

	// 赋值运算符重载
	// d = d1
	// 赋值运算符重载函数：修改对象得内容，不是去修改创建新的对象
	//void operator=(const Date1& d){
	//	_year = d._year;
	//	_month = d._month;
	//	_day = d._day;
	//	cout << "operator=(const Date1&ｄ)"<< endl;
	//}

	// 如果不写，编译器也会自动生成
	// 默认生成的也是一个字节拷贝，浅拷贝，
	// 如果当前类中有资源，则必须显式定义赋值运算符重载函数，完成深拷贝
	Date1& operator=(const Date1& d){
		if (this != &d){
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		cout << "operator=(const Date1&ｄ)" << endl;
		return *this;// 返回当前调用函数本身,this生命周期肯定大于函数生命周期本身
	}

//private:
	int _year;
	int _month;
	int _day;
	A _a;
};

// 自定义类型输出
//ostream& operator << (ostream& _cout, const Date1& date){
//	_cout << date._year << " " << date._month << " " << date._day << endl;
//	return _cout;
//}
int maisn(void){
	Date1 d(2020, 5, 23);
// 调用拷贝构造，d3不存在，用d创建d3对象，所以调用拷贝构造，不是赋值运算符
	// 如果对象都存在，调用赋值运算符重载，如果左边对象不存在，调用拷贝构造
	Date1 d3 = d;
	//cout << d << endl;
	Date1 d2(d);
	d.operator==(d2); // 等价于d == d2
	//testvolatile();
	//
	//test1();
	system("pause");
	return 0;
}
//class A{
//public:
//	~A(){}
//
//};
//class Date1{
//public:
//	Date1(int y = 1, int m = 1, int d = 1){
//		_year = y;
//		_month = m;
//		_day = d;
//	}
//	~Date1(){
//		free(_array); // 这种情况需要销毁
//		cout << "~Date1()"<< endl;
//	}
//	// 拷贝构造，构造函数一种重载形式，也是在创建对象时调用
//	// 调用场景：用一个已经存在的对象去 创建一个新的对象，创建的新对象和当前对象内容相同
//	// 匿名对象拷贝，匿名对象具有常性，需要加const,否则编译不通过
//	// 类型必须是引用，否则会引发无穷递归，不支持值传递
//	// 编译器默认生成的拷贝构造为字节拷贝，浅拷贝
//	// 浅拷贝：只拷贝对象模型中的内容，不拷贝资源
//	// 此处的资源表示：不存在当前对象内的都算资源：例如，堆，管道等等
//	// 赋值运算符必须要两边都存在，否则是拷贝构造 Date1 d= d0 ;// 此处就是拷贝构造，创建对象，内容和d0一样
//	Date1(const Date1& d){
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//
//	bool isEqual(const Date1& d){
//		return _year == d._year
//			&& _month == d._month
//			&& _day == d._day ;
//	}
//
//	// 运算符重载
//	// 已经存在的运算符可以重载
//	// 在自定义类型中，可以实现运算符重载 ， 目的是增强可读性
//	// 运算符重载函数，函数名特殊，定义和使用方式和普通函数一样
//	// 返回值 + operator + 需要重载的运算符 + （参数列表）+ 函数体
//	// 不能通过链接其他符号来创建新的操作符
//	// 重载操作符必须有一个类类型或者枚举类型的操作数
//	// 运算符重载函数如果是成员函数，则参数的个数比运算符需要的个数少一个，这里编译器会传入this指针作为第一个参数
//	// 全局的运算符重载，参数个数和运算符需要的个数一致
//	bool operator == (const Date1& d){
//		return _year == d._year
//			&& _month == d._month
//			&& _day == d._day;
//	}
//	// 连续赋值从右向左
//	// 连续赋值就要有返回类型，直接返回引用
//	// 不写编译器也会自动生成
//	// 如果不写，编译器自动生成的是字节拷贝，即浅拷贝
//	// 如果当前类中有资源，则必须显示定义赋值运算符重载，完成深拷贝
//	// 修改已经存在得对象
//
//	Date1& operator=(const Date1& d){
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//		// 返回当前调用此函数对象本身，this周期肯定大于函数调用本身
//		return *this;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//	int* _array; // 堆上开辟，非栈上，指针指向很大的空间，没有存放在对象当中，此时在西沟函数中就要调用free()清理资源
//};
//// this 指针始终占用运算符操作数得第一个位置，对位置敏感的运算符特别注意：“-”“、”等等
////stream& operator << (ostream& _cout , const )
//void test(){
//	Date1 copy(Date1());
//	//临时对象只能用const
//	// 优化：直接调用
//	Date1 copy2(Date1(2020.5,20)); 
//}
//// 如果有资源必须显式定义拷贝构造
//// 完成深拷贝
//class String{
//public:
//private:
//
//};
//int main(void){
//	volatile int i = 10;
//	const int j = 10;// 因为是缓存，就不去内存读取，只在缓冲读取，只有加上volatile才会去内存读取
//	// 不能从寄存器里面读取，有可能会变
//	const volatile int k = 10;
//	//test();
//	cout << "end"<< endl;
//	system("pause");
//	return 0;
//}





/*
class Date{
public:
	Date(int year = 1, int month = 1, int day = 1){
		if (year > 0 && month > 0 && month < 13
			&& day > 0 && day < getMonthDay(year, month)){
			_year = year;
			_month = month;
			_day = day;
		}
		else{
			cout << "日期不合法" << endl;
			cout << "重置为默认值: 2000-1-1" << endl;
			_year = 2000;
			_month = 1;
			_day = 1;
		}
	}
	int getMonthDay(int year, int month){
		// 静态变量，延长生命周期，只初始化一次
		static int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int day = days[month];
		if (month == 2 && ((year%400 == 0)||(year%4==0 &&year%100 != 0))){
			++day;
		}
		return day;
	}
	Date& operator+=(int day){
		if (day < 0){
			return *this -= -day;
		}

		// 需要考虑进位，月 和 年 的进位
		_day += day;
		while (_day > getMonthDay(_year, _month)){
			// 判断日期是否溢出
			_day > getMonthDay(_year, _month);
			// 减去当月的天数，月份进位
			_day -= getMonthDay(_year, _month);
			++_month;

			// 判断月份是否溢出
			if (_month == 13){
				// 进位到下一年的1月
				_month = 1;
				_year++;
			}
		}
		return *this;
	}

	// 前置++:++d:先加加再返回
	Date& operator++(){
		*this += 1;
		//(*this).operator+=(1);
		return *this;
	}
	// 后置++:d++:返回的是加之前的值
	Date operator++(int){ // int 为标识符,int标志，单目运算符
		// 为成员函数，无需显式传参
		// int 形参不是真正的参数，只是一个标记参数，编译器看到这样的定义，
		// 通过语法树收索，可以解释为后置+
		
		// 保存加之前得值，用于返回
		Date ret(*this);
		// ++ 
		*this += 1;
		// 返回++之前的值
		return ret;
	}
	void printD(){
     	cout << _year << " " << _month << " " << _day << endl;
	}

	// 拷贝构造函数
	Date(const Date& d){
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	// 赋值运算符重载
	Date& operator=(const Date& d){
		_year = d._year;
		_month = d._month;
		_day = d._day;
		return *this;
	}
	~Date(){
		cout << "~Date()" << endl;
	}


	Date& operator -=(int day){
		if (day < 0){
			return *this += -day;
		}
		_day -= day; 
		// 判断_day是否为负值或者0,退位
		while (_day <= 0){
			// 考虑月份是否为负值或者0
			--_month;
			if (_month == 0){
				_month = 12;
				//年份退位
				--_year;
			}
			_day += getMonthDay(_year, _month);
		}
		return *this;
 	}

	Date& operator --(){
		*this -= 1;
		return *this;
	}
	Date operator --(int){
		Date ret(*this); // 执行拷贝构造
		// 等价于 Date ret = *this;
		*this -= 1;
		return ret;
	}

	// 加法和减法不能修改操作数得内容
	// 日期 + 天数
	Date operator+(int day){
		Date ret(*this);
		ret += day;
		return ret;
	}

	Date operator-(int day){
		Date ret(*this);
		ret -= day;
		return ret;
	}

	// > 运算符重载
	bool operator>(const Date& d){
		if (_year >= d._year){
			if (_year == d._year){
				if (_month >= d._month){
					if (_month == d._month){
						if (_day > d._day){
							return true;
						}
						return false;
					}
					return true;
				}
				else{
					return false;
				}
			}
			return true;
		}
		else{
			return false;
		}
	}
	
	bool operator ==(const Date& date){
		if ( _year == date._year
			&& _month == date._month
			&& _day == date._day){
			return true;
		}
		return false;
	}

	bool operator != (const Date& date){
		if (_year != date._year)
			return true;
		else if (_year == date._year){
			if (_month != date._month){
				return true;
			}
			else{

			}
		}
	}

	bool operator>=(const Date& d){
		return *this > d || *this == d;
	}

	bool isLeap(const int year){
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
			return true;
		return false;
	}
	int operator-(const Date& d){
		// 2020 5 24
		// 1998 9 21
		// 代码能复用尽量复用
		Date d1(*this);
		Date d2(d);
		/// d1 - d2
		int num = 0;
		if (d1 > d2){
			while (d1 > d2){
				--d1;
				++num;
			}
			return num;
		}
		else{
			// d1 < d2
			//while (d1 < d2){
			//	++d1;
			//	++num;
			//}
			//return -num;
		}
		return 0;
	}

	// const 对象就会调用const函数
	void printD() const // void printD(const Date& const this)
	{// const 内部，不能修改成员变量的值
		// 此时指向和内容都不能变
	}

	// 取地址运算符重载函数:opertor&
	// 一般不会重写
	// 除非在里面骚操作
	Date* operator&(){
		return this;
	}
	const Date* operator&() const{
		return this; // 因为整的一个const,所以返回值也要为const
	}
private:
	int _year;
	int _month;
	int _day;
};

void test(){
	Date a(2020, 3, 4);
	const Date b(a);
	a.printD();// 调用非const成员函数，此时是可读可写的对象，非const对象可以调用const成员函数，原因在于读写权限没有被放大
	b.printD(); // 调用const成员函数,(只读)，const对象，不能调用非const成员函数，原因是读写权限不可被放大
	Date d(2020, 5, 1);
	d.printD();
	d += 20;
	d.printD();
	d += 20;
	d.printD();
	Date d2(2020, 12, 6);
	d2.printD();
	d2 += 3650;
	d2.printD();
	d2.operator++(0);
	d2.printD();

}

class Date2{
	Date2(int  y =1 , int m =1 , int d = 1)
		// 初始化
	:_year(y)
	,_month(m)
	,_day(d)
	,_a(d) // 引用成员和const成员必须在定义的时候进行初始化，然而这种定义就是在构造函数的参数列表中称为变量的定义
	,_b(d){
		// 没有默认构造的自定义函数，必须初始化列表中进行初始化
		// 其他成员可以不进行显式初始化
// 赋值
		//_year = y;
		//_month = m;
		//_day = d;
	}


	// 此处成员变量为声明，不是定义的位置
private:
	int _year;
	int _month;
	int _day;
	int& _a; // 引用和变量在定义的时候必须初始化（初始化列表中）
	const int _b;
};


int main(void){
	//test();
	system("pause");
	return 0;
}

*/

//class Date{
//public:
//	// 判断year年是否为闰年
//	bool isLeap(int year){
//		if ( year %400 == 0
//			|| (year % 4 ==0 && year % 100 != 0)){
//			return true;
//		}
//		return false;
//	}
//	// 获取当年的当前月的天数
//	int getMonthDay(int year, int month){
//		// 定义静态变量，只初始化一次
//		static int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//		int day = days[month];
//		if (2 == month && isLeap(year)){
//			day += 1;
//		}
//		return day;
//	}
//	// 全缺省构造函数
//	Date(int year = 1900 , int month = 1 , int day = 1){
//		if (year > 0 
//			&& (month>0 && month <13)
//			&& (day > 0 && day <= getMonthDay(year,month))){
//			_year = year;
//			_month = month;
//			_day = day;
//		}
//		else{
//			cout << "输入日期有误" << endl;
//			cout << "重置日期为 2020-01-01" << endl;
//			_year = 2020;
//			_month = 1;
//			_day = 1;
//		}
//	}
//
//	// 拷贝构造函数
//	// d2(d1)
//	// 必须传引用参数，否则会引起无穷递归
//	// 其使用情况就是创建一个与d一致得实例
//	// 如果不显式写出，系统会调用默认拷贝构造，但是不拷贝资源，为字节拷贝（浅拷贝）
//	Date(const Date& d){
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//
//	// 赋值运算符重载
//	// d2 = d3 ->d2.operator=(&d2,d3);
//	Date& operator=(const Date& d){
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//		return *this;
//	}
//
//	// 析构函数，在对象销毁之前释放资源
//	~Date(){
//		//cout << "~Date() : this: " << this << endl;
//		//printDate();
//	}
//
//	// 日期+=天数
//	Date& operator+=(int day){
//		if (day < 0){
//			*this -= -day;
//			return *this;
//		}
//		_day += day;
//		// 2020 5 24
//		//        45
//		// 2020 5 69
//		// 2020 7 8
//		while (_day >= getMonthDay(_year, _month)){
//			_day -= getMonthDay(_year, _month);
//			_month++;
//			if (_month == 13){
//				_month = 1;
//				_year += 1;
//			}
//		}
//		return *this;
//	}
//	// 打印日期
//	void printDate() const{
//		cout << "year: " << _year << " month: " << _month << " day: " << _day << endl;
//		cout << endl;
//	}
//
//	//日期 + 天数
//	Date operator + (int day){
//		Date ret(*this);
//		ret += day;
//		return ret;
//	}
//	// 日期-=天数
//	// 2020 5 24
//	//        78
//	//        -54  => _day
//	//
//	// 2020 4 54
//	// 2020 3 85
//	//        78
//	//        
//	Date& operator-=(int day){
//		if (day < 0){
//			*this += -day;
//			return *this;
//		}
//		_day -= day; // -54
//		while (_day<=0){
//			_month--;
//			if (_month == 0){
//				_month = 12;
//				_year -= 1;
//			}
//			_day += getMonthDay(_year, _month);
//		}
//		return *this;
//	}
//	// 日期-天数
//	Date operator-(int day){
//		Date ret(*this);
//		ret -= day;
//		return ret;
//	}
//
//	// 前置++
//	Date& operator++(){
//		*this += 1;
//		return *this;
//	}
//	// 后置++
//	Date operator++(int){
//		Date ret(*this);
//		*this += 1;
//		return ret;
//	}
//	// 后置--
//	Date operator--(int){
//		Date ret(*this);
//		*this -= 1;
//		return ret;
//	}
//	// 前置--
//	Date& operator--(){
//		*this -= 1;
//		return *this;
//	}
//
//	// == 运算符重载
//	bool operator==(const Date& d){
//		if ( _year == d._year
//			&& _month == d._month
//			&& _day == d._day)
//			return true;
//		return false;
//	}
//	// > 运算符重载
//	bool operator>(const Date& d){
//		if (_year > d._year){
//			return true;
//		}
//		else if (_year == d._year){
//			if (_month > d._month){
//				return true;
//			}
//			else if (_month == d._month){
//				if (_day > d._day)
//					return true;
//			}
//		}
//		return false;
//	}
//
//	// >= 运算符重载
//	inline bool operator>=(const Date & d){
//		return (*this > d) || (*this == d);
//	}
//
//	// < 运算符重载
//	bool operator < (const Date& d){
//		return !(*this>=d);
//	}
//
//	//<= 运算符重载
//	bool operator <= (const Date& d){
//		return *this < d || *this == d;
//	}
//	// != 运算符重载
//	bool operator != (const Date& d){
//		return !(*this == d);
//	}
//	// 日期 - 日期 返回天数
//	int operator-(const Date& d){
//		if (*this == d) return 0;
//		int num = 0;
//		if (*this < d){
//			while (*this < d){
//				++num;
//				(*this)++;
//			}
//			cout << "-num" << endl;
//			num = -num;
//		}
//		else{
//			Date tmp(d);
//			while (*this > tmp){
//				++num;
//				tmp++;
//			}
//		}
//		return num;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};



class Date{
public:
	Date(int year = 1, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{
		//判断日期是否合法
		if (year > 0 && month > 0 && month < 13
			&& day > 0 && day <= getMonthDay(year, month))
		{
			_year = year;
			_month = month;
			_day = day;
		}
		else
		{
			cout << "日期不合法： " << year << "-" << month << "-" << day << endl;
			cout << "重置为默认值： 2000-1-1" << endl;
			_year = 2000;
			_month = 1;
			_day = 1;
		}

	}

	int getMonthDay(int year, int month)
	{
		static int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int day = days[month];
		//如果是2月且为闰年，+1
		if (month == 2
			&& (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)))
			++day;
		return day;
	}
	// a += b
	Date& operator+=(int day)
	{
		// a += -b  --> a -= b
		if (day < 0)
		return *this -= -day;

		//2020.5.1  + 20  --> 2020.5.21
		//2020.5.21 + 20 --> 2020.5.41 --> 进位 --> -31 -->月份进位 --> 2020.6.10
		//2020.12.6 + 90 --> 2020.12.96 --> 进位 --> -31 -->月份进位 --> 2020.13.65 -->年进位
		// --> 2021.1.65--> --> 进位 --> -31 -->月份进位 --> 2021.2.34 --> --> 进位 --> -28 -->月份进位 --> 2021.3.6
		_day += day;
		//判断日期是否溢出,溢出需要进位
		while (_day > getMonthDay(_year, _month))
		{
			//减去当月的天数，月份进位
			_day -= getMonthDay(_year, _month);
			++_month;
			//判断月份是否溢出
			if (_month == 13)
			{
				//进位到下一年的1月
				_month = 1;
				_year++;
			}
		}
		return *this;
	}

	//前置++: ++d: 首先++，返回++之后的值
	Date& operator++()
	{
		return *this += 1;
		//return (*this).operator+=(1);
		//return *this;
	}

	//后置++: d++: 本身++， 返回++之前的值
	//前置++， 后置++都为单目运算符
	//如果为成员函数，则本质上不需要显式传参，编译器会自动传入this指针
	//int： 形参不是一个真正的参数，只是一个标记参数，编译器看到这样的定义，通过语法树搜索，可以解释为后置++
	Date operator++(int)
	{
		//保存++之前的值
		Date ret(*this);
		//++
		*this += 1;
		//返回++之前的值
		return ret;
	}


	Date& operator-=(int day){
		if (day < 0)
			return *this += -day;
		_day -= day;
		while (_day <= 0){
			// 向后退一个月
			--_month;
			// 月份退位之后也要考虑是否为负值 或者 为 0
			if (_month == 0){
				_month = 12;
				--_year;
			}
			_day += getMonthDay(_year, _month);
		}
	}

	Date& operator--(){
		return *this -= 1;
	}

	Date operator--(int){
		// Date ret = *this;
		Date ret(*this);
		*this -= 1;
		return ret;
	}
	// + - 运算符不能去修改左右两边操作数的内容
	Date operator+(int day){
		Date ret(*this);
		ret += day;
		return ret;
	}

	Date operator-(int day){
		Date ret(*this);
		ret -= day;
		return ret;
	}

	// 关系运算符 
	bool operator==(const Date& date){
		return _year == date._year
			&& _month == date._month
			&& _day == date._day;
	}

	bool operator > (const Date& date){
		if (_year > date._year){
			return true;
		}
		else if (_year == date._year){
			if (_month >date._month){
				return true;
			}
			else if (_month == date._month){
				if (_day > date._day){
					return true;
				}
			}
		}
		return false;
	}

	bool operator >= (const Date& d){
		return (*this == d) || (*this > d);
	}

	bool operator < (const Date& date){
		return !(*this >= date);
	}

	bool operator <= (const Date& date){
		return !(*this > date);
	}

	bool operator != (const Date& date){
		return !(*this == date);
	}

	// 两个日期相减得到的天数
	int operator-(const Date& date){
		Date d1(*this);
		Date d2(date);

		int num = 0;
		if (d1 > d2){
			while (d1 > d2){
				--d1;
				++num; 
			}
			return num;
		}
		else{
			while (d1 < d2){
				d1++;
				num++;
			}
			return -num;
		}
	}


	// const 对象调用const成员函数
	// 非const对象调用都可以
	// 非const对象（即可读可写）调用非const成员函数
	// const对象(只读)调用const成员函数，不能调用非const函数，权限不能被放大
	void printD()// printD(Date* const this)
	{
		// 此处可以调用const成员函数
		cout << _year << " " << _month << " " << _day << endl;
		// 可以修改
		this->_year = 2000; 
	}
	// const成员函数中得const修饰得为第一个参数，即this指针
	// const 成员函数内部不能修改成员函数的值
	void printD() const{ // printD(const Date* const this)
		cout << _year << " " << _month << " " << _day << endl;
		// 拒绝可以修改
		//this->_year = 2000;
		// 拒绝调用非const成员函数，读写权限不能被放大
		//++*this;
	}


	// 取地址运算符重载函数：operator&
	// 不需要显式定义，直接用默认即可
	Date* operator&(){
		return this;
	}

	// 返回const对象的地址，调用const成员函数
	const Date* operator&() const{
		return this;
	}

private:
	int _year;
	int _month;
	int _day;
};
//ostream& operator<<(ostream& _cout, const Date& date)
//{
//	_cout << date._year << " " << date._month << " " << date._day << endl;
//	return _cout;
//}

void test(){
	Date d(2020, 5, 24);
	//d.printDate();
	//d += 45;
	//d.printDate();
	//d++;
	Date d1(2020, 5, 31);
	//cout << d.operator-(d1) << endl;
	//cout << (d > d1) << endl;
	//d1++;
	//d1.printDate();
}

void testa(){
	Date d(2020, 5, 24);
	d.printD();
	d -= 30;
	d.printD();

}

class Time{
public:
	// explicit 禁止调用单参的隐式类型转换
 //	explicit Time(int a)
	//: _a(a){

	//}

	Time(int a)
		: _a(a){

	}

	Time(const Time& time)
		:_a(time._a){

	}

	Time& operator =(const Time& time){
		if (this != &time){
			_a = time._a;
		}
		return *this;
	}
private:
	int _a;
};
 
void dd(){
	Time a(1);// 创建对象
	// 通过匿名对象拷贝构造b的对象
	Time b = 2; // 创建对象：单参构造函数的隐式逻辑转换，调用构造函数创建一个匿名对象，+拷贝构造，
	b = 3; // 3作为参数传入构造函数，创建匿名对象，调用赋值，使用匿名对象给b赋值
	// 只支持单参构造函数的隐式类型转换，下面代码不支持
	// Time as =  8 , 0 ; // 不支持
}
int main(){
	testa();
	system("pause");
	return 0;
}