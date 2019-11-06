/*------------------------------------------------------------------------------
* File Name:   sum_of_squares29.c
* Purpose:     求具有 abcd = (ab + cd)^2 性质的四位数
*
* Author:      Ke Wang
*
* Created:     2019-11-07
* Copyright:   (c) Ke Wang 2019
* Licence:     <your licence>
*-----------------------------------------------------------------------------*/

#include <stdio.h>

int main()
{
    int n, a, b;
    printf("There are following numbers with 4 digits satisfied condition:\n");
    for (n = 1000; n < 10000; n++) {  /* 四位数N的取值范围1000～9999 */
        a = n / 100;         /* 截取N的前两位数字存到a */
        b = n % 100;        /*  截取N的后两位数字存到b */
        if ((a + b) * (a + b) == n)    /* 判断是否符合条件 */
            printf(" %d", n);
    }
    return (0);
}
