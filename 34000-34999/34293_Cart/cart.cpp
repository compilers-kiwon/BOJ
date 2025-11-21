#include <iostream>

using namespace std;

#define NONE (-1.0f)
#define MAX_SIZE (100000+1)
#define SPEED_LIMIT (300000000.0f)

int n;
double l, d[MAX_SIZE+1], w[MAX_SIZE+1];

void input(void) {
    cin >> n >> l;

    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }

    d[n+1] = l, w[n+1] = 0.0f;
}

bool simulate(double v) {
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

double bin_search(void) {
    double ret = NONE;
    double low, high, mid;

    for (low = 1.0f, high = l; low < high && (high - low) > 0.00001f; ) {
        mid = (low + high) / 2.0f;

        if (simulate(mid) == true) {
            ret = high = mid;
        } else {
            low = mid;
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    double min_required_speed;

    input();
    min_required_speed = bin_search();

    if (min_required_speed != NONE && min_required_speed <= SPEED_LIMIT) {
        cout << fixed; cout.precision(4);
        cout << min_required_speed << '\n';
    } else {
        cout << "IMPOSSIBLE\n";
    }

    return 0;
}