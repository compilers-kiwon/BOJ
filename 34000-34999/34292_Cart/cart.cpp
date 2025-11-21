#include <iostream>

using namespace std;

#define MAX_SIZE (100000+1)

int n;
double l, v, d[MAX_SIZE], w[MAX_SIZE];

void input(void) {
    cin >> n >> l;

    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }

    cin >> v;
}

bool simulate(void) {
    double cur_pos, cur_time;

    cur_pos = cur_time = 0.0f;

    for (int i = 1; i <= n; i++) {
        double max_time = d[i];
        double dist = d[i] - cur_pos;
        
        cur_time = max(max_time, cur_time + (dist / v)) + w[i];
        cur_pos = d[i];
    }

    cur_time += ((l - cur_pos) / v);

    return (cur_time <= l);
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout << ((simulate()==true)?"YES":"NO") << '\n';

    return 0;
}