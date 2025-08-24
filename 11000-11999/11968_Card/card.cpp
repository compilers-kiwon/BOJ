#include <iostream>
#include <stack>

using namespace std;

#define MAX_NUM (100000+1)

bool elsie[MAX_NUM];

void input(stack<int>& e, stack<int>& b) {
    int N;

    cin >> N;

    for (int i = 1; i <= N; i++) {
        int c;
        cin >> c;
        elsie[c] = true;
    }

    for (int i = 1; i <= 2*N; i++) {
        if (elsie[i] == true) {
            e.push(i);
        } else {
            b.push(i);
        }
    }
}

int simualte(stack<int>& e, stack<int>& b) {
    int ret;

    for (ret = 0; !e.empty() && !b.empty(); e.pop()) {
        if (b.top() > e.top()) {
            ret++, b.pop();
        }
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    stack<int> elsie_cards, bessie_cards;

    input(elsie_cards, bessie_cards);
    cout << simualte(elsie_cards, bessie_cards) << '\n';

    return 0;
}