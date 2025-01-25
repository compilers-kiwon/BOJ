#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef enum {
    ADD = 0,
    MUL = 1,
} OP;

typedef pair<OP,int64_t> Option;

#define MAX_NUM_OF_ROUNDS (50+1)
#define NUM_OF_OPTIONS (2)

size_t N;
int64_t P, max_num[MAX_NUM_OF_ROUNDS], min_num[MAX_NUM_OF_ROUNDS];
Option rounds[MAX_NUM_OF_ROUNDS][NUM_OF_OPTIONS];

void input_and_init(void) {
    cin>>N>>P;
    max_num[0] = min_num[0] = P;

    for (size_t i = 1; i <= N; i++) {
        for (size_t j = 0; j < NUM_OF_OPTIONS; j++) {
            char T;
            int64_t c;

            cin>>T>>c;
            rounds[i][j].first = (T=='+')?ADD:MUL;
            rounds[i][j].second = c;
        }
    }
}

int64_t calculate(int64_t n, size_t r, size_t o) {
    OP t = rounds[r][o].first;
    int64_t c = rounds[r][o].second;

    return (t==ADD)?n+c:n*c;
}

int64_t simulate(void) {
    for (size_t i = 1; i <= N; i++) {
        int64_t prev_max = max_num[i-1];
        int64_t prev_min = min_num[i-1];
        vector<int64_t> result;

        for (size_t j = 0; j < NUM_OF_OPTIONS; j++) {
            result.push_back(calculate(prev_max, i, j));
            result.push_back(calculate(prev_min, i, j));
        }

        sort(result.begin(), result.end());

        min_num[i] = result.front();
        max_num[i] = result.back();
    }

    return max_num[N];
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input_and_init();
    cout<<simulate()<<'\n';

    return 0;
}