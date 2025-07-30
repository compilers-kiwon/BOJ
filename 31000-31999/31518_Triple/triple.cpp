#include <iostream>
#include <vector>

using namespace std;

bool find_num(const vector<int>& numbers, int num) {
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] == num) {
            return true;
        }
    }

    return false;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;

    cin >> n;
    
    for (int i = 0; i < 3; i++) {
        vector<int> digits;

        for (int j = 0; j < n; j++) {
            int d;
            cin >> d;
            digits.push_back(d);
        }

        if (find_num(digits, 7) == false) {
            cout << "0\n";
            return 0;
        }
    }

    cout << "777\n";
    return 0;
}