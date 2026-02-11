#include <iostream>
#include <string>

using namespace std;

const string vowel = "aeiouy";

#define is_vowel(c) (vowel.find((c))!=string::npos)

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    string str;

    for (cin >> N; N > 0; --N) {
        string w;
        cin >> w;
        str += w + " ";
    }

    str.pop_back();

    int cnt = 0;

    for (int i = str.length() - 1; i >= 0; --i) {
        char c = str[i];

        if (c == ' ' || is_vowel(c) == false) {
            cnt = (c==' ')?0:min(2, cnt + 1);
        } else {
            int tmp = cnt;

            cnt = 0;

            if (tmp == 2) {
                continue;
            }
        }

        cout << c;
    }

    return 0;
}