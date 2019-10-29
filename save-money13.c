/*------------------------------------------------------------------------------
* File Name:   save-money13.c
* Purpose:     存钱利率问题 
*
* Author:      Ke Wang
*
* Created:     2019-10-29
* Copyright:   (c) Ke Wang 2019
* Licence:     <your licence>
*-----------------------------------------------------------------------------*/

#include <stdio.h>

int main()
{
	int i; float total=0;
	float mrate=0.0063;     /* monthly interest rate */
	for(i=0;i<5;i++)
		total = (total+1000.)/(1+mrate*12);
    printf("He must save %.2f at first.\n",total);
    return (0);
}
