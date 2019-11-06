/*------------------------------------------------------------------------------
* File Name:   palindrome28.c
* Purpose:     回文数    
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
    int m[16], n, i, t, count = 0;
    long unsigned a, k;
    printf("No. number it's square (palindrome)\n");
    for(n = 1; n < 256; n++) {   /* 穷举n的取值范围 */
        k = 0;
        t = 1;
        a = n * n;
        /* 从低到高分解数a的每一位存于数组m[1]~m[16] */
        for (i = 1; a != 0; i++) {
            m[i] = a % 10;
            a /= 10;
        }
        for (; i > 1; i--) {   /* 生成a的反序数 */
            k += m[i-1] * t;
            t *= 10;
        }
        if (k == n * n)   /* 判断是否为回文 */
            printf(" %2d %10d %10d\n", ++count, n, n * n);
    }
    return (0);
}
