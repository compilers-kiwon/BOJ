#include <iostream>
#include <vector>

using namespace std;

#define REDUCTION (200)
#define NUM_OF_AREAS (2)

const vector<vector<int>> table[NUM_OF_AREAS] = {
    {
        {200, 210, 220}, {210, 220, 225}, {220, 225, 230},
        {225, 230, 235}, {230, 235, 245}, {235, 245, 250}
    },
    {
        {260, 265, 270}, {265, 270, 275}, {270, 275, 280},
        {275, 280, 285}, {280, 285, 290}, {285, 290, 295},
        {290, 295, 300}
    }
};

int get(int cur_level, const vector<int>& area) {
    int quest_level = area[0];
    int first_reduction = area[1];
    int second_reduction = area[2];

    if (cur_level < quest_level) {
        return 0;
    }

    int ret = 500;

    if (cur_level >= first_reduction) {
        ret -= REDUCTION;
    }

    if (cur_level >= second_reduction) {
        ret -= REDUCTION;
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int L;

    cin>>L;

    for (int i = 0; i < NUM_OF_AREAS; i++) {
        for (int j = 0; j < table[i].size(); j++) {
            cout<<get(L, table[i][j])<<' ';
        }
        cout<<'\n';
    }

    return 0;
}