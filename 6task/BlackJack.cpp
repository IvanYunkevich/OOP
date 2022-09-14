#include <iostream>
using namespace std;
//=======Task3======================================================================
class Player : public GenericPlayer
{
public:
    Player(const string& name = "") : GenericPlayer(name) { }

    virtual ~Player() { }

    virtual bool IsHitting() const
    {
        cout << _Name << ", do you want a hit? (Y/N): ";
        char response;
        cin >> response;
        return (response == 'y' || response == 'Y');
    }

    void Win() const
    {
        cout << _Name << " wins.\n";
    }

    void Lose() const
    {
        cout << _Name << " loses.\n";
    }

    void Push() const
    {
        cout << _Name << " pushes.\n";
    }
};
//=====task4==========================================================================
class House : public GenericPlayer
{
public:
    House(const string& name = "House") : GenericPlayer(name) { }

    virtual ~House() { }

    virtual bool IsHitting() const
    {
        return (GetTotal() <= 16);
    }

    void FlipFirstCard()
    {
        if (!(_Cards.empty()))
            _Cards[0]->Flip();
        else
            cout << "No card to flip!\n";
    }
};
int main()
{
    std::cout << "Hello World!\n";
}
