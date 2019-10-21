/*------------------------------------------------------------------------------
* File Name:   6:mantissa-of-higher-power.c
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
    int i, x, y, last=1;
    printf("Input X and Y (X ** Y):");
    scanf("%d ** %d", &x, &y);
    for (i=1; i<=y;i++)
        last = last * x%1000;
    printf("The last 3 digits of %d ** %d is: %d\n",x,y,last%1000);
    return (0);
}
