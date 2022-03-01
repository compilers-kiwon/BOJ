#include    <iostream>
#include    <string>
#include    <cmath>

using namespace std;

#define A_PLAYER    0
#define B_PLAYER    1
#define MAX_PLAYER  2

#define get_win_player(score,p1,p2) (((score)[(p1)]>(score)[(p2)])?(p1):p2)
#define is_deuce(score,p1,p2)       ((score)[(p1)]>=3&&(score)[(p2)]>=3)

bool    end_game(int* score)
{
    bool    ret = false;

    if( is_deuce(score,A_PLAYER,B_PLAYER) == true )
    {
        ret = (abs(score[A_PLAYER]-score[B_PLAYER])>=2);
    }
    else
    {
        ret = (score[A_PLAYER]>=4||score[B_PLAYER]>=4);
    }

    return  ret;
}

void    simulate(const string& str,int* result)
{
    int     score[MAX_PLAYER];

    fill(&score[0],&score[MAX_PLAYER],0);

    for(int i=0;i<str.length();i++)
    {
        if( str[i] == 'A' )
        {
            score[A_PLAYER]++;
        }
        else
        {
            score[B_PLAYER]++;
        }

        if( end_game(score) == true )
        {
            int win_player = get_win_player(score,A_PLAYER,B_PLAYER);

            result[win_player]++;
            fill(&score[0],&score[MAX_PLAYER],0);
        }
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for(;;)
    {
        string  str;
        int     num_of_winning_games[MAX_PLAYER];

        cin>>str;

        if( str == "#" )
        {
            break;
        }

        fill(&num_of_winning_games[0],&num_of_winning_games[MAX_PLAYER],0);
        simulate(str,num_of_winning_games);

        cout<<"A "<<num_of_winning_games[A_PLAYER]<<" ";
        cout<<"B "<<num_of_winning_games[B_PLAYER]<<"\n";
    }

    return  0;
}