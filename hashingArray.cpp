#include <iostream>
using namespace std;



void LinearProbing(int hashtable[10], int size, int index, int index1, int key){
    while (hashtable[index]!=-1)
    {
        index++;
        if (index>=size)
        {
            index=index%size;
        }
        
        if(index==index1)
        {
            cout<<"Jagah nhi hai"<< endl;
            break;
        }
        if (hashtable[index]==-1)
        {
            hashtable[index]=key;
            cout<<"Daal diya "<< endl;
        }
        
        
    }
    
}


void QuadraticProbing(int hashtable[10], int size, int index, int index1,int key){

    int i=1;
    bool signal=true;
    while (hashtable[index]!=-1)
    {
        index=index1+(i*i);
        i++;
        if (index>=size)
        {
            index=index%size;
        }
        if (i==size)
        {
            cout<<"jagah nhi hai"<< endl;
            signal=false;
            break;
        }
        
    }
    if (signal==false)
    {
        LinearProbing(hashtable, size, index, index, key);
    }
    else{
        hashtable[index]=key;
        cout<<"Daal diya"<< endl;
    }
}


void insert(int hashtable[10],int size){
    cout << "Enter value: ";
    int key;
    cin >> key;

    int index = key % size;
    int index1 = index;

    QuadraticProbing(hashtable, size, index, index1, key);

}

void print(int hashtable[10], int size){
    for (int i = 0; i < size; i++)
    {
        cout << hashtable[i] << " ";

        if (i == size-1)
        {
            cout << endl;
        }
    }
    
}


bool QuadraticSearch(int hashtable[10],int size ,int index2 ,int *index,int Search){
    int i =1;
    bool signal = false;
    while (i<size)
    {
        if (hashtable[i]==Search)
        {
            cout<<"mil gya "<<hashtable[i]<<endl;
            signal=true;
            break;
            
        }
        
        *index=index2+(i*i); 
        i++;
        if (*index>=size)
        {
            *index=*index%size;
        }
        
        
    }
    
    return signal;

}

void LinearSearch(int hashtable[10],int size ,int index2 ,int index,int Search){
    bool signal =false;
    do
    {
        
        if (hashtable[index]==Search)
        {
            cout<<"mil gya"<<Search;
            signal=true;
            break;
        }
        index++;
        if (index>=size)
        {
            index=index%size;
        }
    }
        while(index!=index2);
    
        if (signal = false)
        {
            cout<<"Nahi mil rha ";
        }
        
        
    
    
}

void search(int hashtable[10], int size){
    cout<<"Enter the number to search";
    int Search;
    cin>>Search;

    int index= Search%size;
    int index2=index;

    bool check = QuadraticSearch(hashtable,size,index2,&index,Search);
    if (check==false)
    {
        LinearSearch(hashtable,size,index2,index,Search);
    }
    
}

int main(){
    int hashtable[10];
    int size = sizeof(hashtable)/sizeof(hashtable[0]);
    for (int i = 0; i <size; i++)
    {
        hashtable[i]=-1;
        
    }
    bool a =true;
    while (a==true)
    {
        cout << "1. Insert" << endl;
        cout << "2. Search" << endl;
        cout << "3. Print" << endl;
        cout << "4. Exit" << endl;
        int button;
        cin>>button;
        switch (button)
        {
        case 1: 
            insert(hashtable,size);
            
            break;
        case 2:
            search(hashtable, size);
            break;
        case 3: 
            print(hashtable,size);
            
            break;
        case 4:
            a=false;
            break;
        default:
            cout<<"kia bol rha hai bhai";
            break;
        }
        
    }
    
    return 0;
    
}