#include    <iostream>
#include    <vector>

using namespace std;

#define MAX_NUM_OF_PLAYERS  (100000+1)
#define MAX_AREA            53

static int  T,N,pos[MAX_NUM_OF_PLAYERS];
static int  blocked[MAX_NUM_OF_PLAYERS],cnt_of_blocked;
static int  item_state[MAX_NUM_OF_PLAYERS][MAX_AREA+1];

static vector<int>  cheating_log;

#define INCORRECT   0
#define CORRECT     1

#define consume(item)   (item)=max((item)-1,0)

int simulate(void)
{
    int     player,p1,p2,ret;
    char    action;

    cin>>player>>action;
    ret = CORRECT;

    switch(action)
    {
        case    'M':
            cin>>p1;
            pos[player] = p1;
            break;
        case    'F':
            cin>>p1;
            ret = (pos[player]!=p1)?INCORRECT:CORRECT;
            item_state[player][p1]++;
            break;
        case    'C':
            cin>>p1>>p2;
            ret = (item_state[player][p1]==0
                    ||item_state[player][p2]==0)?INCORRECT:CORRECT;
            consume(item_state[player][p1]);
            consume(item_state[player][p2]);
            break;
        case    'A':
            cin>>p1;
            if( (ret=(pos[player]!=pos[p1])?INCORRECT:CORRECT) == INCORRECT )
            {
                cnt_of_blocked += (++blocked[player]==1)?1:0;
            }
            break;
        default:
            // do nothing
            break;
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>T>>N;
    fill(&pos[1],&pos[N+1],1);

    for(int t=0;t<T;)
    {
        cin>>t;
        
        if( simulate() == INCORRECT )
        {
            cheating_log.push_back(t);
        }
    }

    cout<<cheating_log.size()<<'\n';
    for(int i=0;i<cheating_log.size();i++)
    {
        cout<<cheating_log[i]<<
            ((i==cheating_log.size()-1)?'\n':' ');
    }

    cout<<cnt_of_blocked<<'\n';
    for(int i=1;cnt_of_blocked!=0;i++)
    {
        if( blocked[i] != 0 )
        {
            cout<<i<<((--cnt_of_blocked==0)?'\n':' ');
        }
    }

    return  0;
}