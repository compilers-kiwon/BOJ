#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define MAX_RANK (30)
#define MAX_NUM_OF_CONTESTANTS (1000+1)

const int score[MAX_RANK+1] = {
    0, 100, 75, 60, 50, 45, 40, 36, 32, 29, 26,
    24, 22, 20, 18, 16, 15, 14, 13, 12, 11,
    10, 9, 8, 7, 6, 5, 4, 3, 2, 1
};

// <-num_of_solved_problems, <time_penalty, last_accepted_time>>
typedef pair<int,pair<int,int>> Scoring;

typedef struct {
    int s, p, f, o, score;
} Contestant;

int n;
Contestant con[MAX_NUM_OF_CONTESTANTS];
map<Scoring, vector<int>> ranking;

static inline int get_score(int rank) {
    return (rank<=MAX_RANK)?score[rank]:0;
}

void input(void) {
    cin>>n;

    for (int i = 1; i <= n; i++) {
        cin>>con[i].s>>con[i].p>>con[i].f>>con[i].o;
    }
}

void determin_ranking(void) {
    for (int i = 1; i <= n; i++) {
        Scoring sc = {-con[i].s, {con[i].p, con[i].f}};
        ranking[sc].push_back(i);
    }
}

void print_score(void) {
    int prev_rank = 1;
    map<Scoring, vector<int>>::iterator it;

    for (it = ranking.begin(); it != ranking.end(); it++) {
        const vector<int>& c = it->second;
        int cur_rank = prev_rank;
        int sum_of_score = 0;

        for (int i = 0; i < c.size(); i++, cur_rank++) {
            sum_of_score += get_score(cur_rank);
        }

        for (int i = 0; i < c.size(); i++) {
            con[c[i]].score =
                sum_of_score/c.size() + ((sum_of_score%c.size())?1:0);
        }

        prev_rank = cur_rank;
    }

    for (int i = 1; i <= n; i++) {
        cout<<con[i].score+con[i].o<<'\n';
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    determin_ranking();
    print_score();

    return 0;
}