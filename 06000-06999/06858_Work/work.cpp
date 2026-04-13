#include <iostream>
#include <vector>

using namespace std;

#define MAX_SIZE (7)

vector<int> has_to_be_done[MAX_SIZE+1] = {
    {},
    {2},
    {},
    {},
    {1, 3},
    {3},
    {},
    {1}
};

void input(void) {
    for (;;) {
        int x, y;

        cin >> x >> y;

        if (x == 0 && y == 0) {
            break;
        }

        has_to_be_done[y].push_back(x);
    }
}

bool can_do(int w, vector<bool>& state) {
    bool ret = true;

    for (int i = 0; i < has_to_be_done[w].size(); ++i) {
        if (state[has_to_be_done[w][i]] == false) {
            ret = false;
            break;
        }
    }

    return ret;
}

bool simulate(vector<int>& order) {
    vector<bool> done(MAX_SIZE + 1, false);

    for (;;) {
        int pick = 0;

        for (int i = 1; i <= MAX_SIZE; ++i) {
            if (!done[i] && can_do(i, done)) {
                pick = i;
                break;
            }
        }

        if (pick == 0) {
            return false;
        }
        
        done[pick] = true;
        order.push_back(pick);

        if (order.size() == MAX_SIZE) break;
    }

    return true;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<int> order;

    input();

    if (simulate(order) == true) {
        for (int i = 0; i < MAX_SIZE; ++i) {
            cout << order[i] << ((i==MAX_SIZE-1)?'\n':' ');
        }
    } else {
        cout << "Cannot complete these tasks. Going to bed.\n";
    }

    return 0;
}