#include    <iostream>
#include    <string>
#include    <map>

using namespace std;

#define NORTH   0
#define EAST    1
#define SOUTH   2
#define WEST    3
#define MAX_DIR 4

const static struct {
    int dx,dy;
} adj[MAX_DIR] = {{0,1},{1,0},{0,-1},{-1,0}};

#define TURN_LEFT(d)    (((d)-1+MAX_DIR)%MAX_DIR)
#define TURN_RIGHT(d)   (((d)+1)%MAX_DIR)

typedef pair<int,int>   Pos;

int simulate(int x,int y,const string& move)
{
    int d,cnt;
    map<Pos,int> visited;

    cnt = 0;
    d = NORTH;
    visited[{x,y}] = 1;

    for (int i=0;i<move.length();i++) {
        switch (move[i]) {
            case 'L':d=TURN_LEFT(d);break;
            case 'R':d=TURN_RIGHT(d);break;
            case 'F':
                x += adj[d].dx;
                y += adj[d].dy;
                if (++visited[{x,y}] == 2) cnt++;
                break;
            default:/*do nothing*/;break;
        }
    }

    cout<<x<<' '<<y<<' '<<cnt<<'\n';
    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for (int t=1;t<=T;t++) {
        int     x,y;
        string  str;

        cin>>x>>y>>str;
        cout<<"Case #"<<t<<": ";
        simulate(x,y,str);
    }

    return  0;
}