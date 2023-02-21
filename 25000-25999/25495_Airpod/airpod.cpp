#include    <iostream>
#include    <vector>

using namespace std;

#define MAX_CONSUMPTION 100
#define init(a,b,c)     ((a)=(b)=(c)=0)

int input(vector<int>& v)
{
    int N;

    cin>>N;

    for(int i=1;i<=N;i++)
    {
        int A;

        cin>>A;
        v.push_back(A);
    }

    return  0;
}

int simulate(const vector<int>& order)
{
    int current,connected,prev_consumption;

    init(connected,current,prev_consumption);

    for(int i=0;i<order.size();i++)
    {
        current += (connected==order[i])?
            (prev_consumption*=2):(prev_consumption=2);

        if( current >= MAX_CONSUMPTION )
        {
            init(connected,current,prev_consumption);
        }
        else
        {
            connected = order[i];
        }
    }

    return  current;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    vector<int> A;
    
    input(A);
    cout<<simulate(A)<<'\n';

    return  0;
}