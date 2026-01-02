#include <iostream>
#include <string>

using namespace std;

typedef long long int int64;

#define MAX_LEN (10)

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int64 N;
    string cur;

    cin >> N, cur = "1";

    for (int64 i = 1LL; i <= N; i++) {
        int64 num = stoll(cur) * i;
        
        for (; num%10LL == 0LL; num /= 10LL);
        cur = to_string(num);

        if (cur.length() > MAX_LEN) {
            cur.erase(0, cur.length() - MAX_LEN);
        }
    }

    cout << cur.back() << '\n';

    return 0;
}