#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<string, int> table;

void read_items(int num_of_items) {
    for (int i = 1; i <= num_of_items; i++) {
        string a;
        int b;

        cin >> a >> b;
        table[a] = b * 105;
    }
}

int check_purchases(int num_of_purchases) {
    int ret = 0;

    for (int i = 1; i <= num_of_purchases; i++) {
        string c;
        int d;

        cin >> c >> d;

        if (table[c] < (d * 100)) {
            ret++;
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, M;

    cin >> N >> M;
    read_items(N);
    cout << check_purchases(M) << '\n';

    return 0;
}