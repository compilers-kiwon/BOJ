#include <iostream>
#include <string>

using namespace std;

bool build_str(const string& pool, string target) {
    for (int i = 0; i < target.length(); i++) {
        if (pool.find(target[i]) == string::npos) {
            return false;
        }
    }

    return true;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string s;
    cin >> s;
    cout << (build_str(s, "MOBIS")?"YES":"NO") << '\n';

    return 0;
}