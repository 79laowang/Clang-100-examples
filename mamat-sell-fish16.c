/*------------------------------------------------------------------------------
* File Name:   mamat-sell-fish16.c
* Purpose:     买买提卖鱼
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
    int i,j,x;
    int n=0;    /* 标志变量 */
    for(i=23;n==0;i+=2){    /* 控制试探的过程和步长 */
        for(j=1,x=i;j<=4&&x>=11;j++)  /* 完成出售四次操作 */
            if((x+1)%(j+1)==0)  /* 若满足整除条件则进行世界的出售操作 */
                x-=(x+1)/(j+1);
            else{      /* 否则停止计算 */
                x=0;
                break;
            }
        if(j==5&&x==11){  /* 若第四次余下的11条则满足条件,输出结果 */
            printf("There are %d fishes at first.\n",i);
            n=1;    /* 控制退出试探过程 */
        }
    }
    return (0);
}
