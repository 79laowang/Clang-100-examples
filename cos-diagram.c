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

 /* Compile with  gcc -o cos-diagram cos-diagram.c -lm */
int main()
{
    double y;
    int x, m;
    for (y=1;y>=-1;y-=0.1)
    {
        m=acos(y)*10;
        for (x=1;x<m;x++) printf(" ");
        printf("*");
        for(;x<62-m;x++) printf(" ");
        printf("*\n");
    }
    return (0);
}
