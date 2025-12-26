#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define INF (10000000)

void init(const string& str, vector<int>& period, int time) {
    int size = str.length();

    period.front() = period.back() = 0;
    
    for (int i = 1; i < size - 1; i++) {
        if (str[i] == str[i-1] || str[i] == str[i+1]) {
            period[i] = 0;
        }
    }

    for (int i = 1; i < size - 1; i++) {
        if (str[i] != str[i-1] && str[i] != str[i+1]) {
            period[i] = min(time, min(period[i-1], period[i+1]) + 1);;
        }
    }

    for (int i = size - 2; i >= 1; i--) {
        if (str[i] != str[i-1] && str[i] != str[i+1]) {
            period[i] = min(time, min(period[i-1], period[i+1]) + 1);;
        }
    }
}

void simulate(string& str, vector<int>& period) {
    for (int i = 0; i < str.length(); i++) {
        if (period[i] % 2 == 0) {
            continue;
        } else {
            str[i] = (str[i]=='A')?'B':'A';
        }
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, T;
    string str;

    cin >> N >> T >> str;

    vector<int> t(N, INF);

    init(str, t, T);
    simulate(str, t);
    cout << str << '\n';

    return 0;
}