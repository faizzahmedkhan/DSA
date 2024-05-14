#include<iostream>
using namespace std;
int main(){
    // int n;
    // cin>>n;
    // int arr[n];
    // for (int i = 0; i<n; i++)
    // {
    //     cin>>arr[i];
    // }
    int arr[10]={67,2,11,36,21,56,100,22,31,33};  
    int length=sizeof(arr)/sizeof(arr[0]);

    int counter=1;
    while(counter<length){
    for (int i = 0; i<length-counter; i++)
    {
        if (arr[i]>arr[i+1])
        {
            int temp=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp;
        }
        
    }
    counter++;
    }
    for (int i = 0; i <length; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}