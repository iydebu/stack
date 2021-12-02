#include <iostream>
#include <stdlib.h>
#include <Windows.h>
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
template <class t = int>
class Stack
{
private:
    t *stk;
    int top = -1;
    int size;

public:
    Stack();
    Stack(int size);
    void push(t number);
    t pop();
    void show();
    friend ostream &operator<<(ostream &o, Stack<t> &s)
    {
        for (int i = 0; i <= s.top; i++)
        {
            o << s.stk[i] << " ";
        }
        o << endl;
        return o;
    }
};
template <class t>
Stack<t>::Stack()
{
    size = 5;
    stk = new t[size];
}
template <class t>
Stack<t>::Stack(int size)
{
    if (size < 0)
        throw Negative_Size();
    else
    {
        this->size = size;
        stk = new t[size];
    }
}
template <class t>
void Stack<t>::push(t number)
{
    if (top == size - 1)
        throw StackOverFlow();
    else
    {
        top++;
        stk[top] = number;
    }
}
template <class t>
t Stack<t>::pop()
{
    if (top == -1)
        throw StackUnderFlow();
    {
        return stk[top--];
    }
}
// template <class t>
// ostream &operator<<(ostream &o, Stack<t> &s)
// {
//     for (int i = 0; i <= s.top; i++)
//     {
//         o << s.stk[i] << " ";
//     }
//     o << endl;
//     return o;
// }

// template <class t>
// void Stack<t>::show()
// {
//     for (int i = 0; i <= top; i++)
//         cout << stk[i] << "\t";
// }
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
template <class t>
void run(Stack<t> s)
{
    int ch1;
    do
    {
        cout << "Choose the option: " << endl
             << "1. Push" << endl
             << "2. Pop" << endl
             << "3. Show" << endl
             << "4. Exit" << endl
             << "Option: ";
        cin >> ch1;
        switch (ch1)
        {
        case 1:
        {
            cout << endl;
            t ele = 0;
            cout << "Enter the element: ";
            cin >> ele;
            s.push(ele);
            cout << "successfully pushed !" << endl;
            break;
        }
        case 2:
        {
            cout << endl;
            t x = s.pop();
            cout << "Element: " << x << endl;
            cout << "successfully popped !" << endl;
            break;
        }
        case 3:
        {
            cout << endl;
            cout << "Stack :" << s << endl;
            break;
        }
        case 4:
        {
            cout << "Exit!" << endl;
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
    } while (ch1 != 4);
}
int main()
{
    // SetConsoleTitle("Stack");
    logo();
    int size = 0, ch;
    cout << "Enter the stack size: ";
    cin >> size;
    cout << "Welcome to Stack!" << endl
         << endl
         << "Which data type you want for stack? " << endl
         << "choose the option " << endl
         << "1.Integer" << endl
         << "2.Float" << endl
         << "3.Char" << endl
         << "4.Double" << endl
         << "Option: " << endl;
    cin >> ch;
    switch (ch)
    {
    case 1:
    {
        Stack<int> s(size);
        run(s);
        break;
    }

    case 2:
    {
        Stack<float> s(size);
        run(s);
        break;
    }

    case 3:
    {
        Stack<char> s(size);
        run(s);
        break;
    }

    case 4:
    {
        Stack<double> s(size);
        run(s);
        break;
    }
    default:
    {
        cout << endl;
        cout << "Wrong option -_-!" << endl;
        break;
    }
    }
    cout << endl
         << "Thanks for using!" << endl
         << "**** DEBU ****" << endl;
    system("pause");
    return 0;
}