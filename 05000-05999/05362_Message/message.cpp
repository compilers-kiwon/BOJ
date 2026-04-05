#include <iostream>
#include <string>

using namespace std;

const string corrupted = "iiing";
const string original = "th";

void restore_message(const string& src, string& dst) {
    for (int i = 0; i < src.length(); ++i) {
        dst.push_back(src[i]);

        if (dst.length() >= corrupted.length() &&
                dst.substr(dst.length() - corrupted.length()) == "iiing") {
            dst.erase(dst.length() - corrupted.length());
            dst += original;
        }
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for (;;) {
        string received, restored;

        getline(cin, received);

        if (received.empty()) {
            break;
        }

        restore_message(received, restored);
        cout << restored << '\n';
    }

    return 0;
}