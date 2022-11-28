#include <iostream>
#include "strlib.h"

int main()
{
	char str[]="hel0000o";
	char str2[]="hel";
	insert(str,str2,1);
	printf("%s",str);
	return 0;
}

