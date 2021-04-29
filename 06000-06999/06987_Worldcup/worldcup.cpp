#include    <iostream>
#include    <vector>
#include    <algorithm>

using namespace std;

#define NUM_OF_COUNTRY  6
#define NUM_OF_TEST     4

#define WIN     1
#define TIE     0
#define LOSE    -1

typedef struct{int w,l,t;}  Record;

int     score_table[NUM_OF_COUNTRY+1][NUM_OF_COUNTRY+1];
Record  record[NUM_OF_COUNTRY+1];

bool   input(void)
{
    bool    ret = true;

    for(int i=1;i<=NUM_OF_COUNTRY;i++)
    {
        Record& r = record[i];

        cin>>r.w>>r.t>>r.l;

        if( r.w+r.t+r.l >= NUM_OF_COUNTRY )
        {
            ret = false;
        }
    }

    return  ret;
}

bool    compare_score(void)
{
    for(int i=1;i<=NUM_OF_COUNTRY;i++)
    {
        int w=0,l=0,t=0;

        for(int j=1;j<=NUM_OF_COUNTRY;j++)
        {
            if( i == j )
            {
                continue;
            }

            switch(score_table[i][j])
            {
                case    WIN:
                    w++;
                    break;
                case    TIE:
                    t++;
                    break;
                case    LOSE:
                    l++;
                    break;
                default:
                    // do nothing
                    break;
            }
        }
        
        if( w!=record[i].w || t!=record[i].t || l!=record[i].l )
        {
            return  false;
        }
    }

    return  true;
}

bool    build_score_table(vector<int>& opposite,int my_team)
{
    int ptr,prev_win,prev_tie,prev_lose;

    ptr = prev_win = prev_tie = prev_lose = 0;

    for(int i=1;i<my_team;i++)
    {
        switch(score_table[my_team][i])
        {
            case    WIN:
                prev_win++;
                break;
            case    LOSE:
                prev_lose++;
                break;
            case    TIE:
                prev_tie++;
                break;
            default:
                // do nothing
                break;
        }
    }

    if( prev_win>record[my_team].w || prev_lose>record[my_team].l || prev_tie>record[my_team].t )
    {
        return  false;
    }

    // 1. win
    for(int i=1;i<=record[my_team].w-prev_win;i++,ptr++)
    {
        score_table[my_team][opposite[ptr]] = WIN;
        score_table[opposite[ptr]][my_team] = LOSE;
    }

    // 2. lose
    for(int i=1;i<=record[my_team].l-prev_lose;i++,ptr++)
    {
        score_table[my_team][opposite[ptr]] = LOSE;
        score_table[opposite[ptr]][my_team] = WIN;
    }

    // 3. tie
    for(int i=1;i<=record[my_team].t-prev_tie;i++,ptr++)
    {
        score_table[my_team][opposite[ptr]] = TIE;
        score_table[opposite[ptr]][my_team] = TIE;
    }

    return  true;
}

bool    simulate(int current_team)
{
    if( current_team == NUM_OF_COUNTRY )
    {
        return  compare_score();
    }

    vector<int> opposite;

    for(int i=current_team+1;i<=NUM_OF_COUNTRY;i++)
    {
        opposite.push_back(i);
    }

    do{
        if( build_score_table(opposite,current_team) && simulate(current_team+1) )
        {
            return  true;
        }
    }while(next_permutation(opposite.begin(),opposite.end()));

    return  false;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for(int i=1;i<=NUM_OF_TEST;i++)
    {
        if( input() && simulate(1) )
        {
            cout<<"1 ";
        }
        else
        {
            cout<<"0 ";
        }
    }
    cout<<'\n';

    return  0;
}
