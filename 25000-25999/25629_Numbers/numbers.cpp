#include <iostream>
#include <queue>

using namespace std;

#define EVEN (0)
#define ODD (1)
#define MAX_NUM (2)

int input(priority_queue<int> pq[]) {
    int N;

    cin>>N;

    for (int i = 1; i <= N; i++) {
        int a;
        cin>>a;
        pq[a%MAX_NUM].push(-a);
    }

    return N;
}

int simulate(int num_of_numbers, priority_queue<int> pq[]) {
    for (int i = 1; i <= num_of_numbers; i++) {
        if (pq[i%MAX_NUM].empty()) {
            return 0;
        }

        pq[i%MAX_NUM].pop();
    }

    return 1;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    priority_queue<int> pq[MAX_NUM];
    int N = input(pq);

    cout<<simulate(N, pq)<<'\n';
    return 0;
}