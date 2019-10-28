/*------------------------------------------------------------------------------
* File Name:   cos-line-diagrm.c
* Purpose:    
*
* Author:      Ke Wang
*
* Created:     2019-10-17
* Copyright:   (c) Ke Wang 2019
* Licence:     <your licence>
*-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>
int main()
{
    double y;
    int x ,m, n, yy;
    for (yy=0; y<=20;yy++){
        /* 对于每一个y坐标进行计算并在一行中打印图形 */
        y = 0.1 *yy;        /* y:屏幕行方向坐标 */
        m = acos(1-y)*10;   /* m:cos(x)曲线上y点对应的屏幕列坐标  */
        n = 45*(y-1)+WIDTH/2;    /* n:直线上y点对应的列坐标   */
        for(x=0; x<=WIDTH;x++)    /* x:屏幕列方向坐标 */
            if (x==m && x==n)  printf("+");   /* 直线与cos(x)相交时打印'+' */
            else if ( x==n )   printf("+");   /* 打印不相交时直线'+'图形  */
            else if (x==m || x==WIDTH-m)  printf("*");   /* 打印不相交时cos(x)'*'图形  */
            else  printf(" ");    /*  其他情况打印空格占位  */
            printf("\n");
    }
    return (0);
}
