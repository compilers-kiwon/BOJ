#include    <iostream>

using namespace std;

#define MAX_SIZE    (10+1)

#define UP_DOWN     (1)
#define LEFT_RIGHT  (2)
#define NUM_OF_DIRS (2+1)

static int  N,D;
static char grid[MAX_SIZE][MAX_SIZE+1];
static char turned[0x100][NUM_OF_DIRS];

int init(void)
{
    turned['d'][UP_DOWN] = 'q';
    turned['d'][LEFT_RIGHT] = 'b';

    turned['b'][UP_DOWN] = 'p';
    turned['b'][LEFT_RIGHT] = 'd';

    turned['q'][UP_DOWN] = 'd';
    turned['q'][LEFT_RIGHT] = 'p';

    turned['p'][UP_DOWN] = 'b';
    turned['p'][LEFT_RIGHT] = 'q';

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    init();
    cin>>N>>D;

    for (int row=1;row<=N;row++) {
        cin>>&grid[row][1];
    }

    for (int row=1;row<=N;row++) {
        for (int col=1;col<=N;col++) {
            grid[row][col] = turned[grid[row][col]][D];
        }
    }

    for (int row=1;row<=N;row++) {
        cout<<&grid[row][1]<<'\n';
    }

    return  0;
}