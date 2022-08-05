#include    <iostream>

using namespace std;

#define MONDAY  1

int get_num_of_mondays(int days_of_year,int days_of_week,int start)
{
    int ignored = ((start==1)?0:days_of_week-start+1);

    return  (days_of_year-ignored)/days_of_week
                +((days_of_year-ignored)%days_of_week?1:0);
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int Z;

    cin>>Z;

    for(int z=1;z<=Z;z++)
    {
        int N,M,L;

        cin>>N>>M>>L;
        cout<<get_num_of_mondays(N,M,L)<<'\n';
    }

    return  0;
}