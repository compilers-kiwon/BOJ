#include <iostream>
#include <vector>

using namespace std;

#define MAX_NUM (200000)
#define NUM_OF_CARDS (3)
#define OFFSET (3)

bool A[MAX_NUM+1];

bool simulate(const vector<int>& cards) {
    int cnt = 0;

    for (int i = 0; i < cards.size(); i++) {
        cnt += A[cards[i]]?1:0;
    }

    return (cnt == NUM_OF_CARDS);
}

void select_cards(vector<int>& cards, int num) {
    for (int cur = num, i = 0; i < NUM_OF_CARDS; cur += OFFSET, i++) {
        if (cur <= MAX_NUM) {
            cards.push_back(cur);
        }
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;

    for (cin >> N; N > 0; N--) {
        int num;
        cin >> num;
        A[num] = true;
    }

    for (int i = 1; i <= MAX_NUM; i++) {
        if (A[i] == false) {
            continue;
        }

        vector<int> c;

        select_cards(c, i);

        if (simulate(c) == true) {
            cout << "Yes\n";
            return 0;
        }
    }

    cout << "No\n";

    return 0;
}