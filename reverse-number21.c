/*------------------------------------------------------------------------------
* File Name:   reverse-number21.c
* Purpose:     4位反序数   
*
* Author:      Ke Wang
*
* Created:     2019-11-03
* Copyright:   (c) Ke Wang 2019
* Licence:     <your licence>
*-----------------------------------------------------------------------------*/

#include <stdio.h>

int main()
{
    int i;
    /* 穷举思维数可能的值 */
    for (i=1002; i<1111; i++)
        /* 判断反序数是否是原整数的9倍 */
        if (i%10*1000+i/10%10*100+i/100%10*10+i/1000==i*9)
            printf("The number satisfied states condition is:%d\n",i);
        else
            printf("No satisfied states condition number found!\n");
    return (0);
}
