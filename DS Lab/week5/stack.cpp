#include <iostream>
#include <stdlib.h>
struct stack{
	int MAX;
	int top;
	int *value;
	stack(int input)
	{
		MAX = input;
		value = (int*)calloc(MAX,sizeof(int));
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
	int peek()
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
	std::cout<<"Enter maximum size of stack."<<std::endl;
	int size,input=0,aux=0;
	std::cin>>size;
	stack st(size);
	bool flag = 1;
	while(input!=6)
	{
		std::cout<<"Choose operation:\n1)Push\n2)Pop\n3)Peek\n4)isFull\n5)isEmpty\n6)Exit"<<std::endl;
		std::cin>>input;
		switch(input)
		{
			case 1:
				std::cout<<"Enter value: "<<std::endl;
				std::cin>>aux;
				st.push(aux);
				break;
			case 2:
				st.pop();
				break;
			case 3:
				std::cout<<"value is: "<<st.peek()<<std::endl;
				break;
			case 4:
				std::cout<<std::boolalpha<<st.isFull()<<std::endl;
				break;
			case 5:
				std::cout<<std::boolalpha<<st.isEmpty()<<std::endl;
				break;
			case 6:
				std::cout<<"Exiting!"<<std::endl;
				break;
			default:
				std::cout<<"invalid input, please try again."<<std::endl;
		}
	}
}
