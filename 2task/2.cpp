#include <iostream>
#include <cstdint>
#include <string>
using namespace std;
//========Task1=================================================================
class Person
{
public:
    Person(string _Name, int _Age, char _Gender, int _Weight) : Name(_Name), Age(_Age), Gender(_Gender), Weight(_Weight)
    {
        Name = _Name;
        Age = _Age;
        Gender = _Gender;
        Weight = _Weight;
    }

    void print()
    {
        cout << Name << " " << Age << " " << Gender << " " << Weight << endl;
    }
    void setName(string _Name)
    {
        Name = _Name;
    }
    void setAge(int _Age) { (_Age >= 0) ? _Age : Age = 0; }
    void setWeight(int _Weight) { (_Weight >= 0) ? _Weight : Weight = 0; }
protected:
    string Name;
    int Age;
    char Gender;
    int Weight;
};

class Student : public Person
{
public:
    Student(int _Year, string _Name, int _Age, char _Gender, int _Weight) : Person(_Name, _Age, _Gender, _Weight)
    {
        Year = _Year;
        Count++;
    }

    void SetYear(int _Year)
    {
        Year = _Year;
    }
    void printYear()
    {
        cout << Year << endl;
    }
    void IncreaseYear()
    {
        Year++;
    }
    void StudentCounter()
    {
        cout << "Студентов : " << Count << endl;
    }
private:
    int Year;
    static int Count;
};
int Student::Count = 0;
void task1()
{
    setlocale(LC_ALL, "Rus");
    Student MK(2022, "Markus", 23, 'M', 65);
    Student CON(2021, "John", 24, 'M', 60);

    MK.print();
    MK.printYear();
    CON.print();
    CON.printYear();
    MK.StudentCounter();

    MK.setName("Ivan");
    MK.print();
}
//========TASK2=================================================================
class Fruit
{
public:
    Fruit() {}
    Fruit(string _Color) : Color(_Color) {}
    ~Fruit() {}
    string getName()
    {
        return Name;
    }
    string getColor()
    {
        return Color;;
    }
protected:
    string Name;
    string Color;
};

class Apple : public Fruit
{
public:
    Apple() {}
    Apple(string _Color) : Fruit(_Color)
    {
        Name = "apple";
    }
    ~Apple() {}
};

class Banana : public Fruit
{
public:
    Banana()
    {
        Name = "banana";
        Color = "yellow";
    };
};

class GrannySmith : public Apple
{
public:
    GrannySmith()
    {
        Name = "Granny Smith apple";
        Color = "green";
    }
};

void task2()
{
    Apple a("red");
    Banana b;
    GrannySmith c;
    cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";
}
//=========TASK3==================================================================
/* Базовый класс Card (Масть карты, ее значение и положение карты)
   Базовый класс Person и 2 производных от него класса (1 - игрок, 2 - дилер) от каждого из них производный класс Рука (набор карт, кол-во очков
   и возможность взять еще карту)
 */
int main()
{
    task1();
    //task2();
    return 0;
}