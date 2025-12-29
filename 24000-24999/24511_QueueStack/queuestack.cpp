#include <iostream>
#include <deque>

using namespace std;

#define MAX_SIZE (100000+1)

#define QUEUE (0)
#define STACK (1)

int A[MAX_SIZE];

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    deque<int> dq;
    int N, M, B, C;

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    for (int i = 1; i <= N; i++) {
        cin >> B;
        if (A[i] == QUEUE) {dq.push_back(B);}
    }

    cin >> M;

    for (int i = 1; i <= M; i++) {
        cin >> C;
        dq.push_front(C);

        cout << dq.back() << ((i==M)?'\n':' ');
        dq.pop_back();
    }

    return 0;
}