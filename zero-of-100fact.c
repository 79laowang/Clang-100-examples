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
    int a, count = 0;  /* 循环从5开始，以5的倍数为步长，试探整数 */
    for (a = 5; a <= 100; a += 5){
        count ++;   /* 若为5的倍数，计数器加1 */
        if (!(a % 25)) count++; /* 25倍数，计数器再加1 */
    }
    printf("The number of 0 in the end of 100! is: %d.\n",count);
    return (0);
}
