#include <iostream>
#include <vector>

using namespace std;

#define TBD (-1)
#define NUM_OF_BUILDINGS (8)
#define MAX_WALKING_TIME (100000)
#define MOD(n) ((n)%1000000007)

vector<int> connected[NUM_OF_BUILDINGS];
int D, dp[NUM_OF_BUILDINGS][MAX_WALKING_TIME+1];

int get_dp(int cur_pos, int cur_time) {
    if (cur_time == 0) {
        return ((cur_pos==0)?1:0);
    }

    int& ret = dp[cur_pos][cur_time];

    if (ret != TBD) {
        return ret;
    }

    ret = 0;

    const vector<int>& adj = connected[cur_pos];

    for (int i = 0; i < adj.size(); ++i) {
        ret = MOD(ret + get_dp(adj[i], cur_time - 1));
    }

    return ret;
}

void init(void) {
    cin >> D;

    for (int i = 0; i < NUM_OF_BUILDINGS; ++i) {
        fill(&dp[i][0], &dp[i][D+1], TBD);
    }

    /*
     0 : 정보과학관
     1 : 전산관
     2 : 미래관
     3 : 신양관
     4 : 한경직기념관
     5 : 진리관
     6 : 학생회관
     7 : 형남공학관
    */
   
    connected[0] = {1, 2};
    connected[1] = {0, 2, 3};
    connected[2] = {0, 1, 3, 4};
    connected[3] = {1, 2, 4, 5};
    connected[4] = {2, 3, 5, 7};
    connected[5] = {3, 4, 6};
    connected[6] = {5, 7};
    connected[7] = {4, 6};
}

int main(void) {
    cin.tie(NULL);
    cout.sync_with_stdio(false);

    init();
    cout << get_dp(0, D) << '\n';

    return 0;
}