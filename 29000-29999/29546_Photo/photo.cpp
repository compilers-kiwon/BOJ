#include <iostream>
#include <queue>

using namespace std;

#define MAX_SIZE (1000+1)

int n, m, score[MAX_SIZE];
string name[MAX_SIZE];

void get_names(void) {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> name[i];
    }
}

void print(void) {
    cin >> m;

    for (int i = 1; i <= m; i++) {
        int l, r;
        cin >> l >> r;

        for (; l <= r; l++) {
            cout << name[l] << '\n';
        }
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    get_names();
    print();

    return 0;
}