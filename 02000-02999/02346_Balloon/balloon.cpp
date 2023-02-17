#include    <iostream>
#include    <cmath>

using namespace std;

#define MAX_SIZE    (1000+1)

typedef pair<int,int>   Pos;

static int  N,step[MAX_SIZE];
static Pos  balloon[MAX_SIZE];

int input(void)
{
    cin>>N;
    for(int i=1;i<=N;i++) cin>>step[i];

    return  0;
}

int init(void)
{
    for(int i=1;i<=N;i++)
    {
        balloon[i].first = i-1;
        balloon[i].second = i+1;
    }

    balloon[1].first = N;
    balloon[N].second = 1;

    return  0;
}

int move_left(int pos,int s)
{
    int ret = pos;

    for(int i=1;i<=s;i++)
    {
        ret = balloon[ret].first;
    }

    return  ret;
}

int move_right(int pos,int s)
{
    int ret = pos;

    for(int i=1;i<=s;i++)
    {
        ret = balloon[ret].second;
    }

    return  ret;
}

int move(int pos,int s)
{
    balloon[balloon[pos].first].second = balloon[pos].second;
    balloon[balloon[pos].second].first = balloon[pos].first;

    return  ((s>0)?move_right(pos,s):move_left(pos,-s));
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int current = 1;

    input();init();
    
    for(int i=1;i<=N;i++)
    {
        cout<<current<<' ';
        current = move(current,step[current]);
    }

    return  0;
}