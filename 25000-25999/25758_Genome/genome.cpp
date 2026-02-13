#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

void input(vector<string>& g, set<string>& d) {
    int N;
    set<string> v;

    for (cin >> N; N > 0; N--) {
        string s;
        
        cin >> s;

        if (v.find(s) == v.end()) {
            g.push_back(s), v.insert(s);
        } else {
            d.insert(s);
        }
    }
}

void simulate(const vector<string>& g, set<char>& c) {
    for (int i = 0; i < g.size() - 1; ++i) {
        for (int j = i + 1; j < g.size(); ++j) {
            const string& g1 = g[i];
            const string& g2 = g[j];

            c.insert(max(g1.front(), g2.back()));
            c.insert(max(g1.back(), g2.front()));
        }
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<string> genome;
    set<char> generated;
    set<string> duplicated;

    input(genome, duplicated);
    simulate(genome, generated);

    for (auto it = duplicated.begin(); it != duplicated.end(); ++it) {
        generated.insert(max((*it).front(), (*it).back()));
    }
    
    cout << generated.size() << '\n';

    for (auto it = generated.begin(); it != generated.end(); ++it) {
        cout << *it << ' ';
    }

    return 0;
}