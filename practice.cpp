#include <iostream>
using namespace std;

void LinearProbing(int hashtable[10], int size, int index, int og_index, int key)
{
    while (hashtable[index]!=-1)
    {
        index++;
        if (index>=size)
        {
            index=index%size;
        }
        if (index==og_index)
        {
            cout << "Nahi mili" << endl;
            break;
        }
        if (hashtable[index] == -1)
        {
            hashtable[index] = key;
            cout << "Inserted" << endl;
        }
        
    }
}

void LinearSearch(int hashtable[10], int size, int index, int og_index, int s)
{
    while (hashtable[index]!=s)
    {
        index++;
        if (index>=size)
        {
            index=index%size;
        }
        if (index==og_index)
        {
            cout << "Nahi mili" << endl;
            break;
        }
        if (hashtable[index] == s)
        {
            
            cout << "mil gya" << endl;
        }
        
    }
}

void QuadraticProbing(int hashtable[10], int size, int index, int og_index, int key)
{
    int i=1;
    bool flag = true;
    while (hashtable[index]!=-1)
    {
        index=og_index+(i*i);
        i++;
        if (index>=size)
        {
            index=index%size;
        }
        if (i==size)
        {
            cout << "Nahi mili" << endl;
            flag = false;
            break;
        }
    }
    
    if (flag == false)
    {
        LinearProbing(hashtable, size, index, index, key);
    }
    else
    {
        hashtable[index] = key;
        cout << "Entered" << endl;
    }
}

void QuadraticSearching(int hashtable[10], int size, int index, int og_index, int s)
{
    int i=1;
    bool flag = true;
    while (hashtable[index]!=s)
    {
        index=og_index+(i*i);
        i++;
        if (index>=size)
        {
            index=index%size;
        }
        if (i==size)
        {
            cout << "Nahi mili" << endl;
            flag = false;
            break;
        }
    }
    
    if (flag == false)
    {
        LinearSearch(hashtable, size, index, index, s);
    }
    else
    {
        cout<<"Mil gya";
    }
}

void Insert(int hashtable[10], int size)
{
    cout << "Enter value: ";
    int key;
    cin >> key;

    int index = key % size;
    int og_index = index;

    QuadraticProbing(hashtable, size, index, og_index, key);
}

void Search(int hashtable[10],int size)
{
    cout << "Enter value: ";
    int s;
    cin >> s;

    int index = s % size;
    int og_index = index;

    QuadraticSearching(hashtable, size, index, og_index, s);
}

void Print(int hashtable[10], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << hashtable[i] << " ";

        if (i == size-1)
        {
            cout << endl;
        }
    }
    
}

int main()
{
    int hashtable[10];
    int size = sizeof(hashtable)/sizeof(hashtable[0]);

    for (int i = 0; i < size; i++)
    {
        hashtable[i] = -1;
    }

    bool loop = true;
    while (loop == true)
    {
        cout << "1. Insert" << endl;
        cout << "2. Search" << endl;
        cout << "3. Print" << endl;
        cout << "4. Exit" << endl;

        int option;
        cin >> option;

        switch (option)
        {
        case 1:
            Insert(hashtable, size);
            break;
        case 2:
            Search(hashtable, size);
            break;
        case 3:
            Print(hashtable, size);
            break;
        case 4:
            loop = false;
            break;
        default:
            cout << "Invalid entry" << endl;
            break;
        }
    }
    
    return 0;
}