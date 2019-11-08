/*------------------------------------------------------------------------------
* File Name:   get_prime_num30.c
* Purpose:     get prime numbers  
*
* Author:      Ke Wang
*
* Created:     2019-11-08
* Copyright:   (c) Ke Wang 2019
* Licence:     <your licence>
*-----------------------------------------------------------------------------*/

#include <stdio.h>

int main()
{
    int nl, nm, i, j, flag, count = 0;
    do {
        printf("Input START and END=?");
        scanf("%d%d", &nl, &nm);   /* 输入素数范围 */
    } while (! (nl > 0 && nl < nm));

    printf("-------------------- PRIME TABLE(%d - %d) ---------------------\n", nl, nm);
    if (nl == 1 || nl == 2) {  /* 单独处理素数2 */
        printf("%4d", 2);
        nl = 3;
        count++;
    }
    for (i = nl; i <= nm; i++) {
        if ((i % 2) == 0) continue;
        /* 判断是否能被3到整数的一半中的某数所整除 */
        for (flag = 1,j = 3; flag && j < i/2; j += 2)
            if ((i % j) == 0) flag = 0;
        /* 不能整除的为素数，输出 */
        if (flag) printf(++count % 15 ? "%4d" : "%4d\n", i);
    }
    return (0);
}
