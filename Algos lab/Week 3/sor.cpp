#include <iostream>
using namespace std;

void selection_sort(int arr[], int size)
{
	int op=0;
	int max;
	for(int i = 0; i < size; i++)
	{
		int min = arr[i];
		int index = i;
		for(int j = i; j < size; j++)
		{
			op++;
			if(arr[j] < min)
			{
				min = arr[j];
				index = j;
			}
		}
		
		int temp = arr[i];
		arr[i] = arr[index];
		arr[index] = temp;
	}
	cout << "after sorting: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	
	cout<<endl<<"Opcount = "<<op<<endl;
}

int main ()
{
	int a;
	cout << "Enter size" << endl;
	cin >> a;
	int arr[a];
	cout << "Enter values" << endl;
	for (int i = 0; i < a; i++)
		cin >> arr[i];
	selection_sort(arr, a);
}
