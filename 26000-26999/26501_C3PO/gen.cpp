#include <iostream>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for (int cur = 0;;) {
        char c;
        
        if ((c = getchar()) == EOF) {
            break;
        }

        if (cur != c) {
            char offset = (cur>c)?'-':'+';

            do {
                cout << offset;
                cur += (offset=='-')?-1:1;
            } while (cur != c);
        }

        cout << ".\n";
    }

    return 0;
}