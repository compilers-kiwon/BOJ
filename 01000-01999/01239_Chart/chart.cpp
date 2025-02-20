#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int DEGREE_UNIT = 36;
const int HALF_CIRCLE = 1800;

void input(vector<int>& data) {
    int N;

    cin>>N;

    for (int i = 1; i <= N; i++) {
        int num;
        cin>>num;
        data.push_back(num);
    }
}

int count_center(const vector<int>& data) {
    int ret, cur_degree;
    unordered_map<int, bool> drawn;

    ret = cur_degree = 0;
    
    for (int i = 0; i < data.size(); i++) {
        if (drawn[cur_degree%HALF_CIRCLE]) {
            ret++;
        }

        drawn[cur_degree] = true;
        cur_degree += data[i]*DEGREE_UNIT;
    }

    return ret;
}

int draw_chart(vector<int>& data) {
    int ret = 0;

    sort(data.begin(), data.end());

    do {
        ret = max(ret, count_center(data));
    } while (next_permutation(data.begin(), data.end()));

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<int> data;

    input(data);
    cout<<draw_chart(data)<<'\n';

    return 0;
}