/*------------------------------------------------------------------------------
* File Name:   most-profit14.c
* Purpose:     怎样存钱利润最大 
*
* Author:      Ke Wang
*
* Created:     2019-10-30
* Copyright:   (c) Ke Wang 2019
* Licence:     <your licence>
*-----------------------------------------------------------------------------*/

#include <stdio.h>
#include <math.h>

/* Compile with cc -o most-profit14 most-profit14.c -lm  */
int main()
{
    int i8,i5,i3,i2,i1,n8,n5,n3,n2,n1;
    float max=0, term;
    /* 穷举全部可能的存款方式 */
    for(i8=0;i8<3;i8++)
        for(i5=0;i5<=(20-8*i8)/5;i5++)
            for(i2=0;i2<=(20-8*i8-5*i5-3*i3)/2;i2++){
                i1=20-8*i8-5*i5-3*i3-2*i2;
                /* 计算到期时的本利合计 */
                term=2000.0*pow((double)(1+0.0063*12),(double)i1)
                    *pow((double)(1+2*0.0065*12),(double)i2)
                    *pow((double)(1+3*0.0069*12),(double)i3)
                    *pow((double)(1+5*0.0075*12),(double)i5)
                    *pow((double)(1+8*0.0084*12),(double)i8);
                if (term>max) {
                    max=term;
                    n1=i1;
                    n2=i2;
                    n3=i3;
                    n5=i5;
                    n8=i8;
                }
            }
    printf("For maxinum profit, he should so save his money in a bank:\n");
    printf("  made fixed deposit for 8 year: %d times\n",n8);
    printf("  made fixed deposit for 5 year: %d times\n",n5);
    printf("  made fixed deposit for 3 year: %d times\n",n3);
    printf("  made fixed deposit for 2 year: %d times\n",n2);
    printf("  made fixed deposit for 1 year: %d times\n",n1);
    printf("                         Total: %.2f\n",max);
    return (0);
}
