#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

vector<string> category, purchased;
unordered_map<string, string> categorized;
unordered_map<string, vector<string>> sorted;

void input(void) {
    int n, k;

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        string t;
        cin >> t;
        purchased.push_back(t);
    }

    for (int i = 0; i < k; i++) {
        string c;
        cin >> c;
        category.push_back(c);
    }

    for (int i = 0; i < k; i++) {
        int m;
        string c;

        cin >> c >> m;

        for (int j = 0; j < m; j++) {
            string s;
            cin >> s;
            categorized[s] = c;
        }
    }
}

void sort_items(void) {
    for (int i = 0; i < purchased.size(); i++) {
        const string& cur_item = purchased[i];
        sorted[categorized[cur_item]].push_back(cur_item);
    }
}

void print_items(void) {
    for (int i = 0; i < category.size(); i++) {
        const vector<string>& items = sorted[category[i]];

        for (int j = 0; j < items.size(); j++) {
            cout << items[j] << ' ';
        }
    }

    cout << '\n';
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    sort_items();
    print_items();

    return 0;
}