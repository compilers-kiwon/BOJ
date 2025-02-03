#include <iostream>

using namespace std;

#define MAX_NUM_OF_PROBLEMS (100000+1)

const int CPP = 1;
const int JAVA = 2;
const int PYTHON = 3;

int solutions[MAX_NUM_OF_PROBLEMS];

int main (void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n, m;

    cin>>n>>m;

    for (int i = 1; i <= m; i++) {
        int p, L;

        cin>>p>>L;
        solutions[p] |= (1 << L);
    }

    for (int i = 1; i <= n; i++) {
        if ((solutions[i] & (1 << CPP)) != 0
                && (solutions[i] & (1 << JAVA)) != 0) {
            cout<<i<<'\n';
        }
    }

    return 0;
}