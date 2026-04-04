#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef vector<vector<int>> Layer;

#define ROW_SIZE (10)
#define COL_SIZE (10)

void read_layers(vector<Layer>& layers) {
    int n;

    cin >> n;

    for (int i = 1; i <= n; ++i) {
        Layer l;

        for (int row = 0; row < ROW_SIZE; ++row) {
            string s;
            vector<int> cur;

            cin >> s;
            
            for (int col = 0; col < COL_SIZE; ++col) {
                cur.push_back((int)(s[col] - '0'));
            }

            l.push_back(cur);
        }

        layers.push_back(l);
    }
}

void print(const vector<vector<int>>& chip) {
    for (int row = 0; row < ROW_SIZE; ++ row) {
        for (int col = 0; col < COL_SIZE; ++ col) {
            cout << (chip[row][col]<10?"0":"") << chip[row][col] << ' ';
        }
        cout << '\n';
    }
}

void simulate(const vector<Layer>& layers, const vector<int>& used) {
    Layer chip;

    for (int row = 0; row < ROW_SIZE; ++ row) {
        vector<int> cur(COL_SIZE, 0);
        chip.push_back(cur);
    }

    for (int i = 0; i < used.size(); ++i) {
        for (int row = 0; row < ROW_SIZE; ++row) {
            for (int col = 0; col < COL_SIZE; ++ col) {
                chip[row][col] += layers[used[i]][row][col];
            }
        }
    }

    print(chip); cout << '\n';
}

void parse(const string& str, vector<int>& used) {
    string cur;

    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == ' ') {
            used.push_back(stoi(cur));
            cur.clear();
        } else {
            cur.push_back(str[i]);
        }
    }
}

int main(void) {
    int n;
    vector<Layer> layers;
    
    read_layers(layers);

    cin >> n; getchar();

    for (int i = 1; i <= n; ++i) {
        string str;
        vector<int> used;

        getline(cin, str);
        str.push_back(' ');

        parse(str, used);
        simulate(layers, used);
    }

    return 0;
}