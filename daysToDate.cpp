//since 19700101
int daysToDate(int days)
{
    int year = (days += 719468) / 146097 * 400;
    int y1 = (days %= 146097) >= 146000 ? 399 : (days / 365.249 + 0.0021 + days / 36524 / 400.0);
    int mon = ((days -= (y1 * 365 + y1 / 4 - y1 / 100)) * 12 + 4) / 367;
    days -= (mon * 367 + 7) / 12;
    if ((mon += 2) >= 12)
        mon -= 12,year += 1;
    return (year + y1) * 10000 + (mon + 1) * 100 + (days + 1);
}
#include <iostream>
#include <ctime>
int main() {
    for (size_t i = 0; i < 365 * 1000; i++)
    {
        std::time_t timestamp = i * 24 * 60 * 60;
        std::tm* local_time = std::localtime(&timestamp);
        int year = local_time->tm_year + 1900;
        int month = local_time->tm_mon + 1;
        int day = local_time->tm_mday;
        int date = daysToDate(i);
        if (date != year * 10000 + month * 100 + day)
        {
            printf("error");
            break;
        }
    }
    printf("end");
    return 0;
}
