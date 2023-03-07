#include    <iostream>
#include    <vector>
#include    <set>

using namespace std;

#define MAX_SIZE    (1000+1)

static int  N,B[MAX_SIZE];

typedef pair<int,int>   State;  // first:numbere,second:count

int get_max_continuous_number(int excluded)
{
    int             ret;
    vector<State>   table;

    ret = 0;
    table.push_back({0,0});

    for(int i=1;i<=N;i++)
    {
        if( B[i] == excluded )
        {
            continue;
        }

        if( table.back().first == B[i] )
        {
            table.back().second++;
        }
        else
        {
            table.push_back({B[i],1});
        }

        ret = max(ret,table.back().second);
    }

    return  ret;
}

int input(set<int>& numbers)
{
    cin>>N;

    for(int i=1;i<=N;i++)
    {
        cin>>B[i];
        numbers.insert(B[i]);
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int max_count = 0;
    set<int> numbers;
    set<int>::iterator it;

    input(numbers);

    for(it=numbers.begin();it!=numbers.end();it++)
    {
        max_count = max(max_count,
            get_max_continuous_number(*it));
    }

    cout<<max_count<<'\n';

    return  0;
}