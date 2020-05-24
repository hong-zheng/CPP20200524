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
	//Date1 d(fun()); // ���ο������죬��һ����returnd,�ڶ���d(fun())
	//Date1 d;
	//Date1 copy(d);
	//// �Ż���ֱ�ӵ���������������copy2������������г��ԣ�����βα�����const
	//// ���Ż�����������������������+����
	//Date1 copy2(Date1(2020,5,23));
}
void testvolatile(){
	//const int a = 10;
	//int* pa = (int*)&a;
	//*pa = 20;
	//cout << a << endl; //10 :�˴���a���Ǵ��ڴ�ȥ�������ǴӼĴ������߻���ȥ����ԭ����sonst����Ϊ���ᷢ���ı䣬��ֱ�ӷ��ڻ�����߼Ĵ���
	//cout << *pa << endl; //20

	const volatile int a = 10; // �˴��ͱ�ʾ��ֹ�Ż���ֻ�ܴ��ڴ��ȡ
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

	// ����Դ��������ʽ���忽�����죬�����������򿽱���������

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
//	String copy(s);// ���������ɵ�Ĭ�Ͽ������캯��
//}




class Date1{
public:
	Date1(int y = 1, int m = 1, int d = 1){
		_year = y;
		_month = m;
		_day = d;
	}
	// �������죬���캯����һ��������ʽ��Ҳ���ڴ�������ʱ�Զ�����
	// ���ó�������һ���Ѿ����ڵö��󴴽�һ���µö���
	// �����µĶ����֮ǰ�ö���������ͬ
	// �˴��������Date1���ͣ����������ĵݹ鿽������
	// ������Ĭ�����ɵĿ���δ�ֽڿ�������ǳ������ֻ��������ģ���е����ݣ���������Դ
	//Date1(const Date1& d){
	//	_year = d._year;
	//	_month = d._month;
	//	_day = d._day;
	//}

	// ����������������Դ���������ٶ����ڶ����������ڽ���ʱ���������Զ�����
	// ���û����Դ��Ҫ�������Բ�����ʽд����������������Ĭ��������������
	~Date1(){
		// �Զ������Զ������͵���������������Զ������ͳ�Ա����Դ������
		cout << "~Date1()" << endl;
	}

	bool isEqual(const Date1& d){
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}
	// ��������أ���Ҫ��Ϊ����ǿ����Ŀɶ��ԣ�ʹ�÷�������ͨ����һ��
	// ���������⣬�����ʹ�÷�ʽ����ͨ����һ��
	// ����ֵ�� operator + ��Ҫ���ص������(�����б�){}
	// ��������غ�������ǳ�Ա������������ĸ������������Ҫ�ĸ�����һ��
	// �������ᴫ�� this ��Ϊ��һ������
	// �ײ� bool operator==(Date1* const d1 , const Date1& d)
	// this ָ��ʼ��ռ��������������õ�һ��λ��
	bool operator==(const Date1& d){
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}

	// ��ֵ���������
	// d = d1
	// ��ֵ��������غ������޸Ķ�������ݣ�����ȥ�޸Ĵ����µĶ���
	//void operator=(const Date1& d){
	//	_year = d._year;
	//	_month = d._month;
	//	_day = d._day;
	//	cout << "operator=(const Date1&��)"<< endl;
	//}

	// �����д��������Ҳ���Զ�����
	// Ĭ�����ɵ�Ҳ��һ���ֽڿ�����ǳ������
	// �����ǰ��������Դ���������ʽ���帳ֵ��������غ�����������
	Date1& operator=(const Date1& d){
		if (this != &d){
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		cout << "operator=(const Date1&��)" << endl;
		return *this;// ���ص�ǰ���ú�������,this�������ڿ϶����ں����������ڱ���
	}

//private:
	int _year;
	int _month;
	int _day;
	A _a;
};

// �Զ����������
//ostream& operator << (ostream& _cout, const Date1& date){
//	_cout << date._year << " " << date._month << " " << date._day << endl;
//	return _cout;
//}
int maisn(void){
	Date1 d(2020, 5, 23);
// ���ÿ������죬d3�����ڣ���d����d3�������Ե��ÿ������죬���Ǹ�ֵ�����
	// ������󶼴��ڣ����ø�ֵ��������أ������߶��󲻴��ڣ����ÿ�������
	Date1 d3 = d;
	//cout << d << endl;
	Date1 d2(d);
	d.operator==(d2); // �ȼ���d == d2
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
//		free(_array); // ���������Ҫ����
//		cout << "~Date1()"<< endl;
//	}
//	// �������죬���캯��һ��������ʽ��Ҳ���ڴ�������ʱ����
//	// ���ó�������һ���Ѿ����ڵĶ���ȥ ����һ���µĶ��󣬴������¶���͵�ǰ����������ͬ
//	// �������󿽱�������������г��ԣ���Ҫ��const,������벻ͨ��
//	// ���ͱ��������ã��������������ݹ飬��֧��ֵ����
//	// ������Ĭ�����ɵĿ�������Ϊ�ֽڿ�����ǳ����
//	// ǳ������ֻ��������ģ���е����ݣ���������Դ
//	// �˴�����Դ��ʾ�������ڵ�ǰ�����ڵĶ�����Դ�����磬�ѣ��ܵ��ȵ�
//	// ��ֵ���������Ҫ���߶����ڣ������ǿ������� Date1 d= d0 ;// �˴����ǿ������죬�����������ݺ�d0һ��
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
//	// ���������
//	// �Ѿ����ڵ��������������
//	// ���Զ��������У�����ʵ����������� �� Ŀ������ǿ�ɶ���
//	// ��������غ��������������⣬�����ʹ�÷�ʽ����ͨ����һ��
//	// ����ֵ + operator + ��Ҫ���ص������ + �������б�+ ������
//	// ����ͨ���������������������µĲ�����
//	// ���ز�����������һ�������ͻ���ö�����͵Ĳ�����
//	// ��������غ�������ǳ�Ա������������ĸ������������Ҫ�ĸ�����һ��������������ᴫ��thisָ����Ϊ��һ������
//	// ȫ�ֵ���������أ������������������Ҫ�ĸ���һ��
//	bool operator == (const Date1& d){
//		return _year == d._year
//			&& _month == d._month
//			&& _day == d._day;
//	}
//	// ������ֵ��������
//	// ������ֵ��Ҫ�з������ͣ�ֱ�ӷ�������
//	// ��д������Ҳ���Զ�����
//	// �����д���������Զ����ɵ����ֽڿ�������ǳ����
//	// �����ǰ��������Դ���������ʾ���帳ֵ��������أ�������
//	// �޸��Ѿ����ڵö���
//
//	Date1& operator=(const Date1& d){
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//		// ���ص�ǰ���ô˺���������this���ڿ϶����ں������ñ���
//		return *this;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//	int* _array; // ���Ͽ��٣���ջ�ϣ�ָ��ָ��ܴ�Ŀռ䣬û�д���ڶ����У���ʱ�����������о�Ҫ����free()������Դ
//};
//// this ָ��ʼ��ռ��������������õ�һ��λ�ã���λ�����е�������ر�ע�⣺��-���������ȵ�
////stream& operator << (ostream& _cout , const )
//void test(){
//	Date1 copy(Date1());
//	//��ʱ����ֻ����const
//	// �Ż���ֱ�ӵ���
//	Date1 copy2(Date1(2020.5,20)); 
//}
//// �������Դ������ʽ���忽������
//// ������
//class String{
//public:
//private:
//
//};
//int main(void){
//	volatile int i = 10;
//	const int j = 10;// ��Ϊ�ǻ��棬�Ͳ�ȥ�ڴ��ȡ��ֻ�ڻ����ȡ��ֻ�м���volatile�Ż�ȥ�ڴ��ȡ
//	// ���ܴӼĴ��������ȡ���п��ܻ��
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
			cout << "���ڲ��Ϸ�" << endl;
			cout << "����ΪĬ��ֵ: 2000-1-1" << endl;
			_year = 2000;
			_month = 1;
			_day = 1;
		}
	}
	int getMonthDay(int year, int month){
		// ��̬�������ӳ��������ڣ�ֻ��ʼ��һ��
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

		// ��Ҫ���ǽ�λ���� �� �� �Ľ�λ
		_day += day;
		while (_day > getMonthDay(_year, _month)){
			// �ж������Ƿ����
			_day > getMonthDay(_year, _month);
			// ��ȥ���µ��������·ݽ�λ
			_day -= getMonthDay(_year, _month);
			++_month;

			// �ж��·��Ƿ����
			if (_month == 13){
				// ��λ����һ���1��
				_month = 1;
				_year++;
			}
		}
		return *this;
	}

	// ǰ��++:++d:�ȼӼ��ٷ���
	Date& operator++(){
		*this += 1;
		//(*this).operator+=(1);
		return *this;
	}
	// ����++:d++:���ص��Ǽ�֮ǰ��ֵ
	Date operator++(int){ // int Ϊ��ʶ��,int��־����Ŀ�����
		// Ϊ��Ա������������ʽ����
		// int �ββ��������Ĳ�����ֻ��һ����ǲ��������������������Ķ��壬
		// ͨ���﷨�����������Խ���Ϊ����+
		
		// �����֮ǰ��ֵ�����ڷ���
		Date ret(*this);
		// ++ 
		*this += 1;
		// ����++֮ǰ��ֵ
		return ret;
	}
	void printD(){
     	cout << _year << " " << _month << " " << _day << endl;
	}

	// �������캯��
	Date(const Date& d){
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	// ��ֵ���������
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
		// �ж�_day�Ƿ�Ϊ��ֵ����0,��λ
		while (_day <= 0){
			// �����·��Ƿ�Ϊ��ֵ����0
			--_month;
			if (_month == 0){
				_month = 12;
				//�����λ
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
		Date ret(*this); // ִ�п�������
		// �ȼ��� Date ret = *this;
		*this -= 1;
		return ret;
	}

	// �ӷ��ͼ��������޸Ĳ�����������
	// ���� + ����
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

	// > ���������
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
		// �����ܸ��þ�������
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

	// const ����ͻ����const����
	void printD() const // void printD(const Date& const this)
	{// const �ڲ��������޸ĳ�Ա������ֵ
		// ��ʱָ������ݶ����ܱ�
	}

	// ȡ��ַ��������غ���:opertor&
	// һ�㲻����д
	// ����������ɧ����
	Date* operator&(){
		return this;
	}
	const Date* operator&() const{
		return this; // ��Ϊ����һ��const,���Է���ֵҲҪΪconst
	}
private:
	int _year;
	int _month;
	int _day;
};

void test(){
	Date a(2020, 3, 4);
	const Date b(a);
	a.printD();// ���÷�const��Ա��������ʱ�ǿɶ���д�Ķ��󣬷�const������Ե���const��Ա������ԭ�����ڶ�дȨ��û�б��Ŵ�
	b.printD(); // ����const��Ա����,(ֻ��)��const���󣬲��ܵ��÷�const��Ա������ԭ���Ƕ�дȨ�޲��ɱ��Ŵ�
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
		// ��ʼ��
	:_year(y)
	,_month(m)
	,_day(d)
	,_a(d) // ���ó�Ա��const��Ա�����ڶ����ʱ����г�ʼ����Ȼ�����ֶ�������ڹ��캯���Ĳ����б��г�Ϊ�����Ķ���
	,_b(d){
		// û��Ĭ�Ϲ�����Զ��庯���������ʼ���б��н��г�ʼ��
		// ������Ա���Բ�������ʽ��ʼ��
// ��ֵ
		//_year = y;
		//_month = m;
		//_day = d;
	}


	// �˴���Ա����Ϊ���������Ƕ����λ��
private:
	int _year;
	int _month;
	int _day;
	int& _a; // ���úͱ����ڶ����ʱ������ʼ������ʼ���б��У�
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
//	// �ж�year���Ƿ�Ϊ����
//	bool isLeap(int year){
//		if ( year %400 == 0
//			|| (year % 4 ==0 && year % 100 != 0)){
//			return true;
//		}
//		return false;
//	}
//	// ��ȡ����ĵ�ǰ�µ�����
//	int getMonthDay(int year, int month){
//		// ���徲̬������ֻ��ʼ��һ��
//		static int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//		int day = days[month];
//		if (2 == month && isLeap(year)){
//			day += 1;
//		}
//		return day;
//	}
//	// ȫȱʡ���캯��
//	Date(int year = 1900 , int month = 1 , int day = 1){
//		if (year > 0 
//			&& (month>0 && month <13)
//			&& (day > 0 && day <= getMonthDay(year,month))){
//			_year = year;
//			_month = month;
//			_day = day;
//		}
//		else{
//			cout << "������������" << endl;
//			cout << "��������Ϊ 2020-01-01" << endl;
//			_year = 2020;
//			_month = 1;
//			_day = 1;
//		}
//	}
//
//	// �������캯��
//	// d2(d1)
//	// ���봫���ò������������������ݹ�
//	// ��ʹ��������Ǵ���һ����dһ�µ�ʵ��
//	// �������ʽд����ϵͳ�����Ĭ�Ͽ������죬���ǲ�������Դ��Ϊ�ֽڿ�����ǳ������
//	Date(const Date& d){
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//
//	// ��ֵ���������
//	// d2 = d3 ->d2.operator=(&d2,d3);
//	Date& operator=(const Date& d){
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//		return *this;
//	}
//
//	// �����������ڶ�������֮ǰ�ͷ���Դ
//	~Date(){
//		//cout << "~Date() : this: " << this << endl;
//		//printDate();
//	}
//
//	// ����+=����
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
//	// ��ӡ����
//	void printDate() const{
//		cout << "year: " << _year << " month: " << _month << " day: " << _day << endl;
//		cout << endl;
//	}
//
//	//���� + ����
//	Date operator + (int day){
//		Date ret(*this);
//		ret += day;
//		return ret;
//	}
//	// ����-=����
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
//	// ����-����
//	Date operator-(int day){
//		Date ret(*this);
//		ret -= day;
//		return ret;
//	}
//
//	// ǰ��++
//	Date& operator++(){
//		*this += 1;
//		return *this;
//	}
//	// ����++
//	Date operator++(int){
//		Date ret(*this);
//		*this += 1;
//		return ret;
//	}
//	// ����--
//	Date operator--(int){
//		Date ret(*this);
//		*this -= 1;
//		return ret;
//	}
//	// ǰ��--
//	Date& operator--(){
//		*this -= 1;
//		return *this;
//	}
//
//	// == ���������
//	bool operator==(const Date& d){
//		if ( _year == d._year
//			&& _month == d._month
//			&& _day == d._day)
//			return true;
//		return false;
//	}
//	// > ���������
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
//	// >= ���������
//	inline bool operator>=(const Date & d){
//		return (*this > d) || (*this == d);
//	}
//
//	// < ���������
//	bool operator < (const Date& d){
//		return !(*this>=d);
//	}
//
//	//<= ���������
//	bool operator <= (const Date& d){
//		return *this < d || *this == d;
//	}
//	// != ���������
//	bool operator != (const Date& d){
//		return !(*this == d);
//	}
//	// ���� - ���� ��������
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
		//�ж������Ƿ�Ϸ�
		if (year > 0 && month > 0 && month < 13
			&& day > 0 && day <= getMonthDay(year, month))
		{
			_year = year;
			_month = month;
			_day = day;
		}
		else
		{
			cout << "���ڲ��Ϸ��� " << year << "-" << month << "-" << day << endl;
			cout << "����ΪĬ��ֵ�� 2000-1-1" << endl;
			_year = 2000;
			_month = 1;
			_day = 1;
		}

	}

	int getMonthDay(int year, int month)
	{
		static int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int day = days[month];
		//�����2����Ϊ���꣬+1
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
		//2020.5.21 + 20 --> 2020.5.41 --> ��λ --> -31 -->�·ݽ�λ --> 2020.6.10
		//2020.12.6 + 90 --> 2020.12.96 --> ��λ --> -31 -->�·ݽ�λ --> 2020.13.65 -->���λ
		// --> 2021.1.65--> --> ��λ --> -31 -->�·ݽ�λ --> 2021.2.34 --> --> ��λ --> -28 -->�·ݽ�λ --> 2021.3.6
		_day += day;
		//�ж������Ƿ����,�����Ҫ��λ
		while (_day > getMonthDay(_year, _month))
		{
			//��ȥ���µ��������·ݽ�λ
			_day -= getMonthDay(_year, _month);
			++_month;
			//�ж��·��Ƿ����
			if (_month == 13)
			{
				//��λ����һ���1��
				_month = 1;
				_year++;
			}
		}
		return *this;
	}

	//ǰ��++: ++d: ����++������++֮���ֵ
	Date& operator++()
	{
		return *this += 1;
		//return (*this).operator+=(1);
		//return *this;
	}

	//����++: d++: ����++�� ����++֮ǰ��ֵ
	//ǰ��++�� ����++��Ϊ��Ŀ�����
	//���Ϊ��Ա�����������ϲ���Ҫ��ʽ���Σ����������Զ�����thisָ��
	//int�� �ββ���һ�������Ĳ�����ֻ��һ����ǲ��������������������Ķ��壬ͨ���﷨�����������Խ���Ϊ����++
	Date operator++(int)
	{
		//����++֮ǰ��ֵ
		Date ret(*this);
		//++
		*this += 1;
		//����++֮ǰ��ֵ
		return ret;
	}


	Date& operator-=(int day){
		if (day < 0)
			return *this += -day;
		_day -= day;
		while (_day <= 0){
			// �����һ����
			--_month;
			// �·���λ֮��ҲҪ�����Ƿ�Ϊ��ֵ ���� Ϊ 0
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
	// + - ���������ȥ�޸��������߲�����������
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

	// ��ϵ����� 
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

	// ������������õ�������
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


	// const �������const��Ա����
	// ��const������ö�����
	// ��const���󣨼��ɶ���д�����÷�const��Ա����
	// const����(ֻ��)����const��Ա���������ܵ��÷�const������Ȩ�޲��ܱ��Ŵ�
	void printD()// printD(Date* const this)
	{
		// �˴����Ե���const��Ա����
		cout << _year << " " << _month << " " << _day << endl;
		// �����޸�
		this->_year = 2000; 
	}
	// const��Ա�����е�const���ε�Ϊ��һ����������thisָ��
	// const ��Ա�����ڲ������޸ĳ�Ա������ֵ
	void printD() const{ // printD(const Date* const this)
		cout << _year << " " << _month << " " << _day << endl;
		// �ܾ������޸�
		//this->_year = 2000;
		// �ܾ����÷�const��Ա��������дȨ�޲��ܱ��Ŵ�
		//++*this;
	}


	// ȡ��ַ��������غ�����operator&
	// ����Ҫ��ʽ���壬ֱ����Ĭ�ϼ���
	Date* operator&(){
		return this;
	}

	// ����const����ĵ�ַ������const��Ա����
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
	// explicit ��ֹ���õ��ε���ʽ����ת��
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
	Time a(1);// ��������
	// ͨ���������󿽱�����b�Ķ���
	Time b = 2; // �������󣺵��ι��캯������ʽ�߼�ת�������ù��캯������һ����������+�������죬
	b = 3; // 3��Ϊ�������빹�캯���������������󣬵��ø�ֵ��ʹ�����������b��ֵ
	// ֻ֧�ֵ��ι��캯������ʽ����ת����������벻֧��
	// Time as =  8 , 0 ; // ��֧��
}
int main(){
	testa();
	system("pause");
	return 0;
}