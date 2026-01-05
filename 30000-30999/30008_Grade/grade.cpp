#include <iostream>

using namespace std;

#define NUM_OF_GRADES (9)

const pair<int, int> gr[NUM_OF_GRADES+1] = {
    {}, {-1, 4}, {4, 11}, {11, 23}, {23, 40}, {40, 60},
    {60, 77}, {77, 89}, {89, 96}, {96, 100}
};

#define IN_RANGE(MIN,n,MAX) ((MIN)<(n)&&(n)<=(MAX))

int get_grade(int rank, int total) {
    int score, ret;

    for (score = (rank * 100) / total, ret = 1; ret <= NUM_OF_GRADES; ret++) {
        int lower = gr[ret].first;
        int upper = gr[ret].second;

        if (IN_RANGE(lower, score, upper)) {
            break;
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, K;

    for (cin >> N >> K; K > 0; K--) {
        int G;
        cin >> G;
        cout << get_grade(G, N) << ((K==1)?'\n':' ');
    }

    return 0;
}