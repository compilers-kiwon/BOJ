#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define MAX_SIZE (2000+1)

int N;
vector<int> pos[MAX_SIZE];

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin >> N;

    for (int i = 1; i <= 2*N; i++) {
        int X;
        cin >> X;
        pos[X].push_back(i);
    }

    int max_dist = 0;

    for (int i = 1; i <= N; i++) {
        int cur_dist = abs(pos[i].front() - pos[i].back());
        max_dist = max(max_dist, cur_dist - 1);
    }

    cout << max_dist << '\n';

    return 0;
}