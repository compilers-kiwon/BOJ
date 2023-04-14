#include    <iostream>
#include    <string>
#include    <vector>

using namespace std;

#define LEFT    0
#define UP      1
#define RIGHT   2
#define DOWN    3
#define MAX_DIR 4

const struct{int dx,dy;}
    adj[MAX_DIR]= {{-1,0},{0,1},{1,0},{0,-1}};

#define TURN_RIGHT(d)   (((d)+1)%MAX_DIR)
#define TURN_LEFT(d)    (((d)+3)%MAX_DIR)

typedef pair<int,string>    State;

int input(vector<State>& s)
{
    int N,T;

    cin>>N>>T;

    for(int i=1;i<=N;i++)
    {
        State   t;

        cin>>t.first>>t.second;
        s.push_back(t);
    }

    return  T;
}

int simulate(int& x,int& y,int total_time,
                    const vector<State>& record)
{
    int d = RIGHT;
    int time = 0;

    for(int i=0;i<record.size();i++)
    {
        int time_to_walk = record[i].first-time;

        x += adj[d].dx*time_to_walk;
        y += adj[d].dy*time_to_walk;

        d = (record[i].second=="left")?TURN_LEFT(d):TURN_RIGHT(d);
        time = record[i].first;
    }

    x += adj[d].dx*(total_time-time);
    y += adj[d].dy*(total_time-time);

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T,x,y;
    vector<State>   r;

    T = input(r);
    x = y = 0;

    simulate(x,y,T,r);
    cout<<x<<' '<<y<<'\n';

    return  0;
}