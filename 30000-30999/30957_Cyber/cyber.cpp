#include <iostream>
#include <string>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, cnt[0x100];
    string str;

    cin >> N >> str;
    cnt['B'] = cnt['S'] = cnt['A'] = 0;

    for (int i = 0; i < N; i++) {
        cnt[str[i]]++;
    }

    if (cnt['B'] == cnt['S'] && cnt['S'] == cnt['A']) {
        cout << "SCU\n";
    } else {
        if (cnt['B'] == cnt['S']) {
            if (cnt['B'] > cnt['A']) {
                cout << "BS\n";
            } else {
                cout << "A\n";
            }
        } else if (cnt['B'] == cnt['A']) {
            if (cnt['B'] > cnt['S']) {
                cout << "BA\n";
            } else {
                cout << "S\n";
            }
        } else if (cnt['S'] == cnt['A']) {
            if (cnt['S'] > cnt['B']) {
                cout << "SA\n";
            } else {
                cout << "B\n";
            }
        } else {
            char c = 'B';

            if (cnt[c] < cnt['S']) {
                c = 'S';
            }

            if (cnt[c] < cnt['A']) {
                c = 'A';
            }

            cout << c << '\n';
        }
    }

    return 0;
}