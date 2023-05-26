#include    <iostream>
#include    <cmath>

using namespace std;

#define MAX_SIZE    (1000+1)

typedef pair<int,int>   Pos;

#define get_distance(x1,y1,x2,y2) \
        (abs((x1)-(x2))+abs((y1)-(y2)))

#define get_energy_to_reach(P,p1,p2) \
        (max(0,(P)-get_distance((p1).first,(p1).second,(p2).first,(p2).second)))

static int  N,E[MAX_SIZE];
static int  wifi_energy[MAX_SIZE],interference[MAX_SIZE];
static Pos  p[MAX_SIZE];

int input(void)
{
    cin>>N;

    for(int i=0;i<=N;i++)
    {
        cin>>p[i].first>>p[i].second>>E[i];
    }

    return  0;
}

int get_interference(void)
{
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            Pos&    p1 = p[i];
            Pos&    p2 = p[j];

            interference[j] += get_energy_to_reach(E[i],p1,p2);
        }
    }

    return  0;
}

int get_max_speed(void)
{
    int ret = 0;

    for(int i=1;i<=N;i++)
    {
        ret = max(ret,
            get_energy_to_reach(E[0],p[0],p[i])-interference[i]);
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    get_interference();

    int max_speed = get_max_speed();

    if( max_speed == 0 )
    {
        cout<<"IMPOSSIBLE\n";
    }
    else
    {
        cout<<max_speed<<'\n';
    }

    return  0;
}