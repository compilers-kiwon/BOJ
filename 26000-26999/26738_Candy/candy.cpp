#include    <iostream>
#include    <map>

using namespace std;

#define MAX_SIZE                (500000+1)
#define REQUIRED_NUM_OF_PIECES  3

#define NONE    "NIE"
#define INF     0x7FFFFFFF

int N,piece[MAX_SIZE];

void    input(void)
{
    cin>>N;

    for(int i=1;i<=N;i++)
    {
        cin>>piece[i];
    }
}

void    remove_pieces(int& h,int& t,map<int,int>& c)
{
    for(;h<=t;h++)
    {
        if( --c[piece[h]] == 0 )
        {
            c.erase(piece[h]);
        }

        if( piece[h] == piece[t] )
        {
            h++;
            break;
        }
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int             min_len;
    map<int,int>    candy;

    input();
    min_len = INF;

    for(int head=1,tail=1;tail<=N;tail++)
    {
        int&    new_piece = piece[tail];

        candy[new_piece]++;

        if( candy[new_piece] == REQUIRED_NUM_OF_PIECES )
        {
            remove_pieces(head,tail,candy);
            min_len = min(min_len,(tail-head)+2);
        }
    }

    if( min_len == INF )
    {
        cout<<NONE<<'\n';
    }
    else
    {
        cout<<min_len<<'\n';
    }

    return  0;
}