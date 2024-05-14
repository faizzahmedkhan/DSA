#include <iostream>
using namespace std;

int stack[3];
int top = 0;

void Push()
{
    if (top == (sizeof(stack)/sizeof(stack[0])))
    {
        cout << "Stack Overflow" << endl;
    }
    else
    {
        int value;
        cout << "Enter value: ";
        cin >> value;
        stack[top] == value;
        top++;
    }
}

void Pop()
{
    if (top == 0)
    {
        cout << "Stack Underflow" << endl;
    }
    else
    {
        top--;
        // cout << stack[top] << endl;
    }
}

int main()
{
    bool flag = true;

    while (flag == true)
    {
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Exit" << endl;

        int option;
        cin >> option;

        if (option == 1)
        {
            Push();
        }
        else if (option == 2)
        {
            Pop();
        }
        else if (option == 3)
        {
            break;
        }
        else
        {
            cout << "Enter valid option" << endl;
        }
    }
    
    return 0;
}