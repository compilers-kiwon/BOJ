#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void input(priority_queue<int>& pq, int& M, int& K) {
    int N;

    cin>>N>>M>>K;

    for (int i = 1; i <= N; i++) {
        int D;
        cin>>D;
        pq.push(D);
    }
}

void work(priority_queue<int>& pq, int M, 
                int K, vector<int>& satification) {
    satification.push_back(0);

    for (;!pq.empty();) {
        int P = pq.top();

        pq.pop();
        satification.push_back(satification.back()/2 + P);
        
        if ((P-M) > K) {
            pq.push(P-M);
        }
    }
}

int main(void) {
    int M,K, num_of_required_days;
    vector<int> s;
    priority_queue<int> job;

    input(job, M, K);
    work(job, M, K, s);

    cout<<s.size()-1<<'\n';

    for (int i = 1; i < s.size(); i++) {
        cout<<s[i]<<'\n';
    }

    return 0;
}