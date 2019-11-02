/*------------------------------------------------------------------------------
* File Name:   three-digit-nums20.c
* Purpose:     一个奇异的三位数
*
* Author:      Ke Wang
*
* Created:     2019-11-02
* Copyright:   (c) Ke Wang 2019
* Licence:     <your licence>
*-----------------------------------------------------------------------------*/

#include <stdio.h>

int main()
{
    int i,j,k;
    for (i=1; i<7; i++)     /* 穷举9进制的第一位数字 */
        for(j=0; j<7;j++)    /* 穷举9进制的第二位数字 */ 
            for(k=0; k<7;k++)   /* 穷举9进制的第三位数字 */ 
                if (i*9*9+j*9+k == i+j*7+k*7*7) {   /* 满足条件输出结果 */
                    printf("The special number with 3 digits is:");
                    printf("%d%d%d(7)=%d%d%d(9)=%d(10)\n",
                            k,j,i,i,j,k,i*9*9+j*9+k);
                }
    return (0);
}
