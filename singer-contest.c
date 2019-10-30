/*------------------------------------------------------------------------------
* File Name:   singer-contest.c
* Purpose:     4. 歌星大赛 
*
* Author:      Ke Wang
*
* Created:     2019-10-17
* Copyright:   (c) Ke Wang 2019
* Licence:     <your licence>
*-----------------------------------------------------------------------------*/

#include <stdio.h>

int main()
{
    int integer, i, max, min, sum;
    max=-32768;
    min=32768;
    sum=0;
    for (i=1; i<=10; i++){
         printf("Input number %d=",i);
         scanf("%d",&integer);
         sum+=integer;
         if (integer > max) max = integer;  /* 比大小，筛选出最高分 */
         if (integer < min) min = integer;  /* 比大小，筛选出最低分 */
    }
    printf("Canceled max score: %d\nCanceled min score: %d\n", max, min);
    printf("Average score: %d\n",(sum - max - min)/8);    /* 输出结果 */
    return (0);
}
