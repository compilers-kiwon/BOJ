#include <iostream>
#include <string>

using namespace std;

const int num_of_strokes[] = {
    3, 2, 1, 2, 3, 3, 3, 3, 1, 1, 3, 1, 3, 3, 1, 2, 2, 2, 1, 2, 1, 1, 2, 2, 2, 1
};

#define get_num_of_strokes(c) (num_of_strokes[(int)((c)-'A')])

int simulate(const string& str) {
    int ret = 0;

    for (int i = 0; i < str.length(); ++i) {
        ret = (ret + get_num_of_strokes(str[i])) % 10;
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string K;
    cin >> K;
    cout << (simulate(K)%2==0?
                "You're the winner?":"I'm a winner!") << '\n';

    return 0;
}