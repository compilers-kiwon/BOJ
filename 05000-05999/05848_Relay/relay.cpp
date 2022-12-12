#include    <iostream>
#include    <vector>

using namespace std;

#define MAX_SIZE            1000
#define END_OF_NOT_LOOPY    0

int         N;
vector<int> sender[MAX_SIZE+1];

void    input(void)
{
    cin>>N;

    for(int i=1;i<=N;i++)
    {
        int F;

        cin>>F;
        sender[F].push_back(i);
    }
}

int     get_num_of_not_loopy(int receiver)
{
    int ret = 1;

    for(int i=0;i<sender[receiver].size();i++)
    {
        ret += get_num_of_not_loopy(sender[receiver][i]);
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<get_num_of_not_loopy(END_OF_NOT_LOOPY)-1<<'\n';

    return  0;
}