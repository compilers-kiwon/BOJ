#include    <iostream>

using namespace std;

#define MAX_SIZE    (50+1)

static int  N,M;
static char grid[MAX_SIZE][MAX_SIZE+1];

int input(void)
{
    cin>>N>>M;

    for(int row=1;row<=N;row++)
    {
        cin>>&grid[row][1];
    }

    return  0;
}

int simulate(void)
{
    for(int row=1;row<=N;row++)
    {
        for(int head=1,tail=M;head<tail;head++,tail--)
        {
            char&   left_color = grid[row][head];
            char&   right_color = grid[row][tail];

            left_color = (left_color=='.')?right_color:left_color;
            right_color = (right_color=='.')?left_color:right_color;
        }
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    simulate();

    for(int row=1;row<=N;row++)
    {
        cout<<&grid[row][1]<<'\n';
    }

    return  0;
}