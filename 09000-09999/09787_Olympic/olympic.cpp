#include <iostream>
#include <string>
#include <map>
#include <set>
#include <tuple>

using namespace std;

typedef map<tuple<int, int, int>, set<string>> Rank;

void input(Rank& table) {
    string c;
    int g, s, b;

    for (; cin >> c >> g >> s >> b;) {
        table[{g, s, b}].insert(c);
    }
}

void print(Rank& table) {
    int r = 1;

    for (auto it = table.rbegin(); it != table.rend(); ++it) {
        auto [g , s, b] = it->first;
        const set<string>& countries = it->second;

        for (auto c = countries.begin(); c != countries.end(); ++c) {
            cout << r << ' ' << *c << ' '
                    << g << ' ' << s << ' ' << b << ' ' << g + s + b <<'\n';
        }

        r += countries.size();
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    Rank table;

    input(table);
    print(table);

    return 0;
}