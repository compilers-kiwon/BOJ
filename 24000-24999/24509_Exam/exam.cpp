#include    <iostream>
#include    <queue>

using namespace std;

#define MAX_SIZE    (200000+1)
#define MAX_SUBJECT 4

typedef pair<int,int>   Score;

static bool prized[MAX_SIZE];
static priority_queue<Score> pq[MAX_SUBJECT+1];

int input(void)
{
    int N;

    cin>>N;

    for(int i=1;i<=N;i++)
    {
        int X;

        cin>>X;

        for(int j=1;j<=MAX_SUBJECT;j++)
        {
            int s;

            cin>>s;
            pq[j].push({s,-X});
        }
    }

    return  0;
}

int get_winner(int sub_idx)
{
    int ret;

    for(;!pq[sub_idx].empty();pq[sub_idx].pop())
    {
        ret = -pq[sub_idx].top().second;

        if( prized[ret] == false )
        {
            prized[ret] = true;
            break; 
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();

    for(int i=1;i<=MAX_SUBJECT;i++)
    {
        cout<<get_winner(i)<<((i==MAX_SUBJECT)?'\n':' ');
    }

    return  0;
}