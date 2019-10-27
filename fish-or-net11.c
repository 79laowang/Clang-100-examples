/*------------------------------------------------------------------------------
* File Name:   fish-or-net11.c
* Purpose:     三天打鱼两天晒网
*
* Author:      Ke Wang
*
* Created:     2019-10-27
* Copyright:   (c) Ke Wang 2019
* Licence:     <your licence>
*-----------------------------------------------------------------------------*/

#include <stdio.h>

struct date {
    int year;
    int month;
    int day;
};

int days(struct date day)
{
    static int day_tab[2][13]=
    {{0,31,28,31,30,31,30,31,31,30,31,30,31,},
     {0,31,29,31,30,31,30,31,31,30,31,30,31,},
    };
    int i,lp;
    lp = (day.year%4==0 && day.year%100!=0) || day.year%400==0;
    for  (i=1;i<day.month;i++)
        day.day+=day_tab[lp][i];
    return(day.day);
}

int main()
{   
    struct date today,term;
    int yearday,year,day;
    printf("Enter year/month/day:");
    scanf("%d/%d/%d",&today.year,&today.month,&today.day);
    term.month = 12;
    term.day = 31;
    for(yearday=0,year=1990;year<today.year;year++){
        term.year=year;
        yearday+=days(term);
    }
    yearday+=days(today);
    day = yearday%5;
    if (day>0&&day<4) printf("He was fishing at that day.\n");
    else printf("He was sleeping at thay day.\n");
    return (0);
}
