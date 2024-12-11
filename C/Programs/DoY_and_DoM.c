#include <stdio.h>

int *day_tab[13];
    day_tab[0] = 0;
    day_tab[1] = 31;
    day_tab[2] = 28;
    day_tab[3] = 31;
    day_tab[4] = 30;
    day_tab[5] = 31;
    day_tab[6] = 30;
    day_tab[7] = 31;
    day_tab[8] = 31;
    day_tab[9] = 30;
    day_tab[10] = 31;
    day_tab[11] = 30;
    day_tab[12] = 31;

day_of_year (year, month, day) /*set day of year*/
int year, month, day; /*from month of day*/
{
    for (i = 1; i < month; i++) {

    }
    return(day);
}