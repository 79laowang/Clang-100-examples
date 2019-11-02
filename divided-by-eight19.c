/*------------------------------------------------------------------------------
* File Name:   divided-by-eight19.c
* Purpose:     8除不尽的自然数
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
    int i;
    for(i=0;;i++)  /* 试探商的值 */
        /* i逆推判断所取的当前i的值是否满足关系式 */
        if (((i*8+7)*8+1)*8+1==(34*i+15)*17+4){
            /* 满足输出结果 */
            printf("The required number is:%d\n",(34*i+15)*17+4);
            break;
        }
    return (0);
}
