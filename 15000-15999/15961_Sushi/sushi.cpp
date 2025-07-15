#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int simulate(vector<int>& b, int max_size, int coupon) {
    int s, e, cur_size, ret;
    unordered_map<int, int> sushi;

    s = 0, e = 1, cur_size = 1;
    
    sushi[b[s]] = 1;
    sushi[coupon]++;

    for (ret = 0; s < b.size();) {
        int next = b[e];

        sushi[next]++;
        cur_size++;
        e = (e + 1) % b.size();

        if (cur_size > max_size) {
            int prev = b[s];

            sushi[prev]--;

            if (sushi[prev] == 0) {
                sushi.erase(prev);
            }

            s++;
            cur_size--;
        }

        ret = max(ret, (int)sushi.size());
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, d, k, c;
    vector<int> sushi;

    cin >> N >> d >> k >> c;

    for (int i = 1; i <= N ;i++) {
        int s;
        cin >> s;
        sushi.push_back(s);
    }

    cout << simulate(sushi, k, c) << '\n';

    return 0;
}