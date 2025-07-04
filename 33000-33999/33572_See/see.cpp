#include <iostream>

using namespace std;

typedef long long int int64;

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    int64 M, sum;

    sum = 0;
    cin>>N>>M;

    for (int i = 1; i <= N; i++) {
        int64 A;
        cin>>A;
        sum += A - 1;
    }

    cout<<((sum>=M)?"DIMI":"OUT")<<'\n';

    return 0;
}