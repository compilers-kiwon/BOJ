#include    <iostream>
#include    <vector>

using namespace std;

int input(vector<int>& time_table)
{
    int T,D,M;

    cin>>T>>D>>M;

    for(int i=1;i<=M;i++)
    {
        int y;

        cin>>y;
        time_table.push_back(y);
    }

    time_table.push_back(D);
    return  T;
}

int simulate(int time_to_rest,
        const vector<int>& time_table)
{
    int prev_time = 0;

    for(int i=0;i<time_table.size();i++)
    {
        if( time_to_rest <= 
                time_table[i]-prev_time )
        {
            return  true;
        }

        prev_time = time_table[i];
    }

    return  false;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int time_to_rest;
    vector<int> time_table;
    
    time_to_rest = input(time_table);
    cout<<(simulate(time_to_rest,time_table)?'Y':'N')<<'\n';

    return  0;
}