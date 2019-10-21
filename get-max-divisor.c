/*------------------------------------------------------------------------------
* File Name:   get-max-divisor.c
* Purpose:     5. 求最大约数
*
* Author:      Ke Wang
*
* Created:     2019-10-17
* Copyright:   (c) Ke Wang 2019
* Licence:     <your licence>
*-----------------------------------------------------------------------------*/

#include <stdio.h>

int main()
{
    long i;
    int j;
    printf("Please input number >100:");
    scanf("%ld",&i);
    for(j=999;j>=100;j--)
        if(i%j==0){
            printf("The max factor with 3 digits in %ld is:%d.\n",i,j);
            break;
        }
    return (0);
}
