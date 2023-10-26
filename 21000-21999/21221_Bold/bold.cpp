#include    <iostream>

using namespace std;

const static int MAX_SIZE = 100+1;

static int  n,m;
static char grid[MAX_SIZE][MAX_SIZE+1];

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>n>>m;

    for (int row=1;row<=n;row++) {
        char    buf[MAX_SIZE+1];

        cin>>&buf[1];

        for (int col=1;col<=m;col++) {
            if (buf[col] == '#') {
                grid[row][col] = grid[row][col+1] =
                    grid[row+1][col] = grid[row+1][col+1] = '#';
            }
        }
    }

    for (int row=1;row<=n;row++) {
        for (int col=1;col<=m;col++) {
            cout<<(grid[row][col]=='#'?'#':'.');
        }
        cout<<'\n';
    }

    return  0;
}