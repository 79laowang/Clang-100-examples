/*-----------------------------------------------------------------------------
* File Name: rabbits-birth.c
* Purpose: Fibonacci sequence 
* Classical question: There is a pair of rabbits, from the third
* month after birth, they give birth a pair of little rabbits, the lettle rabbit 
* grows to the third month After that, baby rabbits will give birth another pair 
* of little rabbits  every month. If the rabbits are not
* dead, what is the total number of rabbits per month?
*
* Author: Ke Wang
*
* Created Time: 2019年07月04日 星期四 14时37分02秒
* Mail: edward.wang@163.com
* Copyright: (c) Ke Wang 2019
* License: <your license>
-----------------------------------------------------------------------------*/

#include<stdio.h>
int main()
{
    long f1,f2;
    int i;
    f1=f2=1;
    printf("Rabbits pairs:\n");
    for(i=1;i<=20;i++)
    {
        printf("%12ld %12ld",f1,f2);
        if(i%2==0) printf("\n");/*Control ouput，each line four*/
        f1=f1+f2; /*The number of third month is equal to the sum of the first two months */
        f2=f1+f2; 
    }
    return(0);
}
