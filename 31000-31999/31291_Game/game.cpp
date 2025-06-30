#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

typedef pair<string, string> Item;

set<Item> right_items = {
    {"white", "Barabashka"}, {"blue", "book"}, {"red", "chair"},
    {"gray", "mouse"}, {"green", "bottle"}
};

set<string> item_color = {
    "white", "blue", "red", "gray", "green"
};

set<string> item_name = {
    "Barabashka", "book", "chair", "mouse", "bottle"
};

void parse(string& str, vector<Item>& parsed) {
    string cur;
    vector<string> words;

    for (size_t i = 0; i < str.length(); i++) {
        if (!isalpha(str[i])) {
            if (!cur.empty()) {
                words.push_back(cur);
                cur.clear();
            }
        } else {
            cur.push_back(str[i]);
        }
    }

    for (size_t i = 0; i < words.size() - 1; i++) {
        string& color = words[i];
        string& name = words[i+1];

        if (item_color.find(color) != item_color.end()
                && item_name.find(name) != item_name.end()) {
            parsed.push_back({color, name});
        }
    }
}

bool find_color(const vector<Item>& items, const string& color) {
    for (size_t i = 0; i < items.size(); i++) {
        if (items[i].first == color) {
            return true;
        }
    }

    return false;
}

bool find_name(const vector<Item>& items, const string& name) {
    for (size_t i = 0; i < items.size(); i++) {
        if (items[i].second == name) {
            return true;
        }
    }

    return false;
}

void simulate(const vector<Item>& items) {
    for (size_t i = 0; i < items.size(); i++) {
        if (right_items.find(items[i]) != right_items.end()) {
            cout<<items[i].first<<' '<<items[i].second<<'\n';
            return;
        }
    }

    set<Item>::iterator it;

    for (it = right_items.begin(); it != right_items.end(); it++) {
        string color = it->first;
        string name = it->second;

        if (find_color(items, color) == false && find_name(items, name) == false) {
            cout<<color<<' '<<name<<'\n';
            return;
        }
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for (;;) {
        string s;
        vector<Item> found;

        getline(cin, s);

        if (s.empty()) {
            break;
        }
        
        parse(s, found);
        simulate(found);
    }

    return 0;
}