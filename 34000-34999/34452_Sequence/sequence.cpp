#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

#define SUCCESS (0)

bool place_anywhere(const string& card) {
    return (card == "Jd" || card == "Jc");
}

bool remove_any_token(const string& card) {
    return (card == "Jh" || card == "Js");
}

bool is_special_card(const string& card) {
    return (place_anywhere(card) || remove_any_token(card));
}

int simulate(void) {
    int N;
    unordered_map<string, int> placed;

    for (cin >> N; N > 0; N--) {
        int n;
        string card, pos;
        char play;

        cin >> n >> card >> play >> pos;

        if (is_special_card(card) == true) {
            if (place_anywhere(card) == true) {
                if (play != 'P') {
                    return n;
                }

                if (placed[pos] != 2) {
                    placed[pos]++;
                } else {
                    return n;
                }
            } else {
                if (play != 'R') {
                    return n;
                }

                if (placed[pos] != 0) {
                    placed[pos]--;
                } else {
                    return n;
                }
            }
        } else {
            if (play != 'P' || card != pos || placed[pos] == 2) {
                return n;
            } else {
                placed[pos]++;
            }
        }
    }

    return SUCCESS;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int result = simulate();

    if (result == SUCCESS) {
        cout << "VALID GAME\n";
    } else {
        cout << "INVALID " << result << '\n';
    }

    return 0;
}