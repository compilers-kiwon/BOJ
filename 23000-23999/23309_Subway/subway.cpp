#include    <iostream>
#include    <vector>
#include    <string>

using namespace std;

#define MAX_SIZE    (1000000+1)

#define get_prev_idx(current,size)  (((current)+(size)-1)%(size))
#define get_next_idx(current,size)  (((current)+1)%(size))

static pair<int,int>    state[MAX_SIZE];

#define get_prev_station(current)   (state[(current)].first)
#define get_next_station(current)   (state[(current)].second)

#define set_prev_station(current,prev)  (state[(current)].first=(prev))
#define set_next_station(current,next)  (state[(current)].second=(next))

int read_current_line(int size)
{
    vector<int> st;

    for(int i=0;i<size;i++)
    {
        int n;

        cin>>n;
        st.push_back(n);
    }

    for(int i=0;i<size;i++)
    {
        int current_station = st[i];
        int prev_station = st[get_prev_idx(i,size)];
        int next_station = st[get_next_idx(i,size)];
        
        set_prev_station(current_station,prev_station);
        set_next_station(current_station,next_station);
    }

    return  0;
}

int insert(int head,int mid,int tail)
{
    set_prev_station(mid,head);
    set_next_station(head,mid);

    set_next_station(mid,tail);
    set_prev_station(tail,mid);

    return  0;
}

int remove(int mid)
{
    int head = get_prev_station(mid);
    int tail = get_next_station(mid);

    set_next_station(head,tail);
    set_prev_station(tail,head);

    return  0;
}

int do_bn(void)
{
    int i,j,ret;

    cin>>i>>j;
    ret = get_next_station(i);

    insert(i,j,ret);
    return  ret;
}

int do_bp(void)
{
    int i,j,ret;

    cin>>i>>j;
    ret = get_prev_station(i);

    insert(ret,j,i);
    return  ret;
}

int do_cn(void)
{
    int i,ret;

    cin>>i;
    ret = get_next_station(i);

    remove(ret);
    return  ret;
}

int do_cp(void)
{
    int i,ret;

    cin>>i;
    ret = get_prev_station(i);

    remove(ret);
    return  ret;
}

int simulate(int num_of_instructions)
{
    for(int i=1;i<=num_of_instructions;i++)
    {
        int     r;
        string  inst;

        cin>>inst;

        if( inst == "BN" )
        {
            r = do_bn();
        }
        else if( inst == "BP" )
        {
            r = do_bp();
        }
        else if( inst == "CN" )
        {
            r = do_cn();
        }
        else    // inst == "CP"
        {
            r = do_cp();
        }

        cout<<r<<'\n';
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,M;

    cin>>N>>M;

    read_current_line(N);
    simulate(M);

    return  0;
}