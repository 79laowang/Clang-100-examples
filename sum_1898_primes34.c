/*------------------------------------------------------------------------------
* File Name:   sum_1898_primes34.c
* Purpose:    
*
* Author:      Ke Wang
*
* Created:     2019-11-19
* Copyright:   (c) Ke Wang 2019
* Licence:     <your licence>
*-----------------------------------------------------------------------------*/

#include <stdio.h>
#include <math.h>

#define NUM 320

int number[NUM];  /* 存放小于2019的全部奇素数 */

/* 奇素数判断 */
int is_prime(int i)
{
    int j;
    if (i <= 1) return (0);
    if (i <= 2) return (1);
    if (!(i % 2)) return (0);
    for (j = 3; j <= (int)(sqrt((double)i) + 1); j += 2)
        if(!(i % j)) return (0);                                                                                                                                                             
    return (1);
}

int main()
{
    int i, j = 0, count = 0;
    int year = 2019;
    printf("There are following primes sequences in first row:\n");
    for (i = 3; i <= year; i += 2){  // 求出不超过2019的全部奇素数
        if (is_prime(i)) {
            number[j++] = i;
        }
    }
    for (j--; number[j] > 1898; j--) {  //小于2019的最大素数开始向1898搜索
        for (i = 0; (number[j] - number[i]) >= 1898; i++) {  // 循环查找满足条件的素数
            if (number[j] - number[i] == 1898)  // 若两数的差为1898，则输出
                printf(" (%d). %3d,......,%d\n", ++count, number[i], number[j]);
        }
    }
    return (0);
}
