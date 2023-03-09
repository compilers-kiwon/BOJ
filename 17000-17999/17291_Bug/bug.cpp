#include    <iostream>
#include    <queue>

using namespace std;

// first:birth_year,second:num_of_divisions
typedef pair<int,int>   Bug;

static int  N;
static queue<Bug>   q;

#define ODD     3
#define EVEN    4

#define FIRST_BUG   {1,ODD}

#define is_even(n)  ((n)%2==0)
#define is_dead(b)  ((b).second==0)

#define divide(b,y) \
    {(b).second--;q.push({(y),is_even((y))?EVEN:ODD});}

int simulate(void)
{
    q.push({1,ODD});

    for(int i=2;i<=N&&!q.empty();i++)
    {
        for(int j=1,size=q.size();j<=size;j++,q.pop())
        {
            Bug current = q.front();
            
            divide(current,i);

            if( !is_dead(current) )
            {
                q.push(current);
            }
        }
    }

    return  q.size();
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N;
    cout<<simulate()<<'\n';

    return  0;
}