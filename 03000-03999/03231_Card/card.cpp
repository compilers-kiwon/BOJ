#include    <iostream>
#include    <map>

using namespace std;

int input(map<int,int>& pos)
{
    int N;

    cin>>N;

    for(int i=1;i<=N;i++)
    {
        int c;

        cin>>c;
        pos[c] = i;
    }

    return  N;
}

int simulate(int num_of_cards,map<int,int>& pos)
{
    int ret = 0;
    
    for(int current_num=1,prev_pos=0;
            current_num<=num_of_cards;current_num++)
    {
        int current_pos = pos[current_num];

        ret+= (current_pos<prev_pos)?1:0;
        prev_pos = current_pos;
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    map<int,int> pos;

    N = input(pos);
    cout<<simulate(N,pos);

    return  0;
}