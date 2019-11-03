/*------------------------------------------------------------------------------
* File Name:   square-numbers23.c
* Purpose:     由两个平方三位数获得三个平方两位数 
*
* Author:      Ke Wang
*
* Created:     2019-11-03
* Copyright:   (c) Ke Wang 2019
* Licence:     <your licence>
*-----------------------------------------------------------------------------*/

/* Compile with gcc -o square-numbers23 square-numbers23.c -lm */

#include <stdio.h>
#include <math.h>

void f();

int main()
{
    int i, t;
    float a[3], b[3];
    printf("The possible perfect squares combinations are:\n");
    /* 穷举平方三位数的取值范围 */
    for (i = 11; i <=31; i++)
        for(t = 11; t <= 31; t++) {
            /* 分解平方三位数的各位，每位数字分别存入数组中 */
            f(i*i,a);
            f(t*t,b);
            /* 若三个新的数均是完全平方数，打印输出 */
            if (sqrt(a[0] * 10 + b[0]) == (int) sqrt(a[0] * 10 + b[0])
                && sqrt(a[1] * 10 + b[1]) == (int) sqrt(a[1] * 10 + b[1])
                && sqrt(a[2] * 10 + b[2]) == (int) sqrt(a[2] * 10 + b[2]))
                printf(" %d and %d\n",i * i,t * t);
        }
    return (0);
}

/* 分解三位数n的各位数字，将各个数字从高到低依次存入指针s所指向的数组中 */
void f(int n, float *s)
{
    int k;
    for (k=1000; k >= 10; s++){
        *s = (n % k) / (k / 10);
        k /= 10;
    }
}
