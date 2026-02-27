#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void input(vector<int>& d) {
    int N;

    for (cin >> N; N > 0; --N) {
        int X;
        cin >> X;
        d.push_back(X);
    }
}

string evaluate_difficulty(vector<int>& d) {
    int first = d.front();
    sort(d.begin(), d.end());
    return (first==d.front()?"ez":first==d.back()?"hard":"?");
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<int> X;
    input(X);
    cout << evaluate_difficulty(X) << '\n';

    return 0;
}