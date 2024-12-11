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
    int i;

    for (i = 1; i < month; i++) {
        if(month == 2 && year % 4 == 0 && year % 100 != 0 || year % 400 == 0){
            day += day_tab + i + 1;
        } else {
             day += day_tab + i;
        }
    }
    return(day);
}

main() {
  int day, month, year, outcome;
  year = 2077
  month = 7;
  day = 15;

  outcome = day_of_year(year, month, day); 

  printf("%d", outcome);
  return;
}