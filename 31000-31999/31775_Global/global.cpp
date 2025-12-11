#include <iostream>
#include <string>

using namespace std;

const int NUM_OF_STR = 3;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string s = "lkp";

    for (int i = 1; i <= NUM_OF_STR; i++) {
        string S;
        size_t pos;

        cin >> S;
        pos = s.find(S.front());

        if (pos != string::npos) {
            s.erase(pos, 1);
        }
    }

    cout << (s.empty()?"GLOBAL":"PONIX") << '\n';

    return 0;
}