#include <iostream>
#include <string>

using namespace std;

#define DUMMY_CHR ('a')
#define isupper(c) ('A'<=(c)&&(c)<='Z')

string get_new_code(const string& old) {
    string ret, num;
    int sum = 0, sign = 1;

    for (size_t i = 0; i < old.length(); i++) {
        char c = old[i];

        if (isdigit(c)) {
            num.push_back(c);
        } else {
            if (isalpha(c)) {
                if (isupper(c)) {
                    ret.push_back(c);
                }
            }

            if (!num.empty()) {
                sum += stoi(num) * sign;
                sign = 1, num.clear();
            }

            if (c == '-') {
                sign = -1;
            }
        }
    }

    return (ret + to_string(sum));
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;

    for (cin >> N; N > 0; N--) {
        string code;
        cin >> code;
        
        code.push_back(DUMMY_CHR);
        cout << get_new_code(code) << '\n';
    }

    return 0;
}