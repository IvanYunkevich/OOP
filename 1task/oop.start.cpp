#include <iostream>
#include <cstdint>
#include <string>
//=======Task1==================================================================
using namespace std;
class Power
{
public:
    Power()
    {
       first_number = 10.5;
       second_number = 3;
    }

    void set(float _first_number, float _second_number)
    {
        first_number = _first_number;
        second_number = _second_number;
    }

    void calculate()
    {
        cout << pow(first_number, second_number) << endl;
    }
private:
    float first_number, second_number;
};
void task1()
{
    Power MK;
    MK.set(2.5, 2);
    MK.calculate();
}
//=======Task2===================================================================
class RGBA
{
public:
    RGBA(uint8_t _m_red = 0, uint8_t _m_green = 0, uint8_t _m_blue = 0, uint8_t _m_alpha = 255)
    {
        m_red = _m_red;
        m_green = _m_green;
        m_blue = _m_blue;
        m_alpha = _m_alpha;
    }
    void print()
    {
        cout << "|" << m_red << " " << "|" << m_green << " " << "|" << m_blue << " " << "|" << m_alpha << "|" << endl;
    }
private:
    uint8_t m_red;
    uint8_t m_green;
    uint8_t m_blue;
    uint8_t m_alpha;
};
void task2()
{
    RGBA M;
    M.print();
}
//=====Task3=======================================================================
class Stack
{
public:
    void reset()
    {
        for (int i = 0; i < 9; i++)
        {
            Arr[i] = 0;
        }
        count = 0;
    }
    bool push(int StackNumber)
    {
        if (count < 9)
        {
            Arr[count] = StackNumber;
            count++;
            return true;
        }
        else
        {
            cout << "Stack overflow" << endl;
            return false;
        }
    }
    bool pop()
    {
        if (count != 0)
        {
            return Arr[count--];
        }
        else
        {
            cout << "Empty stack" << endl;
        }

    }
    void print()
    {
        cout << "(";
        for (int i = 0; i < count; i++)
        {
            cout << " " << Arr[i];
        }
        cout << " " << ")" << endl;
    }
private:
    int Arr[10];
    int count;

};
void task3()
{
    Stack stack;
    stack.reset();
    stack.print();

    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();
    stack.print();
}
int main()
{
    //task1();
    //task2();
    task3();
    return 0;
}

