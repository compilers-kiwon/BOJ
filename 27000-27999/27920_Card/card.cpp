#include    <iostream>
#include    <vector>

using namespace std;

#define MAX_SIZE    (200000+1)

static int  N,card[MAX_SIZE];

#define TRUE    1
#define FALSE   0

int place_card(void)
{
    int pos;

    pos = 1;

    for(int i=N-1,sign=1;i>=1;i--,sign*=-1)
    {
        card[pos] = i;
        pos += sign*i;
    }

    card[pos] = N;
    return  0;
}

int simulate(vector<int>& opened)
{
    int cnt,pos,sign;

    for(cnt=0,pos=sign=1;cnt!=N;cnt++,sign*=-1)
    {
        if( card[pos] < 0 )
        {
            break;
        }

        opened.push_back(pos);
        
        int prev_pos = pos;

        pos += card[pos]*sign;
        card[prev_pos] *= -1;
    }

    return  (cnt==N)?TRUE:FALSE;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<int> opened;

    cin>>N;
    place_card();

    if( simulate(opened) != TRUE )
    {
        cout<<"NO\n";
        return  0;
    }

    cout<<"YES\n";

    for(int i=1;i<=N;i++)
    {
        cout<<-card[i]<<((i==N)?'\n':' ');
    }

    for(int i=0;i<N;i++)
    {
        cout<<opened[i]<<((i==N-1)?'\n':' ');
    }

    return  0;
}