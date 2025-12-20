#include <iostream>
#include <string>
#include <vector>

using namespace std;

void make_bugers(vector<string>& bugers, int num_of_bugers, int p, int c) {
    for (int i = 0; i < num_of_bugers; i++, p--) {
        bugers.push_back("a");
    }

    for (; p > 0 && c > 0;) {
        for (int i = 0; i < num_of_bugers && p > 0 && c > 0; i++, p--, c-- ) {
            bugers[i] += "ba";
        }
    }
}

void print_bugers(const vector<string>& bugers) {
    cout << bugers.size() << '\n';

    for (int i = 0; i < bugers.size(); i++) {
        cout << bugers[i] << '\n';
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int A, B;

    cin >> A >> B;

    if (!(B < A && A <= 2 * B)) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";

    vector<string> bugers;
    int num_of_bugers = A - B;

    make_bugers(bugers, num_of_bugers, A, B);
    print_bugers(bugers);

    return 0;
}