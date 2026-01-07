#include <iostream>
#include <queue>

using namespace std;

#define MAX_SIZE (2000)

int order[MAX_SIZE];

int input(priority_queue<int>& j) {
    int N;

    cin >> N;

    for (int i = 0; i < N; i++) {
        int P;
        cin >> P;
        j.push(P);
    }

    return N;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, sum;
    priority_queue<int> j;

    N = input(j), sum = 0;

    for (int h = 0, t = N - 1; h <= t; h++, t--) {
        order[h] = j.top(); j.pop();
        if (h != t) {order[t] = j.top(); j.pop();}
    }

    for (int i = 0; i < N; i++) {
        sum += order[i] * order[(i+1)%N];
    }

    cout << sum << '\n';

    for (int i = 0; i < N; i++) {
        cout << order[i] << ' ';
    }

    cout <<'\n';
    return 0;
}