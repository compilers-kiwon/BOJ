#include <iostream>
#include <queue>
#include <cstdint>

using namespace std;

#define get_one_file(buf,pq) {(buf)=-((pq).top());(pq).pop();}

void input(priority_queue<int64_t>& pq) {
    int K;

    cin>>K;

    for (int i = 1; i <= K; i++) {
        int64_t size;
        cin>>size;
        pq.push(-size);
    }
}

int64_t merge(priority_queue<int64_t>& pq) {
    int64_t ret = 0;

    for (; pq.size() > 1;) {
        int64_t f1, f2, cost;

        get_one_file(f1, pq);
        get_one_file(f2, pq);

        ret += (cost = f1 + f2);
        pq.push(-cost);
    }

    return ret;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for (int i = 1; i <= T; i++) {
        priority_queue<int64_t> pq;
        input(pq);
        cout<<merge(pq)<<'\n';
    }

    return 0;
}