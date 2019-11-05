/*------------------------------------------------------------------------------
* File Name:   automorphic_number27.c
* Purpose:     自守数
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
    long mul, number, k, ll, kk;
    printf("It exists following automorphic numbers smaller than 200000:\n");
    for (number = 0; number < 200000; number++) {
        /* 由number的位数确定截取数字进行乘法时的系数k */
        for (mul = number, k = 1; (mul /= 10) > 0; k *= 10);
        kk = k * 10;  /* kk为截取部分积时的系数 */
        mul = 0;   /* 积的最后N位 */
        ll = 10;   /* ll为截取乘数相应位时的系数 */
        while (k > 0){
            /* （部份积+截取被乘数的后N位*截取乘数的第M位），%kk再截取部分积 */
            mul = (mul + (number % (k * 10)) * (number % ll - number % (ll / 10))) % kk;
            k /= 10;  /* k为截取被乘数时的系数 */
            ll *= 10;
        }
        if (number == mul)  /* 判断若为自守数则输出 */
            printf(" %ld", number);
    }
    return (0);
}
