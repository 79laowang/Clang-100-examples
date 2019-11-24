/*------------------------------------------------------------------------------
* Fi1e Name:   prime_cube35.c
* Purpose:     素数魔方 
*
* Author:      Ke Wang
*
* Created:     2019-11-23
* Copyright:   (c) Ke Wang 2019
* Licence:     <your licence>
*-----------------------------------------------------------------------------*/

#include <stdio.h>
#include <math.h>

int number[210][5];
int select[100];
int array[4][5];
int count;
int selecount;
int larray[2][200];
int lcount[2];

int ok(int number)
{
    int i, j;
    if (number % 2 == 0) return (0);
    j = sqrt((double) number) + 1;
    for (i = 3; i <= j; i += 2)
        if (number % i == 0) return (0);
    return (1);
}

int num(int number)
{
    int j;
    if (! ok(number)) return (0);
    for (j = 0; number > 0; number /= 10)
        j = j * 10 + number % 10;
    if (! ok(j)) return (0);
    return (1);
}

void process(int i)
{
    int j, num;
    num = number[i][0];
    for (j = 4; j >= 1; j--, num /= 10)
        number[i][j] = num % 10;

}

void copy_num(int i)
{
    int j;
    for (j = 1; j <= 4; j++)
        array[i][j] = number[array[i][0]][j];
}

int comp_num(int n)
{
    static int ii;
    static int jj;
    int i, num, k, *p;
    int *pcount;
    switch (n) {
        case 2: pcount = &lcount[0]; p = &ii;break;
        case 3: pcount = &lcount[1]; p = &jj;break;
        default: return (0);
    }
    for (i = 1; i <= 4; i++) {
        for (num = 0, k = 0; k <= n; k++)
            num = num * 10 + array[k][i];
        if (num <= larray[n-2][*p])
            for (; *p >= 0 && num < larray[n-2][*p]; (*p)--);
        else
            for (; *p < *pcount && num > larray[n-2][*p]; (*p)++);
        if (*p < 0 || *p >= *pcount) { 
            *p = 0;
            return (0);
        }
        if (num != larray[n-2][*p])
            return (0);
    }
    return (1);
}

int find0(int num)
{
    static int j;
    if (num <= number[j][0])
        for (; j >= 0 && num < number[j][0]; j--);
    else
        for (; j < count && num > number[j][0]; j++);
    if (j < 0 || j >= count) {j = 0; return (0);}
    if (num == number[j][0]) 
        return (1);
    else
        return (0);
}

int find1(int i)
{
    int num, j;
    for (num = 0, j = 0; j < 4; j++)
        num = num * 10 + array[j][i];
    return (find0(num));
}

int find2(void)
{
    int num1, num2, j, i;
    for (num1 = 0, j = 0; j < 4; j++)
        num1 = num1 * 10 + array[j][j+1];
    for (num2 = 0, j = 0, i = 4; j < 4; j++, i--)
        num2 = num2 * 10 + array[j][i];
    if (find0(num1))
        return (find0(num2));
    else
        return (0);
}

void p_array(void)
{
    int i, j;
    for (i = 0; i < 4; i++) {
        for (j = 1; j <= 4; j++)
            printf("%6d", array[i][j]);
        printf("\n");
    }
}

int main()
{
    int i, k, flag, cc = 0, i1, i4;
    printf("There are magic squares with invertable primes as follow:\n");
    for (i = 1001; i < 9999; i += 2) {
        k = i / 1000;
        if ( k % 2 != 0 && k != 5 && num(i)) {
            number[count][0] = i;
            process(count++);
            if (number[count-1][2] % 2 != 0 &&
                    number[count-1][3] % 2 != 0 &&
                    number[count-1][2] != 5 &&
                    number[count-1][3] != 5)
                select[selecount++] = count - 1;
        }
    }
    larray[0][lcount[0]++] = number[0][0] / 100;
    larray[1][lcount[1]++] = number[0][0] / 10;
    for (i = 1; i < count; i++) {
        if (larray[0][lcount[0] - 1] != number[i][0] / 100)
            larray[0][lcount[0]++] = number[i][0] / 100;
        if (larray[1][lcount[1] - 1] != number[i][0] / 10)
            larray[1][lcount[1]++] = number[i][0] / 10;
    }
    for (i1 = 0; i1 < selecount; i1++) {
        array[0][0] = select[i];
        copy_num(0);
        for (array[1][0] = 0; array[1][0] < count; array[1][0]++) {
            copy_num(1);
            if (! comp_num(2))
                continue;
            for (array[2][0] = 0; array[2][0] < count; array[2][0]++){
                copy_num(2);
            }
            if (! comp_num(3))
                continue;
            for (i4 = 0; i4 < selecount; i4++) {
                array[3][0] = select[i4];
                copy_num(3);
                for (flag = 1, i = 1;flag && i <=4; i++) 
                    if (! find1(i)) flag = 0;
                if (flag && find2()) {
                    printf("No.%d\n", ++cc);
                    p_array();
                }
            }
        }
    }
    return (0);
}
