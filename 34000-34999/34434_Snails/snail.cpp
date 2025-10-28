#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef long long int int64;

#define chr2int(c) ((int)((c)-'0'))

void get_sequence(vector<int64>& seq) {
    string s;
    int64 num;

    getline(cin, s);
    s.push_back(' '), num = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            seq.push_back(num);
            num = 0;
        } else {
            num = (num * 10) + (int64)chr2int(s[i]); 
        }
    }
}

bool is_nautilus(const vector<int64>& s, vector<int64>& n) {
    for (int pos = n.size(); n.size() < s.size(); pos++) {
        int64 sum = n[pos-1] + n[pos-2] + n[pos-3] + n[pos-4];
        n.push_back(sum);
    }

    for (int i = 0; i < s.size(); i++) {
        if (s[i] != n[i]) {
            return false;
        }
    }

    return true;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;
    string s;
    vector<int64> nautilus = {0, 1, 2, 3};

    getline(cin, s);
    n = stoi(s);

    for (int i = 1; i <= n; i++) {
        vector<int64> numbers;
        get_sequence(numbers);
        cout << (is_nautilus(numbers, nautilus)?"NAUTILUS":"SNAIL") << '\n';
    }

    return 0;
}