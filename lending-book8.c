/*------------------------------------------------------------------------------
* File Name:   lending-book8.c
* Purpose:    
*
* Author:      Ke Wang
*
* Created:     2019-10-21
* Copyright:   (c) Ke Wang 2019
* Licence:     <your licence>
*-----------------------------------------------------------------------------*/

#include <stdio.h>

int main()
{
	int a,b,c,count=0;
	printf("There are different methods for XM to distribute books to 3 readers:\n");
	for (a=1;a<=5;a++)
		for(b=1;b<=5;b++)
			for(c=1;a!=b && c<=5;c++)
				if(c!=a && c!=b)
					printf(count%4 ? "%2d:%d,%d,%d\t" : "%2d:%d,%d,%d\n",
							++count,a,b,c);
	printf("\n");
    return (0);
}
