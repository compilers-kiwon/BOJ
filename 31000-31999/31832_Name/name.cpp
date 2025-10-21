#include <iostream>
#include <string>

using namespace std;

#define MAX_LEN (10)

bool is_preferred_name(const string& name) {
    if (name.length() > MAX_LEN) {
        return false;
    }

    int num_of_lower, num_of_upper, num_of_digit;
    
    num_of_lower = num_of_upper = num_of_digit = 0;

    for (int i = 0; i < name.length(); i++) {
        char c = name[i];

        if (isdigit(c)) {
            num_of_digit++;
        } else {
            if (isalpha(c)) {
                if (islower(c)) {
                    num_of_lower++;
                } else {
                    num_of_upper++;
                }
            }
        }
    }

    if (name.length() == num_of_digit) {
        return false;
    }

    if (num_of_upper > num_of_lower) {
        return false;
    }

    return true;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;

    for (cin >> N; N > 0; N--) {
        string S;
        
        cin >> S;

        if (is_preferred_name(S) == true) {
            cout << S << '\n';
            break;
        }
    }

    return 0;
}