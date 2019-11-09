/*------------------------------------------------------------------------------
* File Name:   goldbach_conjecture31.c
* Purpose:     哥德巴赫猜想
*
* Author:      Ke Wang
*
* Created:     2019-11-09
* Copyright:   (c) Ke Wang 2019
* Licence:     <your licence>
*-----------------------------------------------------------------------------*/

#include <stdio.h>
#include <math.h>

int fflag(int i)
{
    int j;
    if (i <= 1) return (0);
    if (i <= 2) return (1);
    if (!(i % 2)) return (0);
    for (j = 2; j <= (int)(sqrt((double)i) + 1); j += 2)
        if(!(i % j )) return (0);
    return (1);
}

int main()
{
    int i, n;
    for (i = 4; i <= 2000; i += 2) {
        for (n = 2; n < i; n++)  /* 将偶数i分解为两个整数 */
            if (fflag(n))   /* 分别判断两个整数是否均为素数 */
                if (fflag(i - n)) {
                    printf(i % 5 ? " %d = %d + %d " : " %d = %d + %d\n", 
                            i, n, i-n);  /* 若均是素数，则输出 */
                    break;
                }
            if (n == i) printf("error %d\n", i);
    }
    return (0);
}
