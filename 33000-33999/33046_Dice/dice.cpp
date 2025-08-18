#include <iostream>

using namespace std;

#define NUM_OF_PLAYERS (4)
#define get_pos(s,n) (((s)+(n))%NUM_OF_PLAYERS)

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    const int p[NUM_OF_PLAYERS] = {1, 2, 3, 4};
    int A, B, C, D;

    cin >> A >> B >> C >> D;
    cout << p[get_pos(get_pos(0, (A + B) - 1), (C + D) -1)] << '\n';

    return 0;
}