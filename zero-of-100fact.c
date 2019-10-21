/*------------------------------------------------------------------------------
* File Name:   7:zero-of-100fact.c
* Purpose:     count number of zero in the end of 100!  
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
    int a, count=0;
    for(a=5; a<=100;a+=5){
        count ++;
        if (!(a%25)) count++;
    }
    printf("The number of 0 in the end of 100! is: %d.\n",count);
    return (0);
}
