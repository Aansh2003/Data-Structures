#include <iostream>

using namespace std;

void linear_search(int arr[],int n)
{
    cout<<"Enter value to search:"<<endl;
    int val;
    cin>>val;
    cout<<"Starting linear search"<<endl;
    for(int i=0;i<n;i++)
    {
        if(val==arr[i])
        {
            std::cout<<"Found at "<<i<<endl;
            return;
        }
    }
    cout<<"not found"<<endl;
    return;
}

void binary_search(int arr[],int low,int high, int n)
{
    int mid = (high-1)/2;
    if(high<=low)
    {
        cout<<"not found"<<endl;
        return;
    }
    if(n>arr[mid])
        binary_search(arr,mid+1,high,n);
    else if(n<arr[mid])
        binary_search(arr,low,mid-1,n);
    else{
        cout<<"Found at"<<mid;
        return;
    }
}

int main()
{
    cout<<"Enter size of array"<<endl;
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    linear_search(arr,n);
    cout<<"Enter value to search:"<<endl;
    int val;
    cin>>val;
    binary_search(arr,0,n-1,val);
}