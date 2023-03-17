#include    <iostream>
#include    <string>
#include    <vector>
#include    <map>

using namespace std;

#define MAX_SIZE    7

static int  N;
static map<string,int>  produced;
static map<int,vector<string>> table;

int input(void)
{
    cin>>N;

    for(int i=1;i<=N;i++)
    {
        string  name;
        int     amount;

        cin>>name>>amount;
        produced[name] += amount;
    }

    return  0;
}

int build_table(void)
{
    int min_amount = 0x7FFFFFFF;
    map<string,int>::iterator   it;

    for(it=produced.begin();it!=produced.end();it++)
    {
        table[it->second].push_back(it->first);
        min_amount = min(min_amount,it->second);
    }

    return  ((produced.size()!=MAX_SIZE)?0:min_amount);
}

string find_second_smallest(int min_amount)
{
    map<int,vector<string>>::iterator it =
                table.lower_bound(min_amount+1);
    
    if( it==table.end() || it->second.size()!=1 )
    {
        return  "Tie";
    }

    return  it->second.front();
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int M;

    input();
    M = build_table();
    cout<<find_second_smallest(M)<<'\n';

    return  0;
}