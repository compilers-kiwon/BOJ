#include <iostream>
#include <string>

using namespace std;

string analyze(const string& small, const string& big) {
    for (size_t i = 0; i < small.length(); i++) {
        if (big.find(small[i]) == string::npos) {
            return "NO";
        }
    }

    return "YES";
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int t;

    for (cin >> t; t > 0; t--) {
        string a, b;
        cin >> a >> b;
        cout << analyze(b, a) << '\n';
    }

    return 0;
}