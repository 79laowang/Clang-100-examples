/*------------------------------------------------------------------------------
* File Name:   catch-divide-fish15.c
* Purpose:     抓鱼和分鱼
*
* Author:      Ke Wang
*
* Created:     2019-10-31
* Copyright:   (c) Ke Wang 2019
* Licence:     <your licence>
*-----------------------------------------------------------------------------*/

#include <stdio.h>

int main()
{
    int n,i,x;
    int flag=1;           /* flag:控制标记 */
    for(n=6;flag;n++){    /* 采用试探的方法，逐步增大试探值n */
        for(x=n,i=1&&flag;i<=5;i++) 
            /* 判断是否可以按要求进行5次分配 */
            if((x-1)%5==0) x=4*(x-1)/5;
            else flag=0;   /* 若不能分配，设置标记flag=0，退出分配 */
        /* 若分配过程正常结束，则找到结果推出试探过程 */
        if(flag) break;
        else flag=1;     /* 进行试探下一个数 */
    }
    printf("Total number of fish catched = %d\n", n);
    return (0);
}
