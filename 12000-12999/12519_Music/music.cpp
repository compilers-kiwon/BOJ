#include <iostream>
#include <string>
#include <vector>

using namespace std;

void make_upper(string& s) {
    for (int i = 0; i < s.length(); i++) {
        if (isalpha(s[i])) {
            s[i] = toupper(s[i]);
        }
    }
}

int read_num(void) {
    string s;
    getline(cin ,s);
    return stoi(s);
}

void input(vector<string>& collection) {
    int N = read_num();

    for (int i = 1; i <= N; i++) {
        string n;
        
        getline(cin , n);
        make_upper(n);
        collection.push_back(n);
    }
}

bool is_included(const vector<string>& collection, const string& sub, int idx) {
    for (int i = 0; i < collection.size(); i++) {
        if (i == idx) {
            continue;
        }

        if (collection[i].find(sub) != string::npos) {
            return true;
        }
    }

    return false;
}

string find_unique_sub_str(const vector<string>& collection, int idx) {
    const string& cur = collection[idx];

    for (int sub_len = 1; sub_len <= cur.length(); sub_len++) {
        string ret;

        for (int i = 0; i < cur.length() - sub_len + 1; i++) {
            string sub = cur.substr(i, sub_len);

            if (is_included(collection, sub, idx) == false) {
                if (ret.empty() || sub < ret) {
                    ret = sub;
                }
            }
        }

        if (!ret.empty()) {
            return ("\"" + ret + "\"");
        }
    }

    return ":(";
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T = read_num();

    for (int t = 1; t <= T; t++) {
        vector<string> collection;

        input(collection);
        cout << "Case #" << t << ":\n";

        if (collection.size() == 1) {
            cout << "\"\"\n";
            continue;    
        }

        for (int i = 0; i < collection.size(); i++) {
            cout << find_unique_sub_str(collection, i) << '\n';
        }
    }

    return 0;
}