#include    <iostream>
#include    <queue>

using namespace std;

#define MAX_SIZE    (1000000+1)
#define NONE        0

int A,K,visited[MAX_SIZE];

void    check_number(int n,queue<int>& q,int current_step)
{
    if( n<=K && visited[n]==NONE )
    {
        q.push(n);
        visited[n] = current_step+1;
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    queue<int>  q;

    cin>>A>>K;

    for(q.push(A),visited[A]=0;!q.empty();q.pop())
    {
        int current = q.front();

        if( current == K )
        {
            break;
        }

        check_number(current+1,q,visited[current]);
        check_number(current*2,q,visited[current]);
    }

    cout<<visited[K]<<'\n';
    
    return  0;
}