#include    <iostream>
#include    <queue>
#include    <map>

using namespace std;

#define MAX_SIZE    (500000+1)

#define RELEASED    0
#define ACQUIRED    1

typedef struct{int n,op,r_idx;} Action;

#define OP_NONE     0
#define OP_NEXT     1
#define OP_ACQUIRE  2
#define OP_RELEASE  3

static queue<Action>    pile;
static map<int,int>     resource_state;
static queue<int>       player;
static Action           in_hands[MAX_SIZE];

#define acquire_resource(r) (resource_state[(r)]=ACQUIRED)
#define release_resource(r) (resource_state[(r)]=RELEASED)
#define is_available(r)     (resource_state[(r)]==RELEASED)
#define discard_card(c)     ((c).n=OP_NONE)

int input(void)
{
    int N,T;

    cin>>N>>T;

    for(int i=1;i<=T;i++)
    {
        int p;

        cin>>p;
        player.push(p);
    }

    for(int i=1;i<=T;i++)
    {
        Action  a;
        string  tmp;

        cin>>a.n>>tmp;
        a.op = (tmp=="next"?OP_NEXT:
                (tmp=="acquire")?OP_ACQUIRE:OP_RELEASE);
        if (a.op != OP_NEXT) cin>>a.r_idx;
        pile.push(a);
    }

    return  0;
}

int simulate(void)
{
    for(;!player.empty();player.pop())
    {
        int     cur_player = player.front();
        Action& current = in_hands[cur_player];

        if( current.n == OP_NONE )
        {
            current = pile.front();
            pile.pop();
        }

        cout<<current.n<<'\n';

        switch(current.op)
        {
            case    OP_RELEASE:
                release_resource(current.r_idx);
            case    OP_NEXT:
                discard_card(current);
                break;
            case    OP_ACQUIRE:
                if( is_available(current.r_idx) )
                {
                    acquire_resource(current.r_idx);
                    discard_card(current);
                }
                break;
            default:
                // do nothing
                break;
        }
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    simulate();

    return  0;
}