#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;

int main(void) {
    auto now = chrono::system_clock::now();
    time_t t = chrono::system_clock::to_time_t(now);

    /*
    struct tm
    {
        int tm_sec;   // seconds after the minute - [0, 60] including leap second
        int tm_min;   // minutes after the hour - [0, 59]
        int tm_hour;  // hours since midnight - [0, 23]
        int tm_mday;  // day of the month - [1, 31]
        int tm_mon;   // months since January - [0, 11]
        int tm_year;  // years since 1900
        int tm_wday;  // days since Sunday - [0, 6]
        int tm_yday;  // days since January 1 - [0, 365]
        int tm_isdst; // daylight savings time flag
    };
    */
    tm utc_tm = *gmtime(&t);
    
    cout << 1900 + utc_tm.tm_year << '\n';
    cout << 1 + utc_tm.tm_mon << '\n';
    cout << utc_tm.tm_mday << '\n';

    return 0;
}