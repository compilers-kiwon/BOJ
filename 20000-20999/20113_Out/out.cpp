#include    <iostream>

using namespace std;

#define MAX_SIZE    (100+1)
#define NONE        0

int N,vote[MAX_SIZE];

void    input(void)
{
    cin>>N;

    for(int i=1;i<=N;i++)
    {
        int v;

        cin>>v;
        vote[v]++;
    }
}

int     check(void)
{
    int max_vote,cnt,ret;

    max_vote = cnt = 0;

    for(int i=1;i<=N;i++)
    {
        if( vote[i] >= max_vote )
        {
            if( vote[i] > max_vote )
            {
                cnt = 0;
            }

            cnt++;
            max_vote = vote[i];
            ret = i;
        }
    }

    if( max_vote==0 || cnt!=1 )
    {
        ret = NONE;
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int answer;

    input();
    answer = check();

    if( answer != NONE )
    {
        cout<<answer<<'\n';
    }
    else
    {
        cout<<"skipped\n";
    }

    return  0;
}