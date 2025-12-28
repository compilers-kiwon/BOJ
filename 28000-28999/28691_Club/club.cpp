#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<char, string> club = {
    {'M', "MatKor"}, {'W', "WiCys"}, {'C', "CyKor"},
    {'A', "AlKor"}, {'$', "$clear"},
};

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    char c;
    cin >> c;
    cout << club[c] << '\n';

    return 0;
}