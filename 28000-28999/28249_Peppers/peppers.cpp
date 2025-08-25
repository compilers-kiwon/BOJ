#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<string, int> table = {
    {"Poblano", 1500}, {"Mirasol", 6000}, {"Serrano", 15500},
    {"Cayenne", 40000}, {"Thai", 75000}, {"Habanero", 125000}
};

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, sum;

    for (cin >> N, sum = 0; N > 0; N--) {
        string p;
        cin >> p;
        sum += table[p];
    }

    cout << sum << '\n';
    return 0;
}