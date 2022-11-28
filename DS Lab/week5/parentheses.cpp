#include <iostream>
#include <stdlib.h>
#include <string.h>

struct stack{
	int MAX;
	int top;
	char *value;
	stack(int input)
	{
		MAX = input;
		value = (char*)calloc(MAX,sizeof(char));
		top = -1;
	}
	bool isEmpty()
	{
		if(top==-1)
			return 1;
		return 0;
	}
	bool isFull()
	{
		if(top==MAX)
			return 1;
		return 0;
	}
	char peek()
	{
		if(isEmpty()==1)
		{
			std::cout<<"No values in stack"<<std::endl;
			return 0;
		}
		return *(value+top);
	}
	void push(char input)
	{
		if(isFull()==0)
		{
			top++;
			*(value+top)=input;
		}
	}
	void pop()
	{
		if(isEmpty()==0)
		{
			top--;
		}
	}
};
int main()
{
	char array[200];
	std::cout<<"Enter expression:"<<std::endl;
	std::cin>>array;
	bool valid=1;
	int size = strlen(array),i=0;
	stack st(size);
	while(array[i]!='\0')
	{
		if(array[i]==40 || array[i]==91 || array[i]==123)
		{
			st.push(array[i]);
		}
		else if(array[i]==41 || array[i]==93 || array[i]==125)
		{
			if(st.isEmpty()==1)
			{
				valid = 0;
			}
			else
			{
				if(abs(st.peek()-array[i])<3)
				{
					st.pop();
				}
				else
				{
					valid = 0;
				}
			}
			if(valid==0)
				break;
		}
		else{}
		i++;
	}
	if(st.isEmpty()==1 && valid !=0)
		std::cout<<"valid"<<std::endl;
	else
		std::cout<<"invalid"<<std::endl;
}

