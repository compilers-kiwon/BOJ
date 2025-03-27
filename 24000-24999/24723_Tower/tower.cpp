#include <iostream>

using namespace std;

int N, cnt;

void dfs(int row, int col) {
    if (row > (N + 1)) {
        cnt++;
        return;
    }

    for (int c = col; c <= min(col+1, row); c++) {
        dfs(row+1, c);
    }
}

int main(void) {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N;
    dfs(1,1);
    
    cout<<cnt<<'\n';
    return 0;
}