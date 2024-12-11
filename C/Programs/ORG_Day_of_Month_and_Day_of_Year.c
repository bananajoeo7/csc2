static int day_tab[2] [13] ={
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, 
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

day_of_year (year, month, day) /*set day of year*/
int year, month, day; /*from month of day*/
{
    int i, leap;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

    for (i = 1; i< month; i++)
        day += day_tab[leap][i];
    return (day) ;
}

month-day(year, yearday, pmonth, pday) /*set month, day*/
int year, yearday, *pmonth, *pday; /*from day of year*/
{
    int i, leap;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    for (i = 1i yearday > day_tab[leap][i]; i++)
        yearday -= day_tab[leap][i];
    *pmonth = i;
    *pday = yearday;
}