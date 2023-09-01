#include    <iostream>

using namespace std;

#define MAX_SIZE    (250)

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     N,e,chairs[MAX_SIZE];
    bool    moved[MAX_SIZE] = {false,};

    cin>>N;
    for (int i=0;i<N;i++) chairs[i]=i;

    for (int cur_pos=0,cur_cow=0;;)
    {
        int next_pos = (cur_pos+(cur_cow+1))%N;
        int next_cow = chairs[next_pos];

        if (next_cow==-1 ||
                moved[next_cow]==true) {
            e = cur_cow+1;
            break;
        }

        chairs[cur_pos] = -1;
        cur_cow = next_cow;
        cur_pos = next_pos;
    }

    cout<<e<<'\n';
    return  0;
}