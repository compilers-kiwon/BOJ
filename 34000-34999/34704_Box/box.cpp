#include <iostream>

using namespace std;

#define MAX_SIZE (4)

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, box[MAX_SIZE+1], cnt;

    cin >> N, cnt = 0;
    fill(&box[1], &box[MAX_SIZE+1], 0);

    for (int i = 1; i <= N; i++) {
        int a;
        cin >> a;
        ++box[a];
    }

    int tmp;

    cnt += box[4];
    
    tmp = min(box[1], box[3]);
    cnt += tmp, box[1] -= tmp, box[3] -= tmp;
    cnt += box[3];

    tmp = box[2] / 2;
    cnt += tmp, box[2] -= 2 * tmp;

    if (box[2] == 1) {
        cnt++, box[1] -= min(box[1], 2);
    }

    cnt += box[1] / 4;
    box[1] %= 4;
    cnt += (box[1]==0)?0:1;

    cout << cnt << '\n';

    return 0;
}