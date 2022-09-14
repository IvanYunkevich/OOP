#include <iostream>
#include <string>
using namespace std;
//=====Task1==========================================================================
void writeInt()
{
	int num;

	cout << "Enter an int : ";

	while (true)
	{
		cin >> num;

		if (cin.good() && cin.peek() == '\n')
		{
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		}
		cin.clear();
		cout << "You entered an invalid number, try again : ";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	cout << "You entered an integer : " << num << endl;
}
//=====Task2==========================================================================
ostream& endll(ostream& s)
{
	s << "\n\n";
	s.flush();
	return s;
}
int main()
{
	writeInt();
	cout << "test" << endll;
	cout << "test";
	return 0;
}