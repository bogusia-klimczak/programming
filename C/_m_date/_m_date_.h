#ifndef _M_DATE_H_

#define _M_DATE_H_

typedef struct date
{
    int seconds, minutes, hours, mday, wday, mon, year, yday, _0_;
    char month[10], weekday[10];
} date;

date getdate(int timestamp);

int time();

#endif