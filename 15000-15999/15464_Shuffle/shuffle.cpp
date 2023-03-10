#include    <iostream>
#include    <string>
#include    <map>

using namespace std;

#define MAX_SIZE    (100+1)

static int  N;
static map<int,string>  id_table;
static map<int,int> shuffle_table;
static string initial_state[MAX_SIZE];

#define reverse_for_three_times(idx) \
    (shuffle_table[shuffle_table[shuffle_table[(idx)]]])

int input(void)
{
    cin>>N;

    for(int i=1;i<=N;i++)
    {
        int a;

        cin>>a;
        shuffle_table[a] = i;
    }

    for(int i=1;i<=N;i++)
    {
        string  str;

        cin>>str;
        id_table[i] = str;
    }

    return  0;
}

int simulate(void)
{
    for(int i=1;i<=N;i++)
    {
        int init_idx = reverse_for_three_times(i);
        
        initial_state[init_idx] = id_table[i];
    }

    return  0;
}

int print(void)
{
    for(int i=1;i<=N;i++)
    {
        cout<<initial_state[i]<<'\n';
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    simulate();
    print();

    return  0;
}