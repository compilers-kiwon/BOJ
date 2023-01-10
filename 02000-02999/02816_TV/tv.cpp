#include    <iostream>
#include    <string>

using namespace std;

#define MAX_NUM_OF_CHANNELS (100+1)

int     N,kbs1_idx,kbs2_idx;
string  ch[MAX_NUM_OF_CHANNELS];

#define MOVE_DOWN   '1'
#define MOVE_UP     '2'
#define CHANGE_DOWN '3'
#define CHANGE_UP   '4'

void    input(void)
{
    cin>>N;

    for(int i=1;i<=N;i++)
    {
        cin>>ch[i];

        if( ch[i] == "KBS1" )
        {
            kbs1_idx = i;
        }

        if( ch[i] == "KBS2" )
        {
            kbs2_idx = i;
        }
    }
}

string  simulate(void)
{
    string  ret;
    int     current_pos = 1;

    if( min(kbs1_idx,kbs2_idx) != 1 )
    {
        for(int i=1;i<=min(kbs1_idx,kbs2_idx)-1;i++)
        {
            ret.push_back(MOVE_DOWN);
        }

        for(int i=1;i<=min(kbs1_idx,kbs2_idx)-1;i++)
        {
            ret.push_back(CHANGE_UP);
        }

        current_pos = 1;
    }

    if( max(kbs1_idx,kbs2_idx) != 2 )
    {
        for(int i=1;i<=max(kbs1_idx,kbs2_idx)-1;i++)
        {
            ret.push_back(MOVE_DOWN);
        }

        for(int i=1;i<=max(kbs1_idx,kbs2_idx)-2;i++)
        {
            ret.push_back(CHANGE_UP);
        }

        current_pos = 2;
    }

    if( kbs2_idx < kbs1_idx )
    {
        ret.push_back((current_pos==1)?CHANGE_DOWN:CHANGE_UP);
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<simulate()<<'\n';

    return  0;
}