#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

#define NUM_OF_HOURS (24)

unordered_map<string, int[NUM_OF_HOURS]> time_table;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, max_cnt, best_time;
    string best_day;

    for (cin >> N, max_cnt = 0; N > 0; N--) {
        string name, day;
        int X;

        cin >> name >> day >> X;

        for (int i = 1; i <= X; i++) {
            int H;

            cin >> H;
            
            if(++time_table[day][H] > max_cnt) {
                max_cnt = time_table[day][H];
                best_day = day;
                best_time = H;
            }
        }
    }

    cout << "Your professor should host office hours " <<
            best_day << " @ " << ((best_time<10)?"0":"") << best_time << ':' << "00\n";

    return 0;
}