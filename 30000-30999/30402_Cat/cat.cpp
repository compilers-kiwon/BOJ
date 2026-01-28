#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    char c;

    for (; cin >> c;) {
        if (c == 'w' || c == 'b' || c == 'g') {
            break;
        }
    }

    switch (c) {
        case 'w': cout << "chunbae\n"; break;
        case 'b': cout << "nabi\n"; break;
        case 'g': cout << "yeongcheol\n"; break;
        default: /* do nothing */; break;
    }

    return 0;
}