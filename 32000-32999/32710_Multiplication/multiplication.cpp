#include <iostream>

using namespace std;

#define MAX_NUM (100+1)

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    int table[MAX_NUM] = {0, };

    fill(&table[1], &table[9+1], 1);
    
    for (int A = 2; A <= 9; A++) {
        for (int B = 1; B <= 9; B++) {
            table[A*B] = 1;
        }
    }

    cin >> N;
    cout << table[N] << '\n';

    return 0;
}