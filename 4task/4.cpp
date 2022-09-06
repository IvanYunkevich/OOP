#include <iostream>
#include <cstdint>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;
//=======Task1============================================================================
class ArrayInt
{
private:
    int m_length;
    int* m_data;
public:
    ArrayInt() : m_length(0), m_data(nullptr) { }
    ArrayInt(int _size) : m_length(_size)
    {
        if (_size > 0)
            m_data = new int[m_length];
        else
            m_data = nullptr;
    }
    ArrayInt(int _size, int init_value) : m_length(_size)
    {
        if (_size > 0)
            m_data = new int[m_length];
        else
            m_data = nullptr;
        for (size_t i = 0; i < m_length; i++)
        {
            m_data[i] = init_value;
        }
    }
    ~ArrayInt()
    {
        delete[] m_data;
        m_data = nullptr;
    }
    int size()
    {
        return m_length;
    }
    friend ostream& operator<<(ostream& out, ArrayInt& AI);
    int& operator[](int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }
    void clear()
    {
        if (m_data != nullptr)
        {
            delete[] m_data;
            m_data = nullptr;
            m_length = 0;
        }
    }
    void resize(int newSize)
    {
        if (newSize == m_length) return;
        if (newSize <= 0)
        {
            clear();
            return;
        }
        int* newData = new int[newSize];
        int CopySize = (newSize >= m_length) ? m_length : newSize;
        for (size_t i = 0; i < CopySize; i++)
        {
            newData[i] = m_data[i];
        }
        delete m_data;
        m_data = newData;
        m_length = newSize;
    }
    void insert(int value, int index)
    {
        resize(m_length + 1);
        for (size_t i = m_length - 1; i > index; i--)
        {
            m_data[i] = m_data[i - 1];
        }
        m_data[index] = value;
    }
    void pop_back()
    {
        resize(m_length - 1);
    }
    void pop_front()
    {
        for (size_t i = 0; i < m_length - 1; i++)
        {
            m_data[i] = m_data[i + 1];
        }
        resize(m_length - 1);
    }
    void sort()
    {
        int temp = 0;

        for (size_t i = 0; i < m_length - 1; i++)
        {
            for (size_t j = i + 1; j < m_length; j++)
            {
                if (m_data[i] > m_data[j])
                {
                    temp = m_data[i];
                    m_data[i] = m_data[j];
                    m_data[j] = temp;
                }
            }

        }
    }
    void print() 
    {
        for (size_t i = 0; i < m_length; i++)
        {
            cout << m_data[i] << " ";
        }
        cout << endl;
    }
};
ostream& operator<<(ostream& out, ArrayInt& AI)
{
    for (size_t i = 0; i < AI.size(); i++)
    {
        out << AI.m_data[i] << " ";
    }
    return out;
}

void task1()
{
    ArrayInt Arr(7, 5);
    cout << Arr << endl;
    Arr.resize(6);
    cout << Arr << endl;
    Arr.insert(1, 4);
    Arr.insert(2, 3);
    cout << Arr << endl;
    Arr.sort();
    Arr.print();
}
//=======Task2=========================================================
void task2()
{
    vector<int> nums(5, 1);
    nums[1] = 0;
    nums[3] = 3;
    nums[4] = 2;
    int count = 1;
    sort(nums.begin(), nums.end());
    for (size_t i = 1; i < nums.size(); i++)
    {
        if (nums[i - 1] != 0)
        {
            if (nums[i] > nums[i - 1])
            {
                count++;
            }
        }
    }
    cout << "Numbers: ";
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << "\n" "Various Numbers: " << count << endl;
}
int main()
{
    task1();
    task2();
    return 0;
}