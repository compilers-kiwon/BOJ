#include <iostream>
#include <string>

using namespace std;

const string TARGET = "PAUL ";

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, pos;
    string str;

    cin >> N >> str;
    str.push_back(' '), pos = 0;

    for (int i = 0, cnt = 0; i <= N; i++) {
        if (TARGET[pos] == str[i]) {
            if (cnt % 2 != 0) {
                cout << "NO\n";
                return 0;
            }

            pos++, cnt = 0;
        } else {
            cnt++;
        }
    }

    cout << (pos==TARGET.length()?"YES":"NO") << '\n';
    return 0;
}