#include <iostream>
using namespace std;
int factorial(int n)
{
	if(n==1)
		return 1;
	return n*factorial(n-1);
}

int GCD(int n,int k)
{
	if(k>n)
		return GCD(k,n);
	if(k==0)
		return n;
	return GCD(k,n%k);
}

void TOH(int disks,int start,int aux,int dest)
{
	if(disks==1)
		cout<<"Moved from "<<start<<" to "<<dest<<endl;
	else
	{
		TOH(disks-1,start,dest,aux);
		TOH(disks-1,aux,start,dest);
	}
}
int fibonacci(int n)
{
    if(n == 1 || n == 0)
        return n;
    else 
        return fibonacci(n - 1) + fibonacci(n - 2);
}
int length_string(char* input)
{
	if(*input=='\0')
		return 0;
	input++;
	return 1+length_string(input);
}
int main()
{
	cout<<"Enter a value for factorial"<<endl;
	int n,k;
	cin>>n;
	cout<<"Factorial:"<<factorial(n)<<endl;
	cout<<"Enter 2 values for GCD"<<endl;
	cin>>n>>k;
	cout<<"GCD:"<<GCD(n,k)<<endl;
	cout<<"Enter number of disks for tower of hanoi:"<<endl;
	cin>>n;
	TOH(n,1,2,3);
	cout<<"Enter number of values of fibonacci series:"<<endl;
	cin>>n;
	for(int i=0;i<n;i++)
		cout<<fibonacci(i)<<" ";
	cout<<"Enter string to find length:"<<endl;
	char s[100];
	cin>>s;
	cout<<length_string(s);
	return 0;
}
