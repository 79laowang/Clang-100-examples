/*------------------------------------------------------------------------------
* File Name:   get-car-speed22.c
* Purpose:     求车速
*
* Author:      Ke Wang
*
* Created:     2019-11-03
* Copyright:   (c) Ke Wang 2019
* Licence:     <your licence>
*-----------------------------------------------------------------------------*/

#include <stdio.h>

int main()
{
    int t, a[5];  /* 数组a存放分解的数字位 */
    long int k, i;
    for (i = 95860; ; i++) {  /* 循环试探 */
        for (t = 0, k = 100000; k >= 10; t++) {
            /* 从高到低分解所取i值的每位数字，依次存放于a[0]~a[5]中  */
            a[t] =  (i % k) / (k / 10);
            k /= 10;
        }
        if ((a[0] == a[4]) && (a[1] == a[3])) {  /* 若满足条件是对称数，输出结果 */
            printf("The new symmetrical number kelometers is: %d%d%d%d%d\n",
                    a[0],a[1],a[2],a[3],a[4]);
            printf("The velocity of the car is: %.2f\n", (i-95859) / 2.0);
            break;
        }
    }
    return (0);
}
