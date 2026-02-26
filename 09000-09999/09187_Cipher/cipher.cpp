#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int SIZE_OF_SQUARE = 5;

typedef pair<int, int> Pos;

#define row first
#define col second

void build_square(const string& str,
                    char square[][SIZE_OF_SQUARE]) {
    string available;

    for (int i = 0; i < str.length(); ++i) {
        if (available.find(str[i]) == string::npos) {
            available.push_back(str[i]);
        }
    }

    for (int i = 0, row = 0; i < available.length();
            i += SIZE_OF_SQUARE, ++row) {
        string s = available.substr(i, SIZE_OF_SQUARE);

        for (int col = 0; col < s.length(); ++col) {
            square[row][col] = s[col];
        }
    }

    string s = "ABCDEFGHIKLMNOPQRSTUVWXYZ";
    
    for (int row = 0, pos = 0; row < SIZE_OF_SQUARE; ++row) {
        for (int col = 0; col < SIZE_OF_SQUARE; ++col) {
            if (square[row][col] != ' ') {
                continue;
            }

            for (; available.find(s[pos]) != string::npos; ++pos) {}
            square[row][col] = s[pos++];
        }
    }
}

void preprocess_msg(const string& msg, vector<string>& pairs) {
    string tmp1, tmp2;

    for (int i = 0; i < msg.length(); ++i) {
        if (isalpha(msg[i])) {
            tmp1.push_back(msg[i]);
        }
    }

    for (int i = 0; i < tmp1.length(); ++i) {
        char c = tmp1[i];

        if (!tmp2.empty() && tmp2.back() == c) {
            tmp2.push_back(c=='Q'?'Z':'Q');
        }
        
        tmp2.push_back(c);
    }

    if (tmp2.length() % 2 != 0) {
        tmp2.push_back(tmp2.back()=='Q'?'Z':'Q');
    }

    for (int i = 0; i < tmp2.length(); i += 2) {
        pairs.push_back(tmp2.substr(i, 2));
    }
}

Pos get_pos(char c, char square[][SIZE_OF_SQUARE]) {
    for (int row = 0; row < SIZE_OF_SQUARE; ++row) {
        for (int col = 0; col < SIZE_OF_SQUARE; ++col) {
            if (square[row][col] == c) {
                return {row, col};
            }
        }
    }

    return {-1, -1};
}

void encode(const vector<string>& pairs,
                vector<string>& encoded, char square[][SIZE_OF_SQUARE]) {
    for (int i = 0; i < pairs.size(); ++i) {
        char c1 = pairs[i].front();
        char c2 = pairs[i].back();

        Pos p1 = get_pos(c1, square);
        Pos p2 = get_pos(c2, square);

        string s;

        if (p1.row == p2.row) {
            s.push_back(square[p1.row][(p1.col+1)%SIZE_OF_SQUARE]);
            s.push_back(square[p2.row][(p2.col+1)%SIZE_OF_SQUARE]);
        } else if (p1.col == p2.col) {
            s.push_back(square[(p1.row+1)%SIZE_OF_SQUARE][p1.col]);
            s.push_back(square[(p2.row+1)%SIZE_OF_SQUARE][p2.col]);
        } else {
            s.push_back(square[p1.row][p2.col]);
            s.push_back(square[p2.row][p1.col]);
        }

        encoded.push_back(s);
    }
}

void print(vector<string>& encoded) {
    for (int i = 0; i < encoded.size(); ++i) {
        cout << encoded[i] << ' ';
    }

    cout << '\n';
}

void swap_unused_char(string& str, char unused, char used) {
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == unused) {
            str[i] = used;
        }
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for (;;) {
        string keyword, msg;
        char square[SIZE_OF_SQUARE][SIZE_OF_SQUARE];
        vector<string> pairs, encoded;

        getline(cin, keyword);

        if (keyword == "999") {
            break;
        }

        getline(cin, msg);

        swap_unused_char(keyword, 'J', 'I');
        swap_unused_char(msg, 'J', 'I');
        fill(&square[0][0], &square[0][0] + sizeof(square), ' ');

        build_square(keyword, square);
        preprocess_msg(msg, pairs);
        encode(pairs, encoded, square);
        print(encoded);
    }

    return 0;
}