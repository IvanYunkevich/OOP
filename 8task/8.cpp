#include <iostream>
#include <cstdint>
#include <string>
using namespace std;
//======Task1============================================================================

template <typename T> T div(T num, T den)
{
    try
    {
        if (den == 0)
        {
            throw "DivisionByZero";
        }
        else
        {
            return num / den;
        }
    }
    catch (const char* error)
    {
        cout << error << endl;
    }
}
//======Task2============================================================================
class Ex
{
public:
    double x;
    Ex(double a) : x(a) {}
    ~Ex(){}

};
class Bar
{
public:
    Bar() : y(0.0) {}
    void set(double a)
    {
        if (y + a > 100)
        {
            throw Ex(a * y);
        }
        else
        {
            y = a;
        }
    }
private:
    double y;
};
//======Task3============================================================================
class OffTheField
{
    const int x;
    const int y;
    const int lastX;
    const int lastY;
public:
    OffTheField(int _x, int _y, int _lastX, int _lastY) : x(_x), y(_y), lastX(_lastX), lastY(_lastY) { }
    string getError() const
    {
        return "Robot can't leave grid to pos " + to_string(lastX) + " " + to_string(lastY);
    }
};
class IllegalCommand
{
    const int lastX;
    const int lastY;
public:
    IllegalCommand(int _newX, int _newY) : lastX(_newX), lastY(_newY) { }
    string coordError() const
    {
        return "coordinates out of range : " + to_string(lastX) + " " + to_string(lastY);
    }
};
class Robot
{
    int posX;
    int posY;
public:
    Robot(int x, int y) : posX(x), posY(y) {}
    void setX(int x)
    {
        posX = x;
    };
    void setY(int y)
    {
        posY = y;
    };
    void moveTo(int lastX, int lastY)
    {
        if (lastX > 1 || lastX < -1 || lastY > 1 || lastY < -1)
        {
            throw IllegalCommand(lastX, lastY);
        }
        int tempX = posX + lastX;
        int tempY = posY + lastY;
        if (tempX < 0 || tempX > 10 || tempY < 0 || tempY > 10)
        {
            throw OffTheField(posX, posY, tempX, tempY);
        }
        else {
            cout << "move to the coordinates " << tempX << ' ' << tempY << endl;
        }
        setX(tempX);
        setY(tempY);
    }
    void showPosition()
    {
        cout << "Position is - (" << posX << ',' << posY << ')' << endl;
    }
};
//=======================================================================================
//1==
void task1()
{
    cout << div<int>(4, 0);
}
//2==
void task2()
{
    Bar bar;
    try
    {
        int n;
        do
        {
            cout << "Enter n ";
            cin >> n;
            bar.set(n);
        } while (n != 0);
    }
    catch (Ex& ex)
    {
        cerr << "Ex " << ex.x << " > 100" << endl;
    }
}
//3==
void task3()
{
    Robot MK(0, 0);
    int cX;
    int cY;
    while (true)
    {
        cout << "Enter X (-1/0/1)";
        cin >> cX;

        cout << "Enter Y (-1/0/1)";
        cin >> cY;
        try
        {
            MK.moveTo(cX, cY);
            MK.showPosition();
        }
        catch (const OffTheField& exept)
        {
            cout << exept.getError() << endl;
            break;
        }
        catch (const IllegalCommand& exept)
        {
            cout << exept.coordError() << endl;
            break;
        }
    }
}
int main()
{
    //task1();
    //task2();
    task3();
    return 0;
}
