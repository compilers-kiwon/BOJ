#include <iostream>
#include <vector>
#include <string>

using namespace std;

void analyze_text(const string& text, vector<int>& diff) {
    for (int h = 0, t = 3; t < text.length(); h++, t++) {
        size_t pos = text.find(text.substr(h, 3), t);

        if (pos != string::npos) {
            diff.push_back(pos - h);
        }
    }
}

void guess_keyword_length(const vector<int>& x, vector<int>& ret) {
    for (int i = 4; i <= 20; i++) {
        int cnt = 0;

        for (int p = 0; p < x.size(); p++) {
            cnt += (x[p]%i==0)?1:0;
        }

        if (cnt != 0 && (cnt * 10) / 9 >= x.size()) {
            ret.push_back(i);
        }
    }
}

void print(const vector<int>& g) {
    if (g.empty()) {
        cout << "No guesses found.\n";
        return;
    }

    cout << "Possible key lengths between 4 and 20: ";

    for (int i = 0; i < g.size(); i++) {
        cout << g[i] << ((i==g.size()-1)?'\n':' ');
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int t;

    for (cin >> t; t > 0; t--) {
        string text;
        vector<int> x, guess;

        cin >> text;

        analyze_text(text, x);
        guess_keyword_length(x, guess);
        print(guess);
    }

    return 0;
}