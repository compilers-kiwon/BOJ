#include    <iostream>
#include    <set>

using namespace std;

#define MAX_SIZE        48
#define MAX_PLAYERS     3
#define PLAYER_IDX(i)   ((i)%MAX_PLAYERS)
#define MAX_ARR         2
#define NONE            -1

static int      N,S[MAX_SIZE],card_arr[MAX_ARR][MAX_SIZE],ptr;
static set<int> target_in_hands[MAX_PLAYERS];

#define NEXT_ARR_PTR(ptr)   (((ptr)+1)%MAX_ARR)

void    input(void)
{
    cin>>N;

    for(int i=0;i<N;i++)
    {
        int P;
        
        cin>>P;
        target_in_hands[P].insert(i);
    }

    for(int i=0;i<N;i++)
    {
        cin>>S[i];
        card_arr[ptr][i] = i;
    }
}

bool    allocate_card(void)
{
    set<int>    current_in_hands[MAX_PLAYERS];

    for(int i=0;i<N;i++)
    {
        current_in_hands[PLAYER_IDX(i)].insert(card_arr[ptr][i]);
    }

    for(int i=0;i<MAX_PLAYERS;i++)
    {
        if( target_in_hands[i] != current_in_hands[i] )
        {
            return  false;
        }
    }

    return  true;
}

void    mix_card(void)
{
    int current = ptr;
    int next = NEXT_ARR_PTR(current);

    for(int i=0;i<N;i++)
    {
        card_arr[next][S[i]] = card_arr[current][i];
    }

    ptr = next;
}

bool    is_infinite_loop(void)
{
    for(int i=0;i<N;i++)
    {
        if( card_arr[ptr][i] != i )
        {
            return  false;
        }
    }

    return  true;
}

int     simulate(void)
{
    int ret;

    for(ret=0;allocate_card()==false;ret++)
    {
        mix_card();

        if( is_infinite_loop() == true )
        {
            ret = NONE;
            break;
        }
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