#include <iostream>

using namespace std;

bool find_index(char* finput,char* sinput)
{
	char* temp1;
	char* temp2;
	int index=0,opcount=0;
	while(1)
	{
		temp1 = finput;
		temp2 = sinput;
		if(*temp1==*temp2)
		{
			while(1)
			{
				opcount++;
				if(*temp2!=*temp1 && *temp2!='\0')
					break;
				if(*temp2=='\0')
				{
					cout<<"opcount="<<opcount<<endl;
					return true;
				}
				temp1++;
				temp2++;
			}
		}
		if(*finput=='\0')
			break;
		finput++;
		index++;
	}
	cout<<"opcount="<<opcount<<endl;
	return false;
}

int main()
{
	char ar[100],arr[100];
	cout<<"Enter a string:";
	cin>>ar;
	cout<<"Enter substring:";
	cin>>arr;
	cout<<boolalpha<<find_index(ar,arr);
}
