#include    <iostream>

using namespace std;

#define MAX_SIZE    (100+1)
#define YELLOW      0
#define WHITE       1
#define TO_RIGHT    2
#define TO_LEFT     3

#define RIGHT       0
#define LEFT        1
#define MAX_DIR     2
#define TURN_DIR(d) (((d)+1)%MAX_DIR)

const int   step[MAX_DIR] = {1,-1};

int m,n,pos,dir,t[MAX_SIZE];

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

void    input(void)
{
    cin>>m>>n;

    for(int i=1;i<=m;i++)
    {
        cin>>t[i];

        switch(t[i])
        {
            case    TO_LEFT:
                pos = i;
                dir = LEFT;
                break;
            case    TO_RIGHT:
                pos = i;
                dir = RIGHT;
                break;
            default:
                // do nothing
                break;
        }
    }
}

int     play_game(void)
{
    int ret = 0;

    for(int i=1;i<=n;)
    {
        int adj = pos+step[dir];

        if( IN_RANGE(1,adj,m) == true )
        {
            pos = adj;
            ret += (t[pos]==YELLOW)?1:0;
            i++;
        }
        else
        {
            dir = TURN_DIR(dir);
        }
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for(int t=1;t<=T;t++)
    {
        input();
        cout<<play_game()<<'\n';
    }

    return  0;
}