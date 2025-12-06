#include <iostream>
#include <vector>

using namespace std;

#define FIXED_AVG (10000)

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, A, sum;
    vector<int> seq;

    cin >> N, A = sum = 0;

    for (int i = 1; i <= N; i++, A++) {
        seq.push_back(A), sum += A;
    }

    int diff = (FIXED_AVG * N) - sum;
    
    seq.back() += diff;
    seq.push_back(FIXED_AVG);
    
    for (int i = 0; i <= N; i++) {
        cout << seq[i] << ((i==N)?'\n':' ');
    }
    
    return 0;
}