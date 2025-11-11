#include <iostream>
#include <string>

using namespace std;

typedef unsigned long long uint64;

const string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    uint64 N;
    string str, decoded;

    cin >> N >> str;

    for (uint64 i = 0; i < N; i++) {
        uint64 cur_pos = letters.find(str[i]);
        uint64 decoded_pos = (cur_pos + (1ULL << i)) % (uint64)letters.size();
        decoded.push_back(letters[decoded_pos]);
    }

    cout << decoded << '\n';
    return 0;
}