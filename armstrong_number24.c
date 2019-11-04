/*------------------------------------------------------------------------------
* File Name:   armstong_number24.c
* Purpose:     阿姆斯特朗数
*
* Author:      Ke Wang
*
* Created:     2019-11-04
* Copyright:   (c) Ke Wang 2019
* Licence:     <your licence>
*-----------------------------------------------------------------------------*/

#include <stdio.h>

int main()
{
    int i, t, k, a[3];
    printf("There are following Armstrong number smaller than 1000:\n");
    /* 穷举要判定的数i的取值范围 */
    for (i=2; i < 1000; i++) {
        /* 截取整数i的各位从高到低位，分别赋于a[0]~a[2] */
        for(t = 0,k = 1000; k >= 10; t++) {
            a[t] = (i % k)/(k / 10);
            k /= 10;
        }
        /* 如果是阿姆斯特朗数，输出 */
        if (a[0] * a[0] * a[0] + a[1] * a[1] * a[1] + a[2] * a[2] * a[2] == i)
            printf(" %d",i);
    }
    return (0);
}
