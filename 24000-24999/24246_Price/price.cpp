#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n, i;
    vector<int> price;

    for (cin >> n; n > 0; n--) {
        int p;
        cin >> p;
        price.push_back(p);
    }

    for (i = 1; i < price.size(); i++) {
        if (price[i] <= price.front()) {
            break;
        }
    }

    if (i == price.size()) {
        cout << "infinity\n";
    } else {
        cout << i << '\n';
    }

    return 0;
}