#include <iostream>
#include <string>
#include <cstdint>
using namespace std;
//======Task1============================================================================
template<typename T>
class Pair1
{
public:
    Pair1(T _f1, T _f2) : f1(_f1), f2(_f2) {}
    T first() const
    {
        return f1;
    }
    T second() const
    {
        return f2;
    }
private:
    T f1;
    T f2;
};
//======Task2============================================================================
template<typename T1, typename T2>
class Pair
{
public:
    Pair(T1 _n1, T2 _n2) : n1(_n1), n2(_n2) {}
    T1 first() const
    {
        return n1;
    }
    T2 second() const
    {
        return n2;
    }
private:
    T1 n1;
    T2 n2;
};
//======Task3============================================================================
template<typename T3>
class StringValuePair : public Pair<string, T3>
{
public:
    StringValuePair(const string& _m1,const T3& _m2) : Pair<string, T3>(_m1, _m2) {}
};
void task1()
{
    Pair1<int> p1(6, 9);
    cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    const Pair1<double> p2(3.4, 7.8);
    cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
}
void task2()
{
    Pair<int, double> p1(6, 7.8);
    cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';
    const Pair<double, int> p2(3.4, 5);
    cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
}
void task3()
{
    StringValuePair<int> svp("Amazing", 7);
    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
}
int main()
{
    task1();
    task2();
    task3();
    return 0;
}