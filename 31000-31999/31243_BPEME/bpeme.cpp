#include <iostream>
#include <iomanip>

using namespace std;

#define NUM_OF_CARS (3)

#define MINUTES_OF_HOUR (60)
#define HOURS_OF_DAY (24)
#define MINUTES_OF_DAY (HOURS_OF_DAY*MINUTES_OF_HOUR)

int get(int sh, int sm, int eh, int em) {
    return (((eh * MINUTES_OF_HOUR) + em) - ((sh * MINUTES_OF_HOUR) + sm) + MINUTES_OF_DAY) % MINUTES_OF_DAY;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int min_m = MINUTES_OF_DAY;
    int max_m = 0;

    for (int i = 1; i <= NUM_OF_CARS; i++) {
        int hh1, mm1, hh2, mm2, t;

        cin>>hh1>>mm1>>hh2>>mm2;
        t = get(hh1, mm1, hh2, mm2);

        min_m = min(min_m, t);
        max_m = max(max_m, t);
    }

    cout<<min_m/60<<':'<<setw(2)<<setfill('0')<<min_m%60<<'\n';
    cout<<max_m/60<<':'<<setw(2)<<setfill('0')<<max_m%60<<'\n';

    return 0;
}