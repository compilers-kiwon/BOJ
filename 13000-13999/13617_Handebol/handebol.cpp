#include    <iostream>

using namespace std;

bool    score_for_all_game(int num_of_games)
{
    bool    ret = true;

    for(int i=1;i<=num_of_games;i++)
    {
        int X;

        cin>>X;

        if( X == 0 )
        {
            ret = false;
        }
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,M,cnt;

    cin>>N>>M;
    cnt = 0;

    for(int i=1;i<=N;i++)
    {
        cnt += (score_for_all_game(M)?1:0);
    }

    cout<<cnt<<'\n';

    return  0;
}