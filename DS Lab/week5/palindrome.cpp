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
		else
		{
			std::cout<<"STACK FULL!"<<std::endl;
		}
	}
	void pop()
	{
		if(isEmpty()==0)
		{
			top--;
		}
		else
		{
			std::cout<<"STACK EMPTY!"<<std::endl;
		}
	}
};

int main()
{
	char input[200];
	std::cout<<"Enter string:"<<std::endl;
	std::cin>>input;
	int size = strlen(input),i=0;
	bool valid =1;
	stack st(size);
	while(input[i]!='\0')
	{
		if(i<=(size-1)/2)
		{
			st.push(input[i]);
		}
		else
		{
			if((size%2!=0 && i==size/2))
			{
				i++;
				continue;
			}
			else if((st.peek()==input[i]))
			{
				i++;
				st.pop();
				continue;
			}
			else
			{
				valid = 0;
				break;
			}
		}
		i++;
	}
	if(st.isEmpty()==1 && valid!=0)
		std::cout<<"Palindrome"<<std::endl;
	else
		std::cout<<"Not a palindrome"<<std::endl;
}
