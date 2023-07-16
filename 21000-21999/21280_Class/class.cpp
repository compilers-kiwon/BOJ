#include    <iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,missed,empty,prev_week;

    cin>>N>>prev_week;
    missed = empty = 0;

    for(int i=2;i<=N;i++)
    {
        int cur_week;

        cin>>cur_week;

        missed += max(0,cur_week-prev_week);
        empty += max(0,prev_week-cur_week);

        prev_week = cur_week;
    }

    cout<<empty<<' '<<missed<<'\n';
    return  0;
}