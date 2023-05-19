#include    <iostream>
#include    <string>
#include    <vector>
#include    <algorithm>

using namespace std;

#define YES 1
#define NO  0

#define NUM_OF_BLOCKS   4

static string   blocks[NUM_OF_BLOCKS+1];

int init(vector<vector<int>>& order)
{
    vector<int> n;

    for(int i=1;i<=NUM_OF_BLOCKS;i++)
    {
        n.push_back(i);
    }

    do{
        order.push_back(n);
    }while(next_permutation(n.begin(),n.end()));

    return  0;
}

int simulate(const string& str,
        const vector<vector<int>>& order)
{
    for(int i=0;i<order.size();i++)
    {
        bool    found = true;

        for(int j=0;j<str.length();j++)
        {
            string& current_block = blocks[order[i][j]];

            if( current_block.find(str[j]) == string::npos )
            {
                found = false;
                break;
            }
        }

        if( found == true )
        {
            return  YES;
        }
    }

    return  NO;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    vector<vector<int>> order;
    
    cin>>N;
    init(order);

    for(int i=1;i<=NUM_OF_BLOCKS;i++)
    {
        cin>>blocks[i];
    }

    for(int i=1;i<=N;i++)
    {
        string  w;

        cin>>w;
        cout<<(simulate(w,order)==YES?"YES":"NO")<<'\n';
    }

    return  0;
}