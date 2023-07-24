#include    <iostream>
#include    <vector>
#include    <cmath>

using namespace std;

#define MAX_SIZE    8

typedef long long int   int64;

static char     d;
static int64    grid[MAX_SIZE+1][MAX_SIZE+1];

static vector<int64>    num[MAX_SIZE+1];

#define continue_if_empty(n)    {if((n)==0)continue;}

int simulate(void)
{
    switch(d)
    {
        case    'U':
        case    'D':
            for (int col=1;col<=MAX_SIZE+1;col++) {
                for (int row=(d=='U'?1:MAX_SIZE);
                        row!=(d=='U'?MAX_SIZE+1:0);d=='U'?row++:row--) {
                    continue_if_empty(grid[row][col]);
                    if (num[col].empty() || num[col].back()!=grid[row][col]) {
                        num[col].push_back(grid[row][col]);
                    } else {
                        num[col].back() *= -2;
                    }
                }
            }
            break;
        case    'L':
        case    'R':
            for (int row=1;row<=MAX_SIZE+1;row++) {
                for (int col=(d=='L'?1:MAX_SIZE);
                        col!=(d=='L'?MAX_SIZE+1:0);d=='L'?col++:col--) {
                    continue_if_empty(grid[row][col]);
                    if (num[row].empty() || num[row].back()!=grid[row][col]) {
                        num[row].push_back(grid[row][col]);
                    } else {
                        num[row].back() *= -2;
                    }
                }
            }
            break;
        default:
            // do nothing;
            break;
    }

    for (int i=1;i<=MAX_SIZE;i++) {
        vector<int64>& n=num[i];
        for (;n.size()!=MAX_SIZE;n.push_back(0));
        n.insert(n.begin(),0);
    }

    return  0;
}

int input(void)
{
    for (int row=1;row<=MAX_SIZE;row++) {
        for (int col=1;col<=MAX_SIZE;col++) {
            cin>>grid[row][col];
        }
    }

    cin>>d;
    return  0;
}

int print(void)
{
    switch(d)
    {
        case    'U':
        case    'D':
            for (int row=(d=='U'?1:MAX_SIZE);
                    row!=(d=='U'?MAX_SIZE+1:0);d=='U'?row++:row--) {
                for (int col=1;col<=MAX_SIZE;col++) {
                    cout<<abs(num[col][row])<<' ';
                }
                cout<<'\n';
            }
            break;
        case    'L':
        case    'R':
            for (int row=1;row<=MAX_SIZE;row++) {
                for (int col=(d=='L'?1:MAX_SIZE);
                        col!=(d=='L'?MAX_SIZE+1:0);d=='L'?col++:col--) {
                    cout<<abs(num[row][col])<<' ';
                }
                cout<<'\n';
            }
            break;
        default:
            // do nothing;
            break;
    }

    return  0;    
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    simulate();
    print();

    return  0;
}