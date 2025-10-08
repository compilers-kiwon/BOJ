#include <iostream>
#include <vector>

using namespace std;

#define MAX_SIZE (500000+1)

int N, cnt[MAX_SIZE+1];
bool visited[MAX_SIZE];
char w[MAX_SIZE];

int input(void) {
    int ret = 0;

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >>w[i];
        ret += (w[i]=='P')?1:0;
    }

    return ret;
}

int simulate(void) {
    int ret = 0;

    for (int i = 1; i <= N; i++) {
        if (w[i] == 'P' || visited[i] == true) {
            continue;
        }

        vector<int> sunny_days;

        for (int s = i; w[s] == 'S' && s <= N; s++) {
            visited[s] = true;
            sunny_days.push_back(s);
        }

        for (int n = 0; n < sunny_days.size(); n++) {
            cnt[sunny_days[n]] = sunny_days.size();
        }

        ret = max(ret, (int)sunny_days.size());
    }

    return ret;
}

int determine_max_possible_number(void) {
    int ret = 0;

    for (int i = 1; i <= N; i++) {
        if (w[i] == 'P') {
            ret = max(ret, cnt[i-1] + 1 + cnt[i+1]);
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int num_of_precipitation, max_num;

    num_of_precipitation = input();
    max_num = simulate() - (num_of_precipitation==0?1:0);
    max_num = max(max_num, determine_max_possible_number());

    cout << max_num << '\n';
    return 0;
}