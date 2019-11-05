/*------------------------------------------------------------------------------
* File Name:   pefect_number25.c
* Purpose:     完全数
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
    int i, a, m;
    printf("There are following perfect numbers smaller than 1000:\n");
    /* 循环控制选取1～1000中的各数进行判断 */
    for (a = 1; a < 1000; a++) {
        /* 计算a的因子，并将各因子依次累加于m中 */
        for (m = 0,i = 1; i <= a / 2; i++)
            if (! (a % i)) m += i;
        if (m == a)  /* 判断若数a的各因子之和m=a，则a是完全数输出 */
            printf(" %4d", a);
    }
    return (0);
}
