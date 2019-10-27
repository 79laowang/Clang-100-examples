/*------------------------------------------------------------------------------
* File Name:   cos-diagram.c
* Purpose:     Drawing cosine diagram 
*
* Author:      Ke Wang
*
* Created:     2019-07-08
* Copyright:   (c) Ke Wang 2019
* Licence:     <your licence>
*-----------------------------------------------------------------------------*/

#include <stdio.h>
#include <math.h>

#define WIDTH 62

 /* Compile with  gcc -o cos-diagram cos-diagram.c -lm */
int main()
{
    double y;   /* 列 */
    int x, m;   /* x为行 */
    for (y=1;y>=-1;y-=0.1)   /* y为列方向，值从1到-1，步长0.1 */
    {
        m=acos(y)*10;    /*计算出y对应的弧度m,乘10为图形放大倍数 */
        for (x=1;x<m;x++) printf(" ");
        printf("*");   /* 控制打印左侧的*号 */
        for(;x<WIDTH-m;x++) printf(" ");
        printf("*\n"); /* 控制打印同一行对应右侧的*号 */
    }
    return (0);
}
