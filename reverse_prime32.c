/*------------------------------------------------------------------------------
* File Name:   reverse_prime32.c
* Purpose:     可逆素数 
*
* Author:      Ke Wang
*
* Created:     2019-11-10
* Copyright:   (c) Ke Wang 2019
* Licence:     <your licence>
*-----------------------------------------------------------------------------*/

/* compliled with gcc  -o reverse_prime32 reverse_32.c -lm */
#include <stdio.h>
#include <math.h>

int ok (int);
int num (int);

int ok (int number) {
    int i, j;
    if (number % 2 == 0) return (0);  // 判断整数number是否为素数
    j = sqrt((double)number) + 1;   //取整数的平方根为判断的上限
    for (i =3; i <= j; i += 2)      //若为素数返回1,否则返回0
        if (number % i == 0) return (0);
    return (1);
}

int num (int number)
{
    int i, j;
    if (! ok(number)) return (0);  //判断整数是否为素数
    for (i = number, j = 0; i > 0; i /= 10)  // 按位将整数倒过来，产生反序数
        j = j * 10 + i % 10;
    if (number < j) {  //若原数小云反序数
        if (!ok(j)) return (0);  //则判断对应的反序数是否为素数
        else return (1);   //若是可逆素数，返回1
    } else return (0);  //不是，返回0

}

int main()
{
    int i, count;
    printf("There are invertable primes with 4 digits!\n");
    for (count = 0,  i = 1001; i < 9999; i += 2) // 穷举全部奇数
        if (num(i))   // 若为可逆素数，输出
            printf(count % 9 ?  "%3d:%d " : "%3d:%d\n", ++count, i);
    return (0);
}
