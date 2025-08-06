#include <iostream>

using namespace std;

#define MAX_SIZE (200000+1)
#define MAX_VAL (7)
#define TBD (-1)
#define NUM_OF_OPERATIONS (2)

#define MOD(n) ((n)%MAX_VAL)

typedef pair<char, int> Operation;

int T, N;
Operation op[MAX_SIZE][NUM_OF_OPERATIONS];

bool simulate(int num_of_operations, char cur_available) {
    if (num_of_operations > N) {
        return (cur_available&(0x01)==0x01);
    }

    char next_available = 0x00;

    for (int b = 0; b < MAX_VAL; b++) {
        if ((cur_available & (1<<b)) == 0) {
            continue;
        }

        for (int i = 0; i < NUM_OF_OPERATIONS; i++) {
            int result;

            if (op[num_of_operations][i].first == '+') {
                result = b + op[num_of_operations][i].second;
            } else {
                result = b * op[num_of_operations][i].second;
            }

            next_available |= (1<<MOD(result));
        }
    }

    return simulate(num_of_operations + 1, next_available);
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for (cin >> T; T > 0; T--) {
        cin >> N;

        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < NUM_OF_OPERATIONS; j++) {
                cin >> op[i][j].first >> op[i][j].second;
            }
        }

        cout << (simulate(1, 1 << 1)?"LUCKY":"UNLUCKY") << '\n';
    }

    return 0;
}