#include <iostream>
#include <cmath>

using namespace std;

#define MAX_NUM (10000)
#define MAX_SIZE (100000)

#define POSSIBLE (1)
#define IMPOSSIBLE (0)

int N, Q, A[MAX_SIZE+1];
int cnt_of_numbers[MAX_NUM+1];

void input(void) {
    cin >> N >> Q;

    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
        ++cnt_of_numbers[A[i]];
    }
}

int find_multiplication(int x) {
    if (x == 1) {
        return (cnt_of_numbers[1]>=2?POSSIBLE:IMPOSSIBLE);
    }

    if (x <= MAX_NUM) {
        if (cnt_of_numbers[1] >= 1 && cnt_of_numbers[x] >= 1) {
            return POSSIBLE;
        }
    }
    
    for (int i = (x%2==0)?2:3; i <= MAX_NUM; i += 2) {
        if (x % i != 0) {
            continue;
        }

        int j = x / i;

        if (j > MAX_NUM) {
            continue;
        }

        if (i == j) {
            if (cnt_of_numbers[i] >= 2) {
                return POSSIBLE;
            }
        } else {
            if (cnt_of_numbers[i] >= 1 && cnt_of_numbers[j] >= 1) {
                return POSSIBLE;
            }
        }
    }

    return IMPOSSIBLE;
}

void do_query(void) {
    int op, x;

    cin >> op >> x;

    if (op == 2) {
        --cnt_of_numbers[A[x]];
        ++cnt_of_numbers[0];
        A[x] = 0;
    } else {
        if (N == 1) {
            cout << IMPOSSIBLE << '\n';
        } else if (x == 0) {
            cout << ((cnt_of_numbers[0]>=1)?
                        POSSIBLE:IMPOSSIBLE) << '\n';
        } else {
            cout << find_multiplication(x) << '\n';
        }
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();

    for (int i = 1; i <= Q; ++i) {
        do_query();
    }

    return 0;
}