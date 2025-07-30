#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned long long uint64;

int N, m_ptr, i_ptr;
uint64 D;
vector<uint64> monsters, items;

int simulate(void) {
    int cnt;

    for (cnt = 0; m_ptr < monsters.size();) {
        if (i_ptr == items.size() && D <= monsters[m_ptr]) {
            break;
        }

        if (D > monsters[m_ptr]) {
            D += monsters[m_ptr++];
            cnt++;
        } else {
            for (; i_ptr < items.size();) {
                D *= items[i_ptr++];
                cnt++;

                if (D > monsters[m_ptr]) {
                    break;
                }
            }
        }
    }

    for (; i_ptr < items.size(); i_ptr++) {
        cnt++;
    }
    
    return cnt;
}

void input(void) {
    cin >> N >> D;

    for (int i = 1; i <= N; i++) {
        int A;
        uint64 X;

        cin >> A >> X;

        if (A == 1) {
            monsters.push_back(X);
        } else {
            items.push_back(X);
        }
    }

    sort(items.begin(), items.end());
    sort(monsters.begin(), monsters.end());
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout << simulate() << '\n';

    return 0;
}