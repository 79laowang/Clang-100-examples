/*------------------------------------------------------------------------------
* File Name:   palindromic_prime33.c
* Purpose:     回文素数 
*
* Author:      Ke Wang
*
* Created:     2019-11-12
* Copyright:   (c) Ke Wang 2019
* Licence:     <your licence>
*-----------------------------------------------------------------------------*/

#include <stdio.h>

/* 判断是否位素数 */
int is_prime(int n)
{
    int i;
    for (i = 2; i <= (n-1)/2; i++)
        if (n % i == 0) return(0);
    return(1);
}

int main()
{
    int i, j, t, k, s;
    printf("Following are palindromic primes not greater than 1000:\n");
    for (i = 0; i <= 9; i++)   /* 穷举第一位 */
        for (j = 0; j <= 9; j++)   /* 穷举第二位 */
            for (k = 0; k <= 9; k++) {   /* 穷举第三位 */
                s = i * 100 + j * 10 + k;   /* 计算组成的数据 */
                t = k * 100 + j * 10 + i;    /* 计算对应的反序数 */
                if (i == 0 && j == 0) t /= 100;   /* 处理整数的前两位为0的情况 */
                else if (i ==0) t /= 10;    /* 处理整数的第一位为0的情况 */
                if (s > 10 && s == t && is_prime(s))   /* 若大于10且为回文素数，输出 */
                    printf("%d\t", s);
            }
    return (0);
}
