#include <iostream>
#include <vector>

using namespace std;

void convert_base(int num, int base, vector<int>& result) {
    for (; num > 0; num /= base) {
        result.push_back(num % base);
    }
}

void print_digits(const vector<int>& digits) {
    for (int i = digits.size() - 1; i >= 0; i--) {
        if (digits[i] < 10) {
            cout << digits[i];
        } else {
            cout << (char)('A' + (digits[i] - 10));
        }
    }

    cout << '\n';
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int  m, n;
    vector<int> d;

    cin >> m >> n;

    if (m == 0) {
        cout << "0\n";
    } else {
        convert_base(m, n, d);
        print_digits(d);
    }
    
    return 0;
}