/*------------------------------------------------------------------------------
* File Name:   int2binary10.c
* Purpose:     convert integer to binary
*
* Author:      Ke Wang
*
* Created:     2019-10-24
* Copyright:   (c) Ke Wang 2019
* Licence:     <your licence>
*-----------------------------------------------------------------------------*/

#include <stdio.h>

void printb(int x,int n)
{
	if (n>0){
		putchar('0'+((unsigned)(x&(1 << (n-1))) >> (n-1)));
		printb(x,n-1);
	}
}

int main()
{
	int x;
	printf("Input number:");
	scanf("%d",&x);
	printf("number of decimal from:%d\n",x);
	printf("    it's binary from:");
	printb(x, sizeof(int)*8);
	putchar('\n');
    return (0);
}
