#include <iostream>
#include <cstring>

using namespace std;

#define MAX_SIZE (1000)

typedef struct {
    int top, sheets[MAX_SIZE];
} Pile;

Pile p[MAX_SIZE+1];

int get_pile_state(void) {
    int N, P;

    cin >> N >> P;

    for (int i = 1; i <= P; i++) {
        cin >> p[i].top;

        for (int s = 0; s < p[i].top; s++) {
            cin >> p[i].sheets[s];
        }
    }

    return P;
}

void move(int src, int dst, int num_of_sheets) {
    p[src].top -= num_of_sheets;

    for (int i = 0; i < num_of_sheets; i++) {
        p[dst].sheets[p[dst].top++] =
            p[src].sheets[p[src].top + i];
    }
}

void print(int num_of_piles) {
    for (int i = 1; i <= num_of_piles; i++) {
        if (p[i].top == 0) {
            cout << '\n';
            continue;
        }

        for (int s = 0; s < p[i].top; s++) {
            cout << p[i].sheets[s] <<
                    ((s==(p[i].top-1))?'\n':' ');
        }
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int M;
    int num_of_files = get_pile_state();

    for (cin >> M; M > 0; M--) {
        int s, d, n;
        cin >> s >> d >> n;
        move(s, d, n);
    }

    print(num_of_files);

    return 0;
}