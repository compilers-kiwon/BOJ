#include    <iostream>
#include    <queue>

using namespace std;

#define MAX_SIZE    1500

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))
#define check_range(s)      \
        (IN_RANGE(1,(s).A,MAX_SIZE)&&IN_RANGE(1,(s).B,MAX_SIZE)&&IN_RANGE(1,(s).C,MAX_SIZE))

typedef struct{int A,B,C;} State;

bool    visited[MAX_SIZE+1][MAX_SIZE+1];

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    State           current,adj;
    queue<State>    q;

    cin>>current.A>>current.B>>current.C;
    
    q.push(current);
    visited[current.A][current.B] = true;

    for(;!q.empty();q.pop())
    {
        current = q.front();

        if( current.A==current.B && current.B==current.C )
        {
            cout<<"1\n";
            return  0;
        }

        if( current.A != current.B )
        {
            if( current.A < current.B )
            {
                adj.A = current.A+current.A;
                adj.B = current.B-current.A;
                adj.C = current.C;
            }
            else
            {
                adj.A = current.A-current.B;
                adj.B = current.B+current.B;
                adj.C = current.C;
            }

            if( check_range(adj) && visited[adj.A][adj.B]==false )
            {
                q.push(adj);
                visited[adj.A][adj.B] = true;
            }
        }

        if( current.B != current.C )
        {
            if( current.B < current.C )
            {
                adj.A = current.A;
                adj.B = current.B+current.B;
                adj.C = current.C-current.B;
            }
            else
            {
                adj.A = current.A;
                adj.B = current.B-current.C;
                adj.C = current.C+current.C;
            }

            if( check_range(adj) && visited[adj.A][adj.B]==false )
            {
                q.push(adj);
                visited[adj.A][adj.B] = true;
            }
        }

        if( current.C != current.A )
        {
            if( current.C < current.A )
            {
                adj.A = current.A-current.C;
                adj.B = current.B;
                adj.C = current.C+current.C;
            }
            else
            {
                adj.A = current.A+current.A;
                adj.B = current.B;
                adj.C = current.C-current.A;
            }

            if( check_range(adj) && visited[adj.A][adj.B]==false )
            {
                q.push(adj);
                visited[adj.A][adj.B] = true;
            }
        }
    }

    cout<<"0\n";
    return  0;
}