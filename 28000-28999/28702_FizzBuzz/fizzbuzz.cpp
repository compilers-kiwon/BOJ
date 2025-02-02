#include <iostream>
#include <string>

using namespace std;

#define NUM_OF_STR (3)

bool is_number(const string& str) {
    for (size_t i = 0; i < str.length(); i++) {
        if (isdigit(str[i]) == false) {
            return false;
        }
    }

    return true;
}

void input(string str[], string& c) {
    for (size_t i = 1; i <= NUM_OF_STR; i++) {
        cin>>str[i];
        c += str[i];
    }
}

int find_number(const string str[]) {
    int ret = 0;

    for (size_t i = 1; i <= NUM_OF_STR; i++) {
        if (is_number(str[i]) == true) {
            ret = stoi(str[i]) + NUM_OF_STR + 1 - i;
            break;
        }
    }

    return ret;
}

string get_type(int num) {
    if ((num % 3) == 0 && (num % 5) == 0) {
        return "FizzBuzz";
    }

    if ((num % 3) == 0 && (num % 5) != 0) {
        return "Fizz";
    }

    if ((num % 3) != 0 && (num % 5) == 0) {
        return "Buzz";
    }

    return to_string(num);
}

int main (void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int num;
    string in[NUM_OF_STR+1], concatenated;

    input(in, concatenated);

    if ((num = find_number(in)) != 0) {
        cout<<get_type(num)<<'\n';
    } else {
        for (int i = 1; ; i++) {
            string cur;

            for (int d = 0; d <= 2; d++) {
                cur += get_type(i + d);
            }

            if (concatenated == cur) {
                cout<<get_type(i + NUM_OF_STR)<<'\n';
                break;
            }
        }
    }

    return 0;
}