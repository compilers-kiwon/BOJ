#include    <iostream>
#include    <vector>
#include    <queue>

using namespace std;

#define MAX_SIZE    (100+1)
#define NONE        0

static int  C,V,state[MAX_SIZE][MAX_SIZE];

int first_round(priority_queue<pair<int,int>>& pq)
{
    int ret = NONE;
    int cnt[MAX_SIZE] = {0,};

    for(int v=1;v<=V;v++)
    {
        cnt[state[v][1]]++;
    }

    for(int c=1;c<=C;c++)
    {
        pq.push({cnt[c],c});
    }

    if( pq.top().first*2 > V )
    {
        ret = pq.top().second;
    }

    return  ret;
}

int input(void)
{
    cin>>C>>V;

    for(int v=1;v<=V;v++)
    {
        for(int c=1;c<=C;c++)
        {
            cin>>state[v][c];
        }
    }

    return  0;
}

int get_final_candidates(priority_queue<pair<int,int>>& pq,vector<int>& c)
{
    c.push_back(pq.top().second);
    pq.pop();
    c.push_back(pq.top().second);

    return  0;
}

int second_round(vector<int>& candidate)
{
    int cnt[MAX_SIZE] = {0,};

    for(int v=1;v<=V;v++)
    {
        for(int c=1;c<=C;c++)
        {
            if( state[v][c]==candidate.front()
                    || state[v][c]==candidate.back() )
            {
                cnt[state[v][c]]++;
                break;
            }
        }
    }

    return  (cnt[candidate.front()]>cnt[candidate.back()]
                        ?candidate.front():candidate.back());
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for(int t=1;t<=T;t++)
    {
        int winner,round;
        priority_queue<pair<int,int>>   pq;
        
        input();
        round = 1;

        if( (winner=first_round(pq)) == NONE )
        {
            vector<int> final_candidates;

            round++;
            get_final_candidates(pq,final_candidates);
            winner = second_round(final_candidates);
        }

        cout<<winner<<' '<<round<<'\n';
    }

    return  0;
}