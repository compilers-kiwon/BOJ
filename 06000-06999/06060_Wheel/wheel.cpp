#include    <iostream>

using namespace std;

#define MAX_SIZE    (1000+1)

typedef pair<int,int>   Wheel;

#define adj_wheel   first
#define rotation    second

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     N;
    Wheel   state[MAX_SIZE];

    cin>>N;

    for(int i=1;i<N;i++)
    {
        int from,to,d;

        cin>>from>>to>>d;

        state[from].adj_wheel = to;
        state[from].rotation = (d==0)?1:-1;
    }

    int cur_dir = 1;

    for(int w=1;w!=N;w=state[w].adj_wheel)
    {
        cur_dir *= state[w].rotation;
    }

    cout<<(cur_dir==1?0:1)<<'\n';
    return  0;
}