#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void read_image(vector<string>& img) {
    for (string s; getline(cin, s); img.push_back(s));
}

void parse_image(const vector<string>& img) {
    int row = 0;

    for (; count(img[row].begin(), img[row].end(), '#') == 1; row++);
    cout << row << '\n';

    vector<int> tine(img[row++].size(), 0);

    for (; row < img.size(); row++) {
        for (size_t pos = 0; pos < img[row].length();) {
            pos = img[row].find('#', pos);

            if (pos != string::npos) {
                tine[pos++]++;
            } else {
                break;
            }
        }
    }

    for (int i = 0; i < tine.size(); i++) {
        if (tine[i] != 0) {
            cout << tine[i] << ' ';
        }
    }

    cout << '\n';
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<string> buf;

    read_image(buf);
    parse_image(buf);

    return 0;
}