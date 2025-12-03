#include <iostream>
#include <string>

using namespace std;

#define MAX_SIZE (4)

const string category[MAX_SIZE] =
    {"Foundation", "Claves", "Veritas", "Exploration"};

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string code;

    cin >> code;

    for (int i = 0; i < MAX_SIZE; i++) {
        if (category[i].front() == code.front()) {
            cout << category[i] << '\n';
        }
    }

    return 0;
}