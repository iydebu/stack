#include <iostream>
#include <stdlib.h>
using namespace std;

class Negative_Size : exception
{
};

class StackOverFlow : exception
{
};

class StackUnderFlow : exception
{
};

class Stack
{
private:
    int *stk;
    int top = -1;
    int size;

public:
    Stack();
    Stack(int size);
    void push(int number);
    int pop();
    friend ostream &operator<<(ostream &o, Stack &s);
};

Stack::Stack()
{
    size = 5;
    stk = new int[size];
}

Stack::Stack(int size)
{
    if (size < 0)
        throw Negative_Size();
    else
    {
        this->size = size;
        stk = new int[size];
    }
}

void Stack::push(int number)
{
    if (top == size - 1)
        throw StackOverFlow();
    else
    {
        top++;
        stk[top] = number;
    }
}

int Stack::pop()
{
    if (top == -1)
        throw StackUnderFlow();
    else
    {
        return stk[top--];
    }
}

ostream &operator<<(ostream &o, Stack &s)
{
    for (int i = 0; i <= s.top; i++)
    {
        o << s.stk[i] << " ";
    }
    o << endl;
    return o;
}

void logo()
{
    cout << " $$$$$$\\    $$\\                         $$\\  " << endl
         << "$$  __$$\\   $$ |                        $$ |      " << endl
         << "$$ /  \\__|$$$$$$\\    $$$$$$\\   $$$$$$$\\ $$ |  $$\\ " << endl
         << "\\$$$$$$\\  \\_$$  _|   \\____$$\\ $$  _____|$$ | $$  |" << endl
         << " \\____$$\\   $$ |     $$$$$$$ |$$ /      $$$$$$  / " << endl
         << "$$\\   $$ |  $$ |$$\\ $$  __$$ |$$ |      $$  _$$<  " << endl
         << "\\$$$$$$  |  \\$$$$  |\\$$$$$$$ |\\$$$$$$$\\ $$ | \\$$\\ " << endl
         << " \\______/    \\____/  \\_______| \\_______|\\__|  \\__|" << endl
         << endl;
}

int main()
{
    logo();
    int size = 0, ch, ch1;
    cout << "Enter the stack size: ";
    cin >> size;
    Stack s(size);
    do
    {
        do
        {
            cout << "Choose the option: " << endl
                 << "1. Push" << endl
                 << "2. Pop" << endl
                 << "3. Show" << endl
                 << "Option: ";
            cin >> ch1;
            switch (ch1)
            {
            case 1:
            {
                cout << endl;
                int ele = 0;
                cout << "Enter the element: ";
                cin >> ele;
                s.push(ele);
                cout << "successfully pushed !" << endl;
                break;
            }
            case 2:
            {
                cout << endl;
                cout << "Element: " << s.pop() << endl;
                cout << "successfully popped !" << endl;
                break;
            }
            case 3:
            {
                cout << endl;
                cout << "Stack :" << s << endl;
                break;
            }
            default:
            {
                cout << endl;
                cout << "Wrong option -_-!" << endl;
                break;
            }
            }
            system("pause");
            system("cls");
            logo();
        } while (!(ch1 == 1 || ch1 == 2 || ch1 == 3));
        cout << endl;
        cout << "Do you want to continue?" << endl
             << "Enter '1' for yes and **any key** for no!" << endl;
        cin >> ch;
    } while (ch == 1);
    cout << endl
         << "Thanks for using!" << endl
         << "**** DEBU ****" << endl;
    system("pause");
    return 0;
}