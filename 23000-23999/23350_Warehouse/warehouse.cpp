#include    <iostream>
#include    <queue>
#include    <stack>

using namespace std;

#define MAX_PRIORITY    100

typedef pair<int,int>   Container;

static int  N,M;
static int  cnt_per_priority[MAX_PRIORITY+1];

static queue<Container> rail;

int input(void)
{
    cin>>N>>M;

    for(int i=1;i<=N;i++)
    {
        int P,W;

        cin>>P>>W;
        
        rail.push({P,W});
        cnt_per_priority[P]++;
    }

    return  0;
}

int simulate(void)
{
    int ret = 0;
    stack<Container> st,tmp;

    for(int cur_p=M;cur_p>=1;cur_p--)
    {
        for(;cnt_per_priority[cur_p]!=0;)
        {
            int p = rail.front().first;
            int w = rail.front().second;

            rail.pop();
            ret += w;

            if( cur_p != p )
            {
                rail.push({p,w});
                continue;
            }

            // Move <same priority,lighter weight> to temporary
            for(;!st.empty()&&st.top().first==p
                        &&st.top().second<w;st.pop())
            {
                ret += st.top().second;
                tmp.push(st.top());
            }

            // Move current container to load place
            st.push({p,w});

            // Move containers at temporary to load place
            for(;!tmp.empty();tmp.pop())
            {
                ret += tmp.top().second;
                st.push(tmp.top());
            }

            cnt_per_priority[cur_p]--;
        }
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<simulate()<<'\n';

    return  0;
}