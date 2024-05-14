#include <iostream>
using namespace std;
#include <cstdlib>

struct Record
{
    int RollNo;
    float GP;
    Record * next;
};

void Push(Record ** top)
{
    Record * ptr = (Record *)malloc(sizeof(Record));
    cout << "Enter Roll Number: ";
    cin >> ptr->RollNo;
    cout << "Enter GP: ";
    cin >> ptr->GP;

    ptr->next = *top;

    if (*top == NULL)
    {
        *top = ptr;
    }
    else
    {
        // ptr->next = *top;
        *top = ptr;
    }
    
}

void Pop(Record ** top)
{
    if (top == NULL)
    {
        cout << "Stack Underflow" << endl;
    }
    else
    {
        Record * temp = *top;
        *top = (*top)->next;
        free(temp);
    }
}

int main()
{
    Record * top = NULL;
    return 0;
}