#include <iostream>
#include <cstdint>
#include <string>
using namespace std;
//=======Task1============================================================================
class Figure
{
public:
    Figure(){}
    virtual double area() = 0;
};

class Parallelogram : public Figure
{
public:
    Parallelogram() {};
    Parallelogram(double _a, double _b, double _h) : a(_a), b(_b), h(_h) {}
    virtual double area() override
    {
        return a * h;
    }
    ~Parallelogram(){}
protected:
    double a;
    double b;
    double h;
};

class Circle : public Figure
{
public:
    Circle(double _R) : R(_R) {}
    virtual double area() override
    {
        return 3.1415 * (R * R);
    }
private:
    double R;
};

class Rectangle : public Parallelogram
{
public:
    Rectangle(double _a, double _b, double _h) : Parallelogram(_a, _b, _h) {}
    virtual double area() override
    {
        return a * b;
    }
};

class Square : public Parallelogram
{
public:
    Square(double _a) : Parallelogram(_a, _a, _a) {}
    virtual double area() override
    {
        return a * a;
    }
};

class Rhombus : public Parallelogram
{
public:
    Rhombus(double _a, double _b, double _h) : Parallelogram(_a, _b, _h) {}
    virtual double area() override
    {
        return a * h;
    }
    ~Rhombus(){}
};

//======Task2====================================================================
class Car
{
public:
    Car() {}
    Car(string _Company, string _Model) : Company(_Company), Model(_Model) { cout << __FUNCTION__ << endl; }
    ~Car() {}
protected:
    string Company;
    string Model;
};
class PassengerCar : virtual public Car
{
public:
    PassengerCar(string _Company, string _Model) : Car(_Company, _Model) { cout << __FUNCTION__ << endl; }
    ~PassengerCar(){}
};
class Bus : virtual public Car
{
public:
    Bus(string _Company, string _Model) : Car(_Company, _Model) { cout << __FUNCTION__ << endl; }
    ~Bus(){}
};

class Minivan : public PassengerCar, public Bus
{
public:
    Minivan(string _Company, string _Model) : PassengerCar(_Company, _Model), Bus(_Company, _Model) { cout << __FUNCTION__ << endl; }
    ~Minivan(){}
};
//2//
void task2()
{
    Car C("Chevrolet", "Cruise");
    PassengerCar P("Dodge", "Grand Caravan");
    Bus B("Volkswagen", "California");
    Minivan M("Chevrolet", "Orlando");
    
}
//=======Task3=======================================================
class Fraction
{
public:
    Fraction(int _Chisl, int _Znam) : Chisl(_Chisl), Znam(_Znam)
    {
        if (Znam == 0)
        {
            cout << "Znam ne mojet bit' raven 0" << endl;
            Chisl = 0;
            Znam = 0;
        }
        else
        {
            cout << "fraction : " << Chisl << "/" << Znam << endl;
        }
    }
    Fraction operator+(Fraction& right)
    {
        int tZnam = Znam * right.Znam;
        int tChisl = Chisl * right.Znam + right.Chisl;
        return Fraction(tChisl, tZnam);
    }
    Fraction operator-(Fraction& right)
    {
        int tZnam = Znam * right.Znam;
        int tChisl = Chisl * right.Znam - right.Chisl;
        return Fraction(tChisl, tZnam);
    }
    Fraction operator*(Fraction& right)
    {
        int tZnam = Znam * right.Znam;
        int tChisl = Chisl * right.Chisl;
        return Fraction(tChisl, tZnam);
    }
    Fraction operator/(Fraction& right)
    {
        int tZnam = Znam * right.Chisl;
        int tChisl = Chisl * right.Znam;
        return Fraction(tChisl, tZnam);
    }
    bool operator==(Fraction& right)
    {
        if (Chisl == right.Chisl && Znam == right.Znam)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool operator!=(Fraction& right)
    {
        if (Chisl != right.Chisl && Znam != right.Znam)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    bool operator<(Fraction& right)
    {
        double LeftFr = static_cast<double>(Chisl) / static_cast<double>(Znam);
        double RightFr = static_cast<double>(right.Chisl) / static_cast<double>(right.Znam);
        if (LeftFr < RightFr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool operator>(Fraction& right)
    {
        double LeftFr = static_cast<double>(Chisl)/static_cast<double>(Znam);
        double RightFr = static_cast<double>(right.Chisl)/static_cast<double>(right.Znam);
        if (LeftFr > RightFr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool operator<= (Fraction& right)
    {
        if (*this > right)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    bool operator>= (Fraction& right)
    {
        if (*this < right)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

protected:
    int Chisl;
    int Znam;
};

void task3()
{
    Fraction LL1(4, 5);
    Fraction LL2(3, 5);
    //+//
    Fraction LL3 = LL1 + LL2;
    //-//
    Fraction LL4 = LL1 - LL2;
    //*//
    Fraction LL5 = LL1 * LL2;
    //delenie//
    Fraction LL6 = LL1 / LL2;
    //==//
    if (LL1 == LL2)
    {
        cout << "LL1 == LL2" << endl;
    }
    else
    {
        cout << "LL1 !== LL2" << endl;
    }
    //!=//
    if (LL1 != LL2)
    {
        cout << "LL1 != LL2" << endl;
    }
    else
    {
        cout << "LL1 = LL2" << endl;
    }
    //<//
    if (LL1 < LL2)
    {
        cout << "LL1 < LL2" << endl;
    }
    else
    {
        cout << "LL1 !< LL2" << endl;
    }
    //>//
    if (LL1 > LL2)
    {
        cout << "LL1 > LL2" << endl;
    }
    else
    {
        cout << "LL1 !> LL2" << endl;
    }
    //<=//
    if (LL1 <= LL2)
    {
        cout << "LL1 <= LL2" << endl;
    }
    else
    {
        cout << "LL1 !<= LL2" << endl;
    }
    //>=//
    if (LL1 >= LL2)
    {
        cout << "LL1 >= LL2" << endl;
    }
    else
    {
        cout << "LL1 !>= LL2" << endl;
    }
}
int main()
{
    task2();
    //task3();
    return 0;
}