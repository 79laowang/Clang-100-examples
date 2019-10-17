/*------------------------------------------------------------------------------
* File Name:   draw-circle.c
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

/* Compile with gcc -o draw-circle draw-circle.c -lm */
int main()
{
	double y;
	int x, m;

	for (y=10; y>=-10; y--){
		m = 2 * sqrt(100-y*y);
		for (x=1; x<30-m; x++) printf(" ");
		printf("*");
		for (; x<30+m; x++) printf(" ");
		printf("*\n");
	}
}
