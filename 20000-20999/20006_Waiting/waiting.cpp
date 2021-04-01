#include    <iostream>
#include    <vector>
#include    <string>
#include    <algorithm>

using namespace std;

typedef pair<string,int>    Player;
typedef vector<Player>      Room;

#define NONE    -1
#define DIFF   10

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

void    enter_room(vector<Room>& r,Player& n,int full)
{
    int room_no = NONE;

    for(int i=0;i<r.size();i++)
    {
        if( r[i].size()==full ||
            !IN_RANGE(r[i].front().second-DIFF,n.second,r[i].front().second+DIFF) )
        {
            continue;
        }

        room_no = i;
        break;
    }

    if( room_no == NONE )
    {
        Room    k;

        k.push_back(n);
        r.push_back(k);
    }
    else
    {
        r[room_no].push_back(n);
    }
}

void    print_room(vector<Player>& r,int full)
{
    if( r.size() == full )
    {
        cout<<"Started!\n";
    }
    else
    {
        cout<<"Waiting!\n";
    }

    sort(r.begin(),r.end());

    for(int i=0;i<r.size();i++)
    {
        cout<<r[i].second<<' '<<r[i].first<<'\n';
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int             p,m;
    vector<Room>    game;

    cin>>p>>m;

    for(int i=1;i<=p;i++)
    {
        Player  n;

        cin>>n.second>>n.first;
        enter_room(game,n,m);
    }

    for(int i=0;i<game.size();i++)
    {
        print_room(game[i],m);
    }

    return  0;
}