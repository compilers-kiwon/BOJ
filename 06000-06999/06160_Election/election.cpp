#include    <iostream>
#include    <queue>

using namespace std;

typedef pair<pair<int,int>,int> Vote;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,K,winner,max_second_vote;
    priority_queue<Vote>    cows;

    cin>>N>>K;
    max_second_vote = 0;

    for(int i=1;i<=N;i++)
    {
        int A,B;

        cin>>A>>B;
        cows.push({{A,B},i});
    }

    for(int i=1;i<=K;i++,cows.pop())
    {
        if( cows.top().first.second > max_second_vote )
        {
            winner = cows.top().second;
            max_second_vote = cows.top().first.second;
        }
    }

    cout<<winner<<'\n';
    return  0;
}