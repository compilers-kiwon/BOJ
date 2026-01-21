#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define QUOTIENT (9)

typedef pair<string, string> Div;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    vector<Div> solutions;
    string arr = "0123456789";

    cin >> N;

    do {
        string a = arr.substr(0, 5);
        string b = arr.substr(5, 5);

        if (stoi(b) * QUOTIENT == stoi(a)) {
            solutions.push_back({a, b});
        }
    } while (next_permutation(arr.begin(), arr.end()));

    sort(solutions.begin(), solutions.end());
    cout << solutions[N-1].first << ' ' << solutions[N-1].second << '\n';

    return 0;
}