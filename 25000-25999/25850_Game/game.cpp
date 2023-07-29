#include    <iostream>
#include    <queue>
#include    <string>

using namespace std;

typedef pair<int,char>  State;

int read_cards(priority_queue<State>& pq,char p)
{
    int c;

    cin>>c;
    
    for(int i=1;i<=c;i++)
    {
        int n;

        cin>>n;
        pq.push({-n,p});
    }

    return  0;
}

int input(priority_queue<State>& pq)
{
    int     N;
    char    player;

    cin>>N;
    player = 'A';

    for(int i=1;i<=N;i++,player++)
    {
        read_cards(pq,player);
    }

    return  0;
}

int simulate(priority_queue<State>& pq)
{
    string  s;

    for(;!pq.empty();pq.pop())
    {
        s.push_back(pq.top().second);
    }

    cout<<s<<'\n';
    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    priority_queue<State>   pq;

    input(pq);
    simulate(pq);

    return  0;
}