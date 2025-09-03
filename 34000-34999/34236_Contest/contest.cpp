#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    vector<int> years;

    for (cin >> N; N > 0; N--) {
        int A;
        cin >> A;
        years.push_back(A);
    }

    cout << years.back() +
            ((years.back() - years.front())/(years.size() - 1)) << '\n';
    return 0;
}