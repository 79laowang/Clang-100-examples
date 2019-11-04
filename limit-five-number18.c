/*------------------------------------------------------------------------------
* File Name:   limit-five-number18.c
* Purpose:     有限5位数
*
* Author:      Ke Wang
*
* Created:     2019-11-02
* Copyright:   (c) Ke Wang 2019
* Licence:     <your licence>
*-----------------------------------------------------------------------------*/

#include <stdio.h>

int main()
{
    long int i;
    int count=0;   /* 满足条件的5位数的总数 */
    for(i=1000;i<9999;i++)
        if(!((i*10+6)%3))  /* 判断所选的数能否被3整除 */
            count++;
    printf("count=%d\n",count);
    return (0);
}
