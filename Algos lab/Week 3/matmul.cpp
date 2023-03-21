#include <iostream>

using namespace std;

int main()
{
	cout<<"Enter number of rows in matrix 1:"<<endl;
	int n1,m1;
	cin>>n1;
	cout<<"Enter number of columns in matrix 1:"<<endl;
	cin>>m1;
	cout<<"Enter number of rows in matrix 2:"<<endl;
	int n2,m2;
	cin>>n2;
	cout<<"Enter number of columns in matrix 2:"<<endl;
	cin>>m2;
	if(m1!=n2)
	{
		cout<<"Invalid"<<endl;
		return 0;
	}
	int arr1[n1][m1],arr2[n2][m2],arr3[n1][m2];
	cout<<"Enter matrix 1 values:"<<endl;
	for(int i=0;i<n1;i++)
	{
		for(int j=0;j<m1;j++)
		{
			cin>>arr1[i][j];
		}
		cout<<endl;
	}
	cout<<"Enter matrix 2 values:"<<endl;
	for(int i=0;i<n2;i++)
	{
		for(int j=0;j<m2;j++)
		{
			cin>>arr2[i][j];
		}
		cout<<endl;
	}
	cout<<"Matrix 1:"<<endl;
	for(int i=0;i<n1;i++)
	{
		for(int j=0;j<m1;j++)
		{
			cout<<arr1[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl<<"Matrix 2:"<<endl;
	for(int i=0;i<n2;i++)
	{
		for(int j=0;j<m2;j++)
		{
			cout<<arr2[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl<<"Multiplying..."<<endl;
	for(int i=0;i<n1;i++)
	{
		for(int j=0;j<m2;j++)
		{
			arr3[i][j]=0;
			for(int k=0;k<m2;k++)
			{
				arr3[i][j]+=arr1[i][k]*arr2[k][j];   
			}
		}
	}
	for(int i=0;i<n1;i++)
	{
		for(int j=0;j<m2;j++)
		{
			cout<<arr3[i][j]<<" ";
		}
		cout<<endl;
	}
}
