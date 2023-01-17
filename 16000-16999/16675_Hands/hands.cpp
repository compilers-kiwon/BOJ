#include    <iostream>

using namespace std;

#define MAX_SIZE        3
#define NUM_OF_PLAYERS  2
#define NUM_OF_HANDS    2
#define get_idx(c)      ((c)=='S'?0:(c)=='R'?1:2)

int hands[NUM_OF_PLAYERS][NUM_OF_HANDS];
const char* name[NUM_OF_PLAYERS] = {"MS","TK"};

#define NONE    -1

void    input(void)
{
    for(int p=0;p<NUM_OF_PLAYERS;p++)
    {
        for(int h=0;h<NUM_OF_HANDS;h++)
        {
            char    c;

            cin>>c;
            hands[p][h] = get_idx(c);
        }
    }
}

bool    play(int offense_player,int defense_player)
{
    bool    ret = false;

    for(int h1=0;h1<NUM_OF_HANDS;h1++)
    {
        bool    win = true;

        for(int h2=0;h2<NUM_OF_HANDS;h2++)
        {
            if( hands[defense_player][h2] !=
                    ((hands[offense_player][h1]+2)%MAX_SIZE) )
            {
                win = false;
                break;
            }
        }

        if( win == true )
        {
            ret = true;
            break;
        }
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    
    int num_of_wins[NUM_OF_PLAYERS],n;

    input();
    fill(num_of_wins,num_of_wins+NUM_OF_PLAYERS,0);

    for(int p=0;p<NUM_OF_PLAYERS;p++)
    {
        if( play(p,(p+1)%NUM_OF_PLAYERS) == true )
        {
            num_of_wins[p]++;
        }
    }

    n = NONE;

    for(int p=0;p<NUM_OF_PLAYERS;p++)
    {
        if( num_of_wins[p] != 0 )
        {
            if( n == NONE )
            {
                n = p;
            }
            else
            {
                n = NONE;
                break;
            }
        }
    }

    if( n == NONE )
    {
        cout<<"?\n";
    }
    else
    {
        cout<<name[n]<<'\n';
    }

    return  0;
}