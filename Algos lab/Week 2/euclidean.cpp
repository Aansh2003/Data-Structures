#include <iostream>

using namespace std;

int main()
{
	int num1,num2,temp,opcount=0;
	cout<<"Enter first number: "<<endl;
	cin>>num1;
	cout<<"Enter second number: "<<endl;
	cin>>num2;
	if(num1==0)
	{
		cout<<"GCD="<<num2<<endl;
		return 0;
	}
	else if(num2==0)
	{
		cout<<"GCD="<<num1<<endl;
		return 0;
	}
	else
	{
		while(num2!=0)
		{
			opcount++;
			temp = num1%num2;
			num1 = num2;
			num2 = temp;
		}
		cout<<"GCD="<<num1<<endl;
		cout<<"Opcount="<<opcount<<endl;
		return 0;
	}
}
