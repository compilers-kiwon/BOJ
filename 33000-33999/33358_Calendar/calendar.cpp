#include <iostream>

using namespace std;

typedef enum {
    Mo = 0,
    Tu = 1,
    We = 2,
    Th = 3,
    Fr = 4,
    Sa = 5,
    Su = 6,
    MAX_DAY = 7
} Day;

#define February (2)
#define LAST_MONTH (12)
#define START (1)

const int num_of_days[12+1] = {
    0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

int is_leap_year(int yy) {
    return (((yy%400)==0 || (yy%4==0 && yy%100!=0))?1:0);
}

int get_end_day(int yy, int mm) {
    int tail = (mm==February&&is_leap_year(yy))?1:0;
    return (num_of_days[mm] + tail);
}

bool get_date_of_tomorrow(int& yy, int& mm, int& dd, int& d) {
    bool ret = false;

    ++dd;
    d = (d+1)%MAX_DAY;

    if (dd > get_end_day(yy, mm)) {
        dd = START;
        
        if(++mm > LAST_MONTH) {
            mm = START;
            ++yy;
        }
    }

    if ((d == Mo) || (dd == START)) {
        ret = true;
    }

    return ret;
}

int count_num_of_weeks(int cur_year) {
    int ret = 0;
    int yy = 1969;
    int mm = 12;
    int dd = 31;
    int col = We;

    for (; yy <= cur_year;) {
        if(get_date_of_tomorrow(yy, mm, dd, col) && (yy == cur_year)) {
            ret++;
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    
    int year;
    cin>>year;

    cout<<count_num_of_weeks(year)<<'\n';
    return 0;
}