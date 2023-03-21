#include <iostream>

using namespace std;

int gcd_cons_int(int num1,int num2)
{
	int temp,opcount=0;
	if(num1==0||num2==0)
		return 0;
	if(num1<num2)
		temp = num1;
	else
		temp = num2;
	while(true)
	{
		opcount++;
		if(num1%temp==0)
		{
			if(num2%temp==0)
			{
				cout<<"Opcount="<<opcount<<endl;
				return temp;
			}
		}
		--temp;
	}
}

int main()
{
	int num1,num2;
	cout<<"Enter first number: "<<endl;
	cin>>num1;
	cout<<"Enter second number: "<<endl;
	cin>>num2;
	cout<<"GCD="<<gcd_cons_int(num1,num2)<<endl;
}
