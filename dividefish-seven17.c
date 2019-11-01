/*------------------------------------------------------------------------------
* File Name:   dividefish-seven17.c
* Purpose:     平分七筐鱼
*
* Author:      Ke Wang
*
* Created:     2019-11-01
* Copyright:   (c) Ke Wang 2019
* Licence:     <your licence>
*-----------------------------------------------------------------------------*/

#include <stdio.h>

int main()
{
    int a[3][3],count;
    int i,j,k,m,n,flag;
    printf("It exists possible distribution plans:\n");
    for(i=0;i<=3;i++){   /* 试探第一个人筐满a[0][0]的值，满筐数不能>3 */
        a[0][0]=i;
        for(j=i;j<=7-i && j<=3;j++){ /* 试探第二个人筐满a[1][0]的值，满筐数不能>3    */
            a[1][0]=j;
            if(((a[2][0])=7-j-a[0][0])>3) continue;  /* 第三个人满筐数不能>3 */
            if(a[2][0]<a[1][0]) break;
            /* 要求后一个人分的满筐数>=前一个人，以排除重复情况 */
            for(k=1;k<=5;k+=2){
                a[0][1]=k;  /* 试探半筐a[0][1]的值，半筐数为奇数 */
                for(m=1;m<7-k;m+=2){  /* 试探半筐a[1][1]的值，半筐数为奇数 */ 
                    a[1][1]=m;
                    a[2][1]=7-k-m;
                    for(flag=1,n=0;flag && n<3;n++)
                        /* 判断每个人分到的鱼是否为3.5筐，flag为满足题意的标记变量 */
                        if(a[n][0]+a[n][1]<7 && a[n][0]*2+a[n][1]==7)
                            a[n][2]=7-a[n][0]-a[n][1];  /* 计算应得到的空筐数量  */
                        else flag=0;     /* 不符合的标记为0 */
                    if(flag) {    /* 符合条件的则输出每个人的分配情况 */
                        printf("No.%d            Full basket|Semi-basket|Empty\n",++count);
                        for(n=0;n<3;n++)
                            printf("    fisher %c:        %d            %d        %d\n",
                                    'A'+n,a[n][0],a[n][1],a[n][2]);
                        
                    }
                }
            }
        }
    }
    return (0);
}
