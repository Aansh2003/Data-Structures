#include <iostream>
int length(char* input)
{
	int count = 0;
	while(*input!='\0')
	{
		count++;
		input++;
	}
	return count;
}

void concatenation(char* finput,char*sinput)
{
	while(*finput!='\0')
	{
		finput++;
	}
	while(*sinput!='\0')
	{
		*finput = *sinput;
		finput++;
		sinput++;
	}
	*finput='\0';
}

int compare(char* finput,char* sinput)
{
	while(*finput!='\0'||*sinput!='\0')
	{
		if(*finput!=*sinput)
		{
			return *finput-*sinput;
		}
		finput++;
		sinput++;
	}
	return 0;
}

int find_index(char* finput,char* sinput)
{
	char* temp1;
	char* temp2;
	int index=0;
	while(1)
	{
		temp1 = finput;
		temp2 = sinput;
		if(*temp1==*temp2)
		{
			while(1)
			{
				if(*temp2!=*temp1 && *temp2!='\0')
					break;
				if(*temp2=='\0')
					return index;
				temp1++;
				temp2++;
			}
		}
		if(*finput=='\0')
			break;
		finput++;
		index++;
	}
	return -1;
}
void remove(char* finput,char* sinput)
{
	int index = find_index(finput,sinput);
	int len = length(sinput);

	if(index!=-1)
	{
		finput += index;
		while(1)
		{
			*finput = *(finput+len);
			if(*finput=='\0')
				break;
			finput++;
		}
	}
}

void insert(char *finput,char *sinput,int pos)
{
	finput += pos;
	char var;
	if(pos<length(finput))
	{
		char* temp = finput;
		int len = length(sinput);
		char* temp2 = finput+len;
		do
		{
			*temp2 = *finput;
			finput++;
			temp2++;
		}while(*temp2!='\0');
		while(*sinput!='\0')
		{
			*temp = *sinput;
			sinput++;
			temp++;
		}
	}
}

