#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdint>

using namespace std;

void input(vector<int>& A) {
    int N;

    cin>>N;

    for (int i = 0; i < N; i++) {
        int num;
        cin>>num;
        A.push_back(num);
    }
}

void count_numbers(const vector<int>& A,
                    unordered_map<int, int64_t>& count_num) {
    for (int i = 0; i < A.size(); i++) {
        count_num[A[i]]++;
    }
}

int64_t solve(const vector<int>& A,
                unordered_map<int, int64_t>& count_num) {
    int64_t ret = 0;

    for (int i = 0; i < A.size() - 1; i++) {
        for (int j = i + 1; j < A.size(); j++) {
            const int& n1 = A[i];
            const int& n2 = A[j];
            int n3 = 0 - n1 - n2;

            ret += count_num[n3] - (n1==n3?1LL:0LL) - (n2==n3?1LL:0LL);
        }
    }

    return ret/3LL;
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<int> A;
    unordered_map<int, int64_t> count_num;

    input(A);
    count_numbers(A, count_num);
    cout<<solve(A, count_num)<<'\n';

    return 0;
}