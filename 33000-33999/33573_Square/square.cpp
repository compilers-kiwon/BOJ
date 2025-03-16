#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

bool is_square(const string& number) {
    int64_t n = stoll(number);
    int64_t q = static_cast<int64_t>(floor(sqrt(n)));
    return (q*q == n);
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for (int i = 1; i <= T; i++) {
        string N;
        
        cin>>N;

        if (!is_square(N)) {
            cout<<"NO\n";
            continue;
        }

        reverse(N.begin(), N.end());

        if (!is_square(N)) {
            cout<<"NO\n";
            continue;
        }

        cout<<"YES\n";
    }

    return 0;
}