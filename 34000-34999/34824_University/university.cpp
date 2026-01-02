#include <iostream>
#include <string>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;

    for (cin >> N; N > 0; N--) {
        string s;

        cin >> s;

        if (s == "yonsei") {
            cout << "Yonsei Won!\n";
            break;
        }

        if (s == "korea") {
            cout << "Yonsei Lost...\n";
            break;
        }
    }

    return 0;
}