#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

typedef pair<int, int> Factor;

void get_factors(int n, vector<Factor>& f) {
    for (int i = 1; i <= sqrt(n); ++i) {
        if ((n % i) == 0) {
            f.push_back({n / i, i});
        }
    }
}

bool is_nasty(const vector<Factor>& f) {
    set<int> s;

    for (int i = 0; i < f.size(); ++i) {
        s.insert(f[i].first - f[i].second);
    }

    for (int i = 0; i < f.size(); ++i) {
        if (s.find(f[i].first + f[i].second) != s.end()) {
            return true;
        }
    }
    
    return false;
}

bool simulate(int num) {
    vector<Factor> factors;
    get_factors(num, factors);
    return is_nasty(factors);
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;

    for (cin >> n; n > 0; --n) {
        int num;
        cin >> num;
        cout << num << " is " << (simulate(num)?"":"not ") << "nasty\n";
    }

    return 0;
}