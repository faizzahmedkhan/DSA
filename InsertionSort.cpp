#include<iostream>
using namespace std;
int main(){
    int arr[10]={67,2,11,36,21,56,100,22,31,33};  
    int length=sizeof(arr)/sizeof(arr[0]);
    
    for (int i = 0; i <length; i++)
    {
        int c=arr[i];
        int j=i-1;
        while (arr[j]>c && j>=0)
        {
            arr[j+1]=arr[j];
            j--;
        }
        
        arr[j+1]=c;
    }
    for (int i = 0; i < length; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}