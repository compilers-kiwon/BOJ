#include <iostream>
#include <vector>

using namespace std;

#define MAX_SIZE (8)

typedef pair<int, int> Pos;

void input(vector<Pos>& r) {
    int N;

    for (cin >> N; N > 0; N--) {
        int row, col;
        cin >> row >> col;
        r.push_back({row, col});
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int t;

    for (cin >> t; t > 0; t--) {
        bool is_safe = true;
        vector<Pos> rooks;
        int row[MAX_SIZE+1], col[MAX_SIZE+1];

        input(rooks);
        fill(&row[1], &row[MAX_SIZE+1], 0);
        fill(&col[1], &col[MAX_SIZE+1], 0);

        for (int i = 0; i < rooks.size(); i++) {
            int r = rooks[i].first;
            int c = rooks[i].second;

            if (row[r] == 1 || col[c] == 1) {
                is_safe = false;
                break;
            }

            row[r]++, col[c]++;
        }

        cout << (is_safe?"SAFE":"NOT SAFE") << '\n';
    }

    return 0;
}