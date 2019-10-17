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

 /* Compile with  gcc -o cos-diagram cos-diagram.c -lm */
#include <stdio.h>
#include <math.h>
int main()
{
    double y;
    int x ,m, n, yy;
    for (yy=0; y<=20;yy++){
        y = 0.1 *yy;
        m = acos(1-y)*10;
        n = 45*(y-1)+31;
        for(x=0; x<=62;x++) 
            if (x==m && x==n)  printf("+");
            else if ( x==n )   printf("+");
            else if (x==m || x==62-m)  printf("*");
            else  printf(" ");
            printf("\n");
    }
}
