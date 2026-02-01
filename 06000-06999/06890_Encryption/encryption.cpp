#include <iostream>
#include <string>
#include <vector>

using namespace std;

string const alphabets = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

string get_alphabets_only(const string& s) {
    string ret;

    for (int i = 0; i < s.length(); ++i) {
        if (isalpha(s[i])) {
            ret.push_back(s[i]);
        }
    }

    return ret;
}

vector<string> get_blocks(const string& s, int size) {
    vector<string> ret;

    for (int i = 0; i < s.length(); i += size) {
        ret.push_back(s.substr(i, size));
    }

    return ret;
}

void encrypt(vector<string>& blocks, const string& keyword) {
    vector<int> shift;

    for (int i = 0; i < keyword.length(); ++i) {
        shift.push_back(alphabets.find(keyword[i]));
    }

    for (int i = 0; i < blocks.size(); ++i) {
        string& s = blocks[i];

        for (int j = 0; j < s.length(); ++j) {
            char& c = s[j];
            int pos = alphabets.find(c);
            c = alphabets[(pos+shift[j])%alphabets.length()];
        }
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string keyword, message;
    vector<string> blocks;

    getline(cin, keyword);
    getline(cin, message);

    message = get_alphabets_only(message);
    blocks = get_blocks(message, keyword.length());
    encrypt(blocks, keyword);

    for (int i = 0; i < blocks.size(); ++i) {
        cout << blocks[i];
    }

    return 0;
}