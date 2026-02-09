#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<string, pair<int, int>> range = {
    {"Red", {620, 780 + 1}}, {"Orange", {590, 620}},
    {"Yellow", {570, 590}}, {"Green", {495, 570}},
    {"Blue", {450, 495}}, {"Indigo", {425, 450}},
    {"Violet", {380, 425}}
};

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int lambda;
    cin >> lambda;

    for (auto it = range.begin(); it != range.end(); ++it) {
        int lower = it->second.first;
        int upper = it->second.second;

        if (lower <= lambda && lambda < upper) {
            cout << it->first << '\n';
            break;
        }
    }

    return 0;
}