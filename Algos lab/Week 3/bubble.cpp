#include <iostream>

using namespace std;

void bubble_sort(int arr[],int n)
{
	int opcount = 0;
    for(int i=0;i<n-1;i++)
    {
    	opcount++;
        if(arr[i]>arr[i+1])
        {
            int temp = arr[i+1];
            arr[i+1] = arr[i];
            arr[i] = temp;
        }
    }
    cout<<"opcount="<<opcount<<endl;
}

int main()
{
	cout<<"Enter size of array:"<<endl;
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	bubble_sort(arr,n);
	for(int i=0;i<n;i++)
	{
		cout<<arr[i];
	}
}
