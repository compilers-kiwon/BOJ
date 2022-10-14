#include    <iostream>
#include    <queue>
#include    <set>

using namespace std;

typedef long long int       int64;
typedef pair<int64,int64>   State;

int             N,K,cnt;
set<int64>      built;
queue<State>    q;

void    input(void)
{
    cin>>N>>K;

    for(int i=1;i<=N;i++)
    {
        State   s;
        int64&  pos = s.first;
        int64&  dist = s.second;

        cin>>pos;
        dist = 0;

        q.push(s);
        built.insert(pos);
    }
}

int64   bfs(void)
{
    int64   ret = 0;

    for(;;q.pop())
    {
        State   current,adj; 
        int64   left,right;

        current = q.front();

        int64&  pos = current.first;
        int64&  dist = current.second;

        left = pos-1;
        right = pos+1;

        if( built.find(left) == built.end() )
        {
            adj = {left,dist+1};
            q.push(adj);built.insert(left);

            cnt++;
            ret += dist+1;
        }

        if( cnt == K )
        {
            break;
        }

        if( built.find(right) == built.end() )
        {
            adj = {right,dist+1};
            q.push(adj);built.insert(right);

            cnt++;
            ret += dist+1;
        }

        if( cnt == K )
        {
            break;
        }
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<bfs()<<'\n';

    return  0;
}