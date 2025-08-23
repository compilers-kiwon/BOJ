#include <iostream>

using namespace std;

const int NUM_OF_LAPS = 5;
const int MAX_TIME = 1800;
const int AVAILABLE_TIME = 300;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int sum = 0;

    for (int i = 1; i < NUM_OF_LAPS; i++) {
        int t;
        cin >> t;
        sum += t;
    }

    cout << (((sum+AVAILABLE_TIME)<=MAX_TIME)?"Yes":"No") << '\n';

    return 0;
}