#include    <iostream>
#include    <string>

using namespace std;

#define MAX_SIZE    (1000+1)
#define START       1
#define NONE        -1

typedef pair<int,int>   Port;

int     N,M,K,visited_time[MAX_SIZE];
Port    p[MAX_SIZE];
string  seq;

#define move(dir,port)  (((dir)=='L')?p[(port)].first:p[(port)].second)

void    input(void)
{
    cin>>N>>M>>K;

    for(int i=1;i<=N;i++)
    {
        cin>>p[i].first>>p[i].second;
    }

    for(int i=1;i<=M;i++)
    {
        char    c;

        cin>>c;
        seq.push_back(c);
    }
}

int     simulate(int s)
{
    int ret = s;

    for(int i=0;i<M;i++)
    {
        ret = move(seq[i],ret);
    }

    return  ret;
}

int     repaet_seq(int& head)
{
    int ret,current;

    fill(&visited_time[START],&visited_time[N+1],NONE);
    current=START;visited_time[current]=0;

    for(int r=1;;r++)
    {
        current = simulate(current);
        
        if( visited_time[current] != NONE )
        {
            head = visited_time[current];
            ret = r-head;
            break;
        }

        visited_time[current] = r;
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int repeated,not_repeated,pos;

    input();
    repeated = repaet_seq(not_repeated);

    pos = START;

    for(int i=1;i<=not_repeated+(K-not_repeated)%repeated;i++)
    {
        pos = simulate(pos);
    }

    cout<<pos<<'\n';

    return  0;
}