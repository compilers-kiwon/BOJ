#include <iostream>
#include <vector>

using namespace std;

#define NUM_OF_QUARTILE (11)
#define SCORE_LOWER_BOUND (200)
#define CREDIT_LOWER_BOUND (17)

#define QUARTILE_IDX (0)
#define SCORE_IDX (1)
#define CREDIT_IDX (2)

void read_quartile(vector<int>& q) {
    for (int i = 0; i < NUM_OF_QUARTILE; i++) {
        int M;
        cin >> M;
        q.push_back(M);
    }
}

void read_student_info(vector<int>& info) {
    int M;
    cin >> M;
    info.push_back(M);

    int L1, L2;
    char c;
    cin >> L1 >> c >> L2;
    info.push_back(L1 * 100 + L2);

    int S;
    cin >> S;
    info.push_back(S);
}

bool award_scholarship(const vector<int>& info) {
    return ((info[SCORE_IDX] >= SCORE_LOWER_BOUND)
            && (info[CREDIT_IDX] >= CREDIT_LOWER_BOUND));
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, sum;
    vector<int> M;

    read_quartile(M);

    for (sum = 0, cin >> N; N > 0; N--) {
        vector<int> s;
        read_student_info(s);
        sum += award_scholarship(s)?M[s[QUARTILE_IDX]]:0;
    }

    cout << sum << '\n';
    return 0;
}