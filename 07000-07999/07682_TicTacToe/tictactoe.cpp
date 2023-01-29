#include    <iostream>
#include    <string>
#include    <vector>
#include    <algorithm>

using namespace std;

#define BOARD_SIZE          9
#define NUM_OF_WAYS_TO_WIN  8
#define LEN_OF_WIN_PATTERN  3
#define INITIAL_STATE       "........."

#define EMPTY   '.'
#define PLAYER1 'X'
#define PLAYER2 'O'

#define INVALID()   {cout<<"invalid\n";continue;}

const int win_state[NUM_OF_WAYS_TO_WIN][LEN_OF_WIN_PATTERN] =
    {{0,1,2},{0,3,6},{0,4,8},{1,4,7},
        {2,5,8},{2,4,6},{3,4,5},{6,7,8}};

bool    win(const string& board,char player)
{
    bool    ret = false;

    for(int i=0;i<NUM_OF_WAYS_TO_WIN;i++)
    {
        int cnt = 0;

        for(int j=0;j<LEN_OF_WIN_PATTERN;j++)
        {
            if( board[win_state[i][j]] == player )
            {
                cnt++;
            }
        }

        if( cnt == LEN_OF_WIN_PATTERN )
        {
            ret = true;
            break;
        }
    }

    return  ret;
}

int     get_num_of_pieces(const string& board,char p)
{
    int ret = 0;

    for(int i=0;i<board.length();i++)
    {
        if( board[i] == p )
        {
            ret++;
        }
    }

    return  ret;
}

bool    simulate(const string& board)
{
    int         i;
    vector<int> pos;

    for(i=0;i<board.length();i++)
    {
        if( board[i] != EMPTY )
        {
            pos.push_back(i);
        }
    }

    do{
        string  current = INITIAL_STATE;
        
        for(i=0;i<pos.size();i++)
        {
            char    c = (i%2==0)?PLAYER1:PLAYER2;

            current[pos[i]] = c;

            if( win(current,c) && i!=pos.size()-1 )
            {
                break;
            }
        }
        
        if( board == current )
        {
            return  true;
        }
    }while(next_permutation(pos.begin(),pos.end()));

    return  false;
}
int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for(;;)
    {
        string  s;

        cin>>s;

        if( s == "end" )
        {
            break;
        }

        int num_of_player1 = get_num_of_pieces(s,PLAYER1);
        int num_of_player2 = get_num_of_pieces(s,PLAYER2);

        if( !(num_of_player1==num_of_player2 
                || (num_of_player1-num_of_player2)==1) )
        {
            INVALID();
        }

        if( win(s,PLAYER2) &&
                (num_of_player1+num_of_player2)==BOARD_SIZE )
        {
            INVALID();
        }

        if( !(win(s,'X')||win(s,'O')) &&
                (num_of_player1+num_of_player2)!=BOARD_SIZE )
        {
            INVALID();
        }

        if( simulate(s) != true )
        {
            INVALID();
        }

        cout<<"valid\n";
    }

    return  0;
}