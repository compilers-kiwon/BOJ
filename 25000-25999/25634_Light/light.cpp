#include <iostream>

using namespace std;

#define ON (1)
#define OFF (0)

#define MAX_SIZE (200000+1)

int N, a[MAX_SIZE], b[MAX_SIZE];

int input(void) {
    int ret;

    cin >> N, ret = 0;

    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= N; i++) {
        cin >> b[i];
        ret += b[i] * a[i];
    }

    return ret;
}

int simulate(void) {
    int max_light, cur_state;

    max_light = cur_state = (b[1]==OFF)?a[1]:-a[1];

    for (int i = 2; i <= N; i++) {
        int d = (b[i]==OFF)?a[i]:-a[i];
        cur_state = max(cur_state + d, d);
        max_light = max(max_light, cur_state);
    }
    
    return max_light;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int sum_of_lights = input();
    cout << sum_of_lights + simulate() << '\n';

    return 0;
}