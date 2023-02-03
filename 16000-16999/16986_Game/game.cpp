#include    <iostream>
#include    <vector>
#include    <set>
#include    <algorithm>

using namespace std;

#define MAX_TABLE_SIZE      (9+1)
#define MAX_NUM_OF_GAMES    20

#define FALSE   0
#define TRUE    1
#define NONE    -1

#define Jiwoo       0
#define Kyunghee    1
#define Minho       2
#define MAX_PLAYER  3

#define WIN     2
#define TIE     1
#define LOSE    0

static int  N,K;
static int  table[MAX_TABLE_SIZE][MAX_TABLE_SIZE];
static vector<int>  hands[MAX_PLAYER];

#define read_hands(person) \
    for(int i=0;i<MAX_NUM_OF_GAMES;i++){\
        int n;cin>>n;hands[(person)].push_back(n);}

int input(void)
{
    cin>>N>>K;

    for(int row=1;row<=N;row++)
    {
        for(int col=1;col<=N;col++)
        {
            cin>>table[row][col];
        }
    }

    read_hands(Kyunghee);
    read_hands(Minho);
    
    for(int i=1;i<=N;i++)
    {
        hands[Jiwoo].push_back(i);
    }

    return  0;
}

int simulate(void)
{
    int ret = NONE;
    int ptr[MAX_PLAYER],num_of_wins[MAX_PLAYER];

    fill(ptr,ptr+MAX_PLAYER,0);
    fill(num_of_wins,num_of_wins+MAX_PLAYER,0);
    
    for(int p1=Jiwoo,p2=Kyunghee,p3=Minho;;)
    {
        int win_player,lose_player;

        if( ptr[p1]==hands[p1].size()
                || ptr[p2]==hands[p2].size() )
        {
            break;
        }

        int p1_hand = hands[p1][ptr[p1]++];
        int p2_hand = hands[p2][ptr[p2]++];

        switch(table[p1_hand][p2_hand])
        {
            case    LOSE:
                win_player = p2;
                lose_player = p1;
                break;
            case    TIE:
                win_player = max(p1,p2);
                lose_player = min(p1,p2);
                break;
            case    WIN:
                win_player = p1;
                lose_player = p2;
                break;
            default:
                break;
        }

        if( ++num_of_wins[win_player] == K )
        {
            ret = win_player;
            break;
        }

        p1 = win_player;
        p2 = p3;
        p3 = lose_player;
    }

    return  ret;
}

int play_game(void)
{
    do{
        if( simulate() == Jiwoo )
        {
            return  TRUE;
        }
    }while(next_permutation(hands[Jiwoo].begin(),hands[Jiwoo].end()));

    return  FALSE;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<play_game()<<'\n';

    return  0;
}