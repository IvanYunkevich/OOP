#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
//======Task1============================================================================
class Date
{
public:
	Date(unsigned int _Day, unsigned int _Month, unsigned int _Year) : Day(_Day), Month(_Month), Year(_Year) { }
	unsigned int getDay() const
	{
		return Day;
	}
	unsigned int getMonth() const
	{
		return Month;
	}
	unsigned int getYear() const
	{
		return Year;
	}
	friend std::ostream& operator<<(std::ostream& o, const Date& date) 
	{
		o << setfill('0')
			<< setw(2) << to_string(date.getDay()) << '.'
			<< setw(2) << to_string(date.getMonth()) << '.'
			<< to_string(date.getYear()) << endl;
		return o;
	}
protected:
	unsigned int Day;
	unsigned int Month;
	unsigned int Year;
};
//======Task2============================================================================
std::shared_ptr<Date> laterDate(const shared_ptr<Date>& date_1, const shared_ptr<Date>& date_2)
{
	if (date_1.get()->getYear() > date_2.get()->getYear())
	{
		return date_1;
	}
	else if (date_1.get()->getYear() < date_2.get()->getYear())
	{
		return date_2;
	}
	else if (date_1.get()->getMonth() > date_2.get()->getMonth())
	{
		return date_1;
	}
	else if (date_1.get()->getMonth() < date_2.get()->getMonth())
	{
		return date_2;
	}
	else if (date_1.get()->getDay() > date_2.get()->getDay())
	{
		return date_1;
	}
	else if (date_1.get()->getDay() < date_2.get()->getDay())
	{
		return date_2;
	}
};
void swapDate(shared_ptr<Date>& date_1, shared_ptr<Date>& date_2)
{
	auto temp = move(date_1);
	date_1 = move(date_2);
	date_2 = move(temp);
};
void task1()
{
	Date d(21, 9, 2022);
	unique_ptr<Date> today(new Date(d));
	cout << today.get()->getDay() << endl;
	cout << today.get()->getMonth() << endl;
	cout << today.get()->getYear() << endl;
	cout << *(today.get()) << endl;
	unique_ptr<Date> date;
	cout << "move *today in *date" << endl << endl;
	date = move(today);

	if (today.get() == nullptr) 
	{
		cout << "*today = nullptr" << endl;
	}
	else 
	{
		cout << "*today != nullptr" << endl;
	}
	if (date.get() == nullptr) 
	{
		cout << "*date = nullptr" << endl;
	}
	else 
	{
		cout << "*date != nullptr" << endl;
	}
}
void task2()
{
	auto d1 = make_shared<Date>(20, 9, 2022);
	auto d2 = make_shared<Date>(15, 9, 2022);
	cout << *d1 << *d2 << endl;
	auto LD = laterDate(d1, d2);
	cout << "Later Date is: " << *LD << endl;
	swapDate(d1, d2);
	cout << *d1 << *d2 << endl;
}
int main()
{
	task1();
	task2();
	return 0;
}