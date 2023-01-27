#include    <iostream>

using namespace std;

#define MAX_SIZE    (100+1)

static int  N,M,score_board[MAX_SIZE],target[MAX_SIZE];

#define input_arr(arr,size) for(int i=1;i<=(size);i++)cin>>(arr)[(i)];

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N>>M;
    input_arr(target,M);

    for(int i=1;i<=M;i++)
    {
        for(int j=1;j<=N;j++)
        {
            int t;

            cin>>t;

            if( target[i] == t )
            {
                score_board[j]++;
            }
            else
            {
                score_board[target[i]]++;
            }
        }
    }

    for(int i=1;i<=N;i++)
    {
        cout<<score_board[i]<<'\n';
    }

    return  0;
}