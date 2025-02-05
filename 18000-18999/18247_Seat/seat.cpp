#include <iostream>

using namespace std;

int get_pos(int row_size, int col_size) {
    const int L_row = ((int)('L'-'A')) + 1;
    const int _4_col = 4;

    if (row_size < L_row || col_size < _4_col) {
        return -1;
    }

    return ((L_row - 1)*col_size + _4_col);
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    
    int T;

    cin>>T;

    for (int t = 1; t <= T; t++) {
        int N, M;

        cin>>N>>M;
        cout<<get_pos(N, M)<<'\n';
    }

    return 0;
}