#include <iostream>
#include <string>

using namespace std;

#define MAX_SIZE (12)
#define NUM_OF_DAYS (365+1)

int const month[MAX_SIZE+1] = {
    0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

pair<int, int> const table[MAX_SIZE] ={
    {1, 19}, {2, 18}, {3, 20}, {4, 19}, {5, 20}, {6, 20},
    {7, 22}, {8, 22}, {9, 22}, {10, 22}, {11, 22}, {12, 21}
};

string const zodiac[MAX_SIZE] = {
    "Capricorn", "Aquarius", "Pisces", "Aries", "Taurus", "Gemini",
    "Cancer", "Leo", "Virgo", "Libra", "Scorpio", "Sagittarius"};

string name[NUM_OF_DAYS+1];

void init(void) {
    int cur, ptr;

    cur = ptr = 0;

    for (int m = 1; m <= 12; ++m) {
        for (int d = 1; d <= month[m]; ++d) {
            name[++cur] = zodiac[ptr];
            
            if (m == table[ptr].first && d == table[ptr].second) {
                ptr = (ptr + 1) % MAX_SIZE;
            }
        }
    }
}

int get_num_of_days(int m, int d) {
    int ret = d;

    for (int i = 1; i < m; i++) {
        ret += month[i];
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int YYYY, MM, DD;
    char dummy1, dummy2;

    init();
    cin >> YYYY >> dummy1 >> MM >> dummy2 >> DD;
    cout << name[get_num_of_days(MM, DD)] << '\n';

    return 0;
}