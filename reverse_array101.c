/*------------------------------------------------------------------------------
* File Name:   reverse_array.c
* Purpose:     逆序输出数组 
*
* Author:      Ke Wang
*
* Created:     2019-11-08
* Copyright:   (c) Ke Wang 2019
* Licence:     <your licence>
*-----------------------------------------------------------------------------*/

#include "stdio.h"
#define N 5

int main()
{
    int a[N]={9,6,5,4,1}, i, temp;
    printf("\n original array:\n");
    for(i=0;i<N;i++)
        printf("%4d",a[i]);
    for(i=0;i<N/2;i++) {
        temp=a[i];
        a[i]=a[N-i-1];
        a[N-i-1]=temp;
    }
    printf("\n sorted array:\n");
    for(i=0;i<N;i++)
        printf("%4d",a[i]);
    printf("\n");
    return (0);
}
