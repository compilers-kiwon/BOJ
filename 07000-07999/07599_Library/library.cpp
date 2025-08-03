#include <iostream>
#include <string>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for (;;) {
        string li;
        int f, c;

        cin >> li >> f;

        if (li == "#" && f == 0) {
            break;
        }

        cout << li << " Library\n";
        cin >> c;

        for (int i = 1; i <= c; i++) {
            int w;
            string label;

            cin >> w >> label;

            cout << "Book " << i <<
                ((w>=(2+label.length()*f))?" horizontal":" vertical") << '\n';
        }
    }

    return 0;
}