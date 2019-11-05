/*------------------------------------------------------------------------------
* File Name:   affinity_number26.c
* Purpose:     亲密数
*
* Author:      Ke Wang
*
* Created:     2019-11-05
* Copyright:   (c) Ke Wang 2019
* Licence:     <your licence>
*-----------------------------------------------------------------------------*/

#include <stdio.h>

int main()
{
    int a ,i, b, n;
    printf("There are following friendly - numbers pair smaller than 3000:\n");
    /* 穷举1000以内的全部整数 */
    for (a = 1; a < 3000; a++) {
        for (b = 0, i = 1; i <= a/2; i++)  /* 计算数a的各因子，各因子之和存于b */
            if (! (a % i)) b += i;   /* 计算数b的各因子，各因子之和存于n */
        for (n = 0, i = 1; i <= b/2; i++)
            if (! (b % i)) n += i;
        if (n == a && a < b)  /* 若n=a，则a和b是一对亲密数，输出 */
            printf("  %4d<==>%4d  " ,a,b);
    }
    return (0);
}
