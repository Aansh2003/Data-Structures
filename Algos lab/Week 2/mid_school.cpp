#include <iostream>
#include <math.h>

using namespace std;

void prime_values(int n,int arr[],int *len)
{
	int l=0;
    while (n%2==0)
    {
        arr[l]=2;
        l++;
        n = n/2;
    }
    for(int i=3;i<=sqrt(n);i=i+2)
    {
        while(n%i==0)
        {
            arr[l]=i;
            l++;
            n=n/i;
        }
    }
    if(n>2)
    {
    	arr[l]=n;
    	l++;
    } 
    *len = l;
}
 

int main()
{
	int num1,num2,gcd=1,opcount=0;
	cout<<"Enter first number: "<<endl;
	cin>>num1;
	cout<<"Enter second number: "<<endl;
	cin>>num2;
	int array1[100],len1;
	int array2[100],len2;
	int array3[100];
	prime_values(num1,array1,&len1);
	prime_values(num2,array2,&len2);
	int m=0,n=0,k=0;
	for(;m<len1||n<len2;)
	{
		opcount++;
		if(array1[m]==array2[n])
		{
			array3[k] = array1[m];
			k++;
			m++;
			n++;
		}
		if(array1[m]>array2[n])
			n++;
		if(array2[n]>array1[m])
			m++;
	}
	for(int i=0;i<k;i++)
	{
		gcd*=array3[i];
	}
	cout<<"GCD="<<gcd<<endl;
	cout<<"Opcount="<<opcount;
}
