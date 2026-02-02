#include <iostream>
#include <string>
#include <map>

using namespace std;

void simulate(int num_of_days, const string& net_changed, map<int, string>& matrix) {
    int cur_net = 0;

    for (int i = 0; i < num_of_days; ++i) {
        char c = net_changed[i];

        cur_net -= (c=='-')?1:0;

        if (matrix.find(cur_net) == matrix.end()) {
            matrix[cur_net] = string(num_of_days, '.');
        }

        switch(c) {
            case '-': matrix[cur_net][i] = '\\'; break;
            case '+': matrix[cur_net][i] = '/'; break;
            case '=': matrix[cur_net][i] = '_'; break;
            default: /*do nothing*/; break;
        }

        cur_net += (c=='+')?1:0;
    }
}

void print(map<int, string>& matrix) {
    for (auto it = matrix.rbegin(); it != matrix.rend(); ++it) {
        cout << it->second << '\n';
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;
    string s;
    map<int, string> matrix;

    cin >> n >> s;
    simulate(n, s, matrix);
    print(matrix);

    return 0;
}