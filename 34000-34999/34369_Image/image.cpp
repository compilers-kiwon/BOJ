#include <iostream>

using namespace std;

#define INF (0x7FFFFFFF)
#define MAX_NUM_OF_DRIVES (1000+1)

int flashing_time[MAX_NUM_OF_DRIVES];
int time_to_finish[MAX_NUM_OF_DRIVES];

int simulate(int num_of_computers, int num_of_drives) {
    int ret;

    for (int i = 1; i <= num_of_computers; i++) {
        int next_earliest_time_to_finish = INF;
        int selected_drive;

        for (int j = 1; j <= num_of_drives; j++) {
            if ((time_to_finish[j] + flashing_time[j]) < next_earliest_time_to_finish) {
                selected_drive = j;
                next_earliest_time_to_finish = time_to_finish[j] + flashing_time[j];
            }
        }

        ret = (time_to_finish[selected_drive] += flashing_time[selected_drive]);
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, M;

    cin >> N >> M;

    for (int i = 1; i <= M; i++) {
        cin >> flashing_time[i];
    }

    cout << simulate(N, M) << '\n';

    return 0;
}