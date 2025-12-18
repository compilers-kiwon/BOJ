#include <iostream>
#include <string>

using namespace std;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, k, pos;
    int cur_num_of_rains, max_num_of_rains;
    string c;

    cin >> N >> k >> c;
    pos = cur_num_of_rains = 0;

    for (int i = 0; i < k; i++) {
        cur_num_of_rains += (c[i]=='L')?1:0;
    }

    max_num_of_rains = cur_num_of_rains;

    for (int h = 0, t = k; t < c.length(); h++, t++) {
        cur_num_of_rains += (c[t]=='L'?1:0) - (c[h]=='L'?1:0);

        if (cur_num_of_rains > max_num_of_rains) {
            pos = h + 1, max_num_of_rains = cur_num_of_rains;
        }
    }

    cout << pos + 1 << '\n';

    return 0;
}