#include    <iostream>

using namespace std;

#define LENGTH_OF_BOARD     2019
#define MAX_NUM_OF_PIECES   (100+1)
#define EMPTY               0

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,M,board_status[LENGTH_OF_BOARD+1],pos[MAX_NUM_OF_PIECES];

    cin>>N;
    fill(&board_status[1],&board_status[LENGTH_OF_BOARD+1],EMPTY);

    for(int i=1;i<=N;i++)
    {
        int X;

        cin>>X;

        board_status[X] = i;
        pos[i] = X;
    }

    cin>>M;

    for(int i=1;i<=M;i++)
    {
        int A;

        cin>>A;

        if( pos[A]!=LENGTH_OF_BOARD && board_status[pos[A]+1]==EMPTY )
        {
            swap(board_status[pos[A]],board_status[pos[A]+1]);
            pos[A]++;
        }
    }

    for(int i=1;i<=N;i++)
    {
        cout<<pos[i]<<'\n';
    }

    return  0;
}