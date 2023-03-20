#include    <iostream>

using namespace std;

#define MAX_SIZE    200000

#define IN  1
#define OUT 0

static int  state[MAX_SIZE+1];

int update_state(int p,int s)
{
    int ret = (state[p]==s)?1:0;

    state[p] = s;

    return  ret;
}

int get_num_of_people_in(void)
{
    int ret = 0;

    for(int i=1;i<=MAX_SIZE;i++)
    {
        ret += state[i];
    }

    return  ret;
}

int simulate(int num_of_records)
{
    int missed = 0;

    for(int i=1;i<=num_of_records;i++)
    {
        int a,b;

        cin>>a>>b;
        missed += update_state(a,b);
    }

    return  missed+get_num_of_people_in();
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;

    cin>>N;
    cout<<simulate(N)<<'\n';

    return  0;
}