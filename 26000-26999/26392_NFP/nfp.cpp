#include    <iostream>

using namespace std;

#define MAX_SIZE    (50+1)

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n,r,s;

    cin>>n>>r>>s;

    for (int i=1;i<=n;i++) {
        int     max_val,min_val;
        char    grid[MAX_SIZE][MAX_SIZE+1];

        for (int row=1;row<=r;row++) {
            cin>>&grid[row][1];
        }

        max_val = 0;
        min_val = MAX_SIZE;

        for (int col=1;col<=s;col++) {
            for (int row=1;row<=r;row++) {
                if (grid[row][col] == '#') {
                    max_val = max(max_val,row);
                    min_val = min(min_val,row);
                    break;
                }
            }
        }

        cout<<max_val-min_val<<'\n';
    }

    return  0;
}