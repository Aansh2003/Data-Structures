#include <iostream>

using namespace std;

void bubble_sort(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        if(arr[i]>arr[i+1])
        {
            int temp = arr[i+1];
            arr[i+1] = arr[i];
            arr[i] = temp;
        }
    }
}

void swap(int& a,int& b) 
{
    int temp = b;
    b = a;
    a = temp;
}

int partition(int arr[], int start, int end)
{
    int pivot = arr[start];

    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }

    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);

    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex) {

        while (arr[i] <= pivot) {
            i++;
        }

        while (arr[j] > pivot) {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void quickSort(int arr[], int start, int end)
{

    if (start >= end)
        return;

    int p = partition(arr, start, end);

    quickSort(arr, start, p - 1);

    quickSort(arr, p + 1, end);
}

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
int main()
{
    int n;
    cout<<"Enter size"<<endl;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"1 for bubble ,2 for quick, 3 for insertion";
    int a;
    cin>>a;
    if(a==1)
        bubble_sort(arr,n);
    else if(a==2)
        quickSort(arr,0,n-1);
    else if(a==3)
        insertionSort(arr,n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i];
    }
}
